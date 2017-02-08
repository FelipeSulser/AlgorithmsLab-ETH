// ALGOLAB BGL Tutorial 3
// Code snippets demonstrating 
// - MinCostMaxFlow with negative edge costs using cycle_canceling
// - MinCostMaxFlow with negative edge costs using successive_shortest_path_nonnegative_weights

// Compile and run with one of the following:
// g++ -std=c++11 -O2 bgl_mincostmaxflow.cpp -o bgl_mincostmaxflow; ./bgl_mincostmaxflow
// g++ -std=c++11 -O2 -I path/to/boost_1_58_0 bgl_mincostmaxflow.cpp -o bgl_mincostmaxflow; ./bgl_mincostmaxflow

// Includes
// ========
// STL includes
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

void do_calc(){
    int N,S;
    cin>>N>>S;

    int MAXT = 100000;
    int delta = 100;
    MAXT = MAXT/30;
    Graph G(S*MAXT+2);
    EdgeCapacityMap capacitymap = get(edge_capacity, G);
    EdgeWeightMap weightmap = get(edge_weight, G);
    ReverseEdgeMap revedgemap = get(edge_reverse, G);
    ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
    EdgeAdder eaG(G, capacitymap, weightmap, revedgemap);
    int start = S*MAXT;
    int end = start+1;
    
    vector<int> initial_cars(S);
    for(int i = 0; i < S; i++){
        cin>>initial_cars[i];
        eaG.addEdge(start,i*MAXT +0,initial_cars[i],0);
    }

    for(int i = 0; i < S; i++){
        for(int j = 1; j< MAXT; j++){
            eaG.addEdge(i*MAXT+(j-1), i*MAXT+(j),INT_MAX,delta);
        }
    }



    for(int i = 0; i < N; i++){
        //si,ti,di,ai,pi
        int si,ti,di,ai,pi;
        cin>>si>>ti>>di>>ai>>pi;
        si--;
        ti--;
        //from s to t
        //at time di->ai
        int vart = ai-di;
        eaG.addEdge(si*MAXT+di,ti*MAXT+ai,1,vart*delta-pi);
    }

    for(int i = 0; i < S; i++){
        eaG.addEdge(i*MAXT+(MAXT-1),end,INT_MAX,0);
    }

   // Option 2: Min Cost Max Flow with successive_shortest_path_nonnegative_weights
    successive_shortest_path_nonnegative_weights(G, start, end);
    int cost2 = find_flow_cost(G);
    int flow2 = 0;
    // Iterate over all edges leaving the source to sum up the flow values.
    OutEdgeIt e, eend;
    for(tie(e, eend) = out_edges(vertex(start,G), G); e != eend; ++e) {
        flow2 += capacitymap[*e] - rescapacitymap[*e];
    }
    //cout<<flow2<<endl;
    cout<<(flow2*delta*MAXT-cost2)-flow2*delta<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)do_calc();
    return 0;
}
