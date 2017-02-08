#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/cycle_canceling.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>
// Namespaces
using namespace boost;
using namespace std;

// BGL Graph definitions
// ===================== 
// Graph Type with nested interior edge properties for Cost Flow Algorithms
typedef adjacency_list_traits<vecS, vecS, directedS> Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
    property<edge_capacity_t, long,
        property<edge_residual_capacity_t, long,
            property<edge_reverse_t, Traits::edge_descriptor,
                property <edge_weight_t, long> > > > > Graph;
// Interior Property Maps
typedef property_map<Graph, edge_capacity_t>::type      EdgeCapacityMap;
typedef property_map<Graph, edge_weight_t >::type       EdgeWeightMap;
typedef property_map<Graph, edge_residual_capacity_t>::type ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type       ReverseEdgeMap;
typedef graph_traits<Graph>::vertex_descriptor          Vertex;
typedef graph_traits<Graph>::edge_descriptor            Edge;
typedef graph_traits<Graph>::out_edge_iterator  OutEdgeIt; // Iterator

// Custom Edge Adder Class, that holds the references
// to the graph, capacity map, weight map and reverse edge map
// ===============================================================
class EdgeAdder {
    Graph &G;
    EdgeCapacityMap &capacitymap;
    EdgeWeightMap &weightmap;
    ReverseEdgeMap  &revedgemap;

public:
    EdgeAdder(Graph & G, EdgeCapacityMap &capacitymap, EdgeWeightMap &weightmap, ReverseEdgeMap &revedgemap) 
        : G(G), capacitymap(capacitymap), weightmap(weightmap), revedgemap(revedgemap) {}

    void addEdge(int u, int v, long c, long w) {
        Edge e, reverseE;
        tie(e, tuples::ignore) = add_edge(u, v, G);
        tie(reverseE, tuples::ignore) = add_edge(v, u, G);
        capacitymap[e] = c;
        weightmap[e] = w;
        capacitymap[reverseE] = 0;
        weightmap[reverseE] = -w;
        revedgemap[e] = reverseE; 
        revedgemap[reverseE] = e; 
    }
};

struct Booking{
    int s,t,d,a,p;

};

void do_calc(){
    int N, S;
    cin>>N>>S;
    //N is number of booking requests
    //S is number of rental stations
     int MAXL = 100;
    int MAXT = 100000;
    int MAXP = 100;
    int INF = MAXL*S;
     // Create Graph and Maps
    vector<int> num_cars(S);
    for(int i = 0; i < S; i++){
        cin>>num_cars[i];
    }   

    vector<Booking> B;
    vector<set<int> > times(S);
    for(int s = 0; s < S; s++){
        times[s].insert(0);
        times[s].insert(MAXT);
    }

    vector<map<int,int> > M(S); //map for coord compression

    for(int i = 0; i < N; i++){
        int s,t,d,a,p;
        cin>>s>>t>>d>>a>>p;
        s--;
        t--;
        times[s].insert(d);
        times[t].insert(a);
        B.push_back({s,t,d,a,p});

    }


    vector<int> psum(S+1);

    for(int s = 0; s < S; s++){
        int i = 0;
        for(auto & t : times[s]){
            M[s][t] = i;
            i++;
        }
        psum[s+1] = psum[s]+M[s].size();
    }

    int T = psum.back();
    int v_source = T;
    int v_target = T+1;

    Graph G(T+2);
    EdgeCapacityMap capacitymap = get(edge_capacity, G);
    EdgeWeightMap weightmap = get(edge_weight, G);
    ReverseEdgeMap revedgemap = get(edge_reverse, G);
    ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
    EdgeAdder eaG(G, capacitymap, weightmap, revedgemap);


    for(int i = 0; i < S; i++){
        eaG.addEdge(v_source,psum[i],num_cars[i],0);
        eaG.addEdge(psum[i+1]-1,v_target,INF,0);
        int it = -1;
        int lastt = 0;
        for(auto & t: times[i]){
            if(it != -1){
                eaG.addEdge(psum[i]+it,psum[i]+it+1,INF,MAXP*(t-lastt));
            }
            it++;
            lastt = t;
        }
    }
    for(int i = 0; i < N; i++){
        eaG.addEdge(psum[B[i].s] + M[B[i].s][B[i].d],
            psum[B[i].t]+M[B[i].t][B[i].a],
            1,((B[i].a-B[i].d)*MAXP)-B[i].p);
    }
   

    successive_shortest_path_nonnegative_weights(G, v_source, v_target);
    int cost2 = find_flow_cost(G);
    int flow2 = 0;
    // Iterate over all edges leaving the source to sum up the flow values.
    OutEdgeIt e, eend;
    for(tie(e, eend) = out_edges(vertex(v_source,G), G); e != eend; ++e) {
        flow2 += capacitymap[*e] - rescapacitymap[*e];
    }
  cout<<MAXP*MAXT*flow2 - cost2<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)do_calc();
    return 0;
}