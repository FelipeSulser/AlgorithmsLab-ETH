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

void do_calc() {
    int N,M,S;
    cin>>N>>M>>S;
    Graph G(N+M+S+2);
    int start = N+M+S;
    int end = start+1;
    EdgeCapacityMap capacitymap = get(edge_capacity, G);
    EdgeWeightMap weightmap = get(edge_weight, G);
    ReverseEdgeMap revedgemap = get(edge_reverse, G);
    ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
    EdgeAdder eaG(G, capacitymap, weightmap, revedgemap);
    //N is interested buyers
    //M is number of sites
    //S is states in algoland
    vector<int> states(S);
    for(int i = 0; i < S; i++){
        cin>>states[i];
        eaG.addEdge(N+M+i,end,states[i],0);
    }

    vector<int> locations(M);
    for(int i = 0; i < M; i++){
        cin>>locations[i];
        eaG.addEdge(N+i,N+M+locations[i]-1,1,0);
    }
    int maxbid = 0;
    vector<vector<int> > vals(N,vector<int>(M,0));
    for(int i = 0; i < N; i++){
         eaG.addEdge(start,i,1,0); // can buy one
        for(int j = 0; j < M; j++){
            int val;
            cin>>val;
            vals[i][j] = val;
            maxbid = std::max(maxbid,val);
          //  eaG.addEdge(i,N+j,1,maxbid-val); // so that its positive
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            eaG.addEdge(i,N+j,1,maxbid-vals[i][j]);
        }
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

    cout<<flow2<<" " <<flow2*maxbid-cost2<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)do_calc();
    return 0;
}
