#include <iostream>
#include <cstdlib>
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

void do_calc(){
    int n,s;
    cin>>n>>s;
    vector<int> cars(s);
    for(int i = 0; i < s; i++){
        cin>>cars[i];
    }
    int MAXL = 100;
    int MAXP = 100;
    int MAXT = 100000;
    int INF = MAXL*s;
   
    vector<pair<int,int> > edges(n);
    vector<pair<int,int> > times(n);

    vector<map<int,int> > translated_times(s);
    vector<int> profit(n);
    vector<set<int> > destinations(s);
    for(int i = 0; i < s; i++){
        destinations[i].insert(0);
        destinations[i].insert(MAXT);
    }
    for(int i = 0; i < n; i++){
        int si,ti,di,ai,pi;
        cin>>si>>ti>>di>>ai>>pi;
        si--;
        ti--;
        //s->t goes from s to t
        //dep time d
        //arrival a
        //p profit -> -cost
       edges[i] = make_pair(si,ti);
       times[i] = make_pair(di,ai);
       profit[i] = pi;
       destinations[si].insert(di);
       destinations[ti].insert(ai);
    }

    vector<int> psum(s+1);
    for(int si = 0; si < s; si++){
        int i = 0;
        for(auto & t: destinations[si]){
            translated_times[si][t] = i;
            i++;
        }
        psum[si+1] = psum[si]+translated_times[si].size();
    }
    int T = psum.back();
    int v_source = T;
    int v_target = T+1;
    //now i can build the graph

    Graph G(T+2);
    EdgeCapacityMap capacitymap = get(edge_capacity, G);
    EdgeWeightMap weightmap = get(edge_weight, G);
    ReverseEdgeMap revedgemap = get(edge_reverse, G);
    ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
    EdgeAdder eaG(G, capacitymap, weightmap, revedgemap);
    for(int i = 0; i < s; i++){
        eaG.addEdge(v_source,psum[i],cars[i],0);
        eaG.addEdge(psum[i+1]-1,v_target,INF,0);
        int it = -1;
        int lastt = 0;
        for(auto & t: destinations[i]){
            if(it != -1){
                eaG.addEdge(psum[i]+it,psum[i]+it+1,INF,MAXP*(t-lastt));
            }
            it++;
            lastt = t;
        }
    }

    for(int i = 0; i < n; i++){
        eaG.addEdge(psum[edges[i].first]+translated_times[edges[i].first][times[i].first],
            psum[edges[i].second]+translated_times[edges[i].second][times[i].second],
            1,((times[i].second-times[i].first)*MAXP)-profit[i]);
    }


    
     // Option 2: Min Cost Max Flow with successive_shortest_path_nonnegative_weights
    successive_shortest_path_nonnegative_weights(G, v_source, v_target);
    int cost2 = find_flow_cost(G);
    int flow2 = 0;
    // Iterate over all edges leaving the source to sum up the flow values.
    OutEdgeIt e, eend;
    for(tie(e, eend) = out_edges(vertex(v_source,G), G); e != eend; ++e) {
        flow2 += capacitymap[*e] - rescapacitymap[*e];
    }
    cout<<MAXP*MAXT*flow2-cost2<<endl;
        

}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)do_calc();
    return 0;
}