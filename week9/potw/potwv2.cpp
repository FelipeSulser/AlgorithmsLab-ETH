#include <iostream>
#include <cstdlib>
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

void do_calc() {
    int n,m,l;
    cin>>n>>m>>l;
    //n is number of train stops
    //m is num of missions
    //l is max num of agents
    Graph G(n+2);
    int start = n;
    int end = n+1;
    EdgeCapacityMap capacitymap = get(edge_capacity, G);
    EdgeWeightMap weightmap = get(edge_weight, G);
    ReverseEdgeMap revedgemap = get(edge_reverse, G);
    ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
    EdgeAdder eaG(G, capacitymap, weightmap, revedgemap);
    int constant = 10000;
    int maxval= -1;
    vector<int> xval(m);
    vector<int> yval(m);
    vector<int> qval(m);
    for(int i = 0; i < m; i++){
        int x,y,q;
        cin>>x>>y>>q;
        xval[i] =x;
        yval[i] = y;
        qval[i] = q;
        maxval = std::max(maxval,q);
       
    }
    int sumadd = 0;
    eaG.addEdge(start,0,l,0);
    eaG.addEdge(n-1,end,l,0);
    for(int i = 0; i < m; i++){
        int diff = yval[i]-xval[i];
         eaG.addEdge(xval[i],yval[i],1,(diff)*maxval-qval[i]);
    }
    for(int i = 0; i < n-1; i++){
        sumadd+=maxval;
        eaG.addEdge(i,i+1,l,maxval);
    }
   
    

    successive_shortest_path_nonnegative_weights(G, start, end);
    int cost2 = find_flow_cost(G);
    int flow2 = 0;
    // Iterate over all edges leaving the source to sum up the flow values.
    OutEdgeIt e, eend;
    for(tie(e, eend) = out_edges(vertex(start,G), G); e != eend; ++e) {
        flow2 += capacitymap[*e] - rescapacitymap[*e];
       
       // cout<<"At edge " <<*e<<" has cap "<<capacitymap[*e]<<" res "<<rescapacitymap[*e]<<endl;
    }
  //  cout<<cost2<<" " <<flow2<<" " <<maxval<<endl;
    cout<<sumadd*l - cost2<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)do_calc();
    return 0;
}
