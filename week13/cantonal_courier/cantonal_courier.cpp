// ALGOLAB BGL Tutorial 2
// Flow example demonstrating
// - interior graph properties for flow algorithms
// - custom edge adder

// Compile and run with one of the following:
// g++ -std=c++11 -O2 flows.cpp -o flows ./flows
// g++ -std=c++11 -O2 -I path/to/boost_1_58_0 flows.cpp -o flows; ./flows

// Includes
// ========
// STL includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/edmonds_karp_max_flow.hpp>
// Namespaces
using namespace std;
using namespace boost;


// BGL Graph definitions
// =====================
// Graph Type with nested interior edge properties for Flow Algorithms
typedef adjacency_list_traits<vecS, vecS, directedS> Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
    property<edge_capacity_t, long,
        property<edge_residual_capacity_t, long,
            property<edge_reverse_t, Traits::edge_descriptor> > > > Graph;
// Interior Property Maps
typedef property_map<Graph, edge_capacity_t>::type      EdgeCapacityMap;
typedef property_map<Graph, edge_residual_capacity_t>::type ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type       ReverseEdgeMap;
typedef graph_traits<Graph>::vertex_descriptor          Vertex;
typedef graph_traits<Graph>::edge_descriptor            Edge;


// Custom Edge Adder Class, that holds the references
// to the graph, capacity map and reverse edge map
// ===================================================
class EdgeAdder {
    Graph &G;
    EdgeCapacityMap &capacitymap;
    ReverseEdgeMap  &revedgemap;

public:
    // to initialize the Object
    EdgeAdder(Graph & G, EdgeCapacityMap &capacitymap, ReverseEdgeMap &revedgemap):
        G(G), capacitymap(capacitymap), revedgemap(revedgemap){}

    // to use the Function (add an edge)
    void addEdge(int from, int to, long capacity) {
        Edge e, reverseE;
        bool success;
        tie(e, success) = add_edge(from, to, G);
        tie(reverseE, success) = add_edge(to, from, G);
        capacitymap[e] = capacity;
        capacitymap[reverseE] = 0;
        revedgemap[e] = reverseE;
        revedgemap[reverseE] = e;
    }
};

void do_calc() {
    int Z,J;
    cin>>Z>>J;

    Graph G(Z+J+2);
    EdgeCapacityMap capacitymap = get(edge_capacity, G);
    ReverseEdgeMap revedgemap = get(edge_reverse, G);
    ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
    EdgeAdder eaG(G, capacitymap, revedgemap);
    int start = Z+J;
    int end = start+1;
    int zone_offset = 0;
    int job_offset = Z;
    //Z is number of zones,
    //J is number of jobs
    vector<int> cost_zone(Z);
    for(int i = 0; i < Z; i++){
        int cost_val;
        cin>>cost_val;
        eaG.addEdge(zone_offset+i,end,cost_val);
    }
    int totalreward = 0;
    for(int i = 0; i < J; i++){
        int rew;
        cin>>rew;
        totalreward+= rew;
        eaG.addEdge(start,job_offset+i,rew);

    }
    for(int i = 0; i < J; i++){
        int ni;
        cin>>ni;
        for(int j = 0; j < ni; j++){
            int val;
            cin>>val;
            eaG.addEdge(job_offset+i,zone_offset+val,INT_MAX);
           // needi[j]--;
        }
    }
  
 
    // Option 1: Min Cost Max Flow with cycle_canceling
   long flow1 = push_relabel_max_flow(G, start, end);
   cout<<totalreward-flow1<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)do_calc();
    return 0;
}