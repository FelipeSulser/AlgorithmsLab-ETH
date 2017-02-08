

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
#include <algorithm>
#include <vector>
#include <queue>
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
typedef graph_traits<Graph>::out_edge_iterator          OutEdgeIt;
// Custom Edge Adder Class, that holds the references
// to the graph, capacity map, weight map and reverse edge map
// ===============================================================
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

void do_calc(){
	int n,m;
	cin>>n>>m; // n is num of figures
	//m is number of limbs between figures
	Graph G(n);
    EdgeCapacityMap capacitymap = get(edge_capacity, G);
    ReverseEdgeMap revedgemap = get(edge_reverse, G);
    ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
    EdgeAdder eaG(G, capacitymap, revedgemap);
	for(int i = 0; i < m; i++){
		int a,b,c;
		cin>>a>>b>>c;

		//figure a -> b
		//cost = c
		eaG.addEdge(a,b,c);
	}

	//now find the best source and sink to do a flow analysis
	int best_source = -1;
	int best_sink = -1;
	int best_sol = INT_MAX;
	for(int i = 1; i < n; i++){
		int max_flow = push_relabel_max_flow(G,0,i);
		if(max_flow < best_sol){
			best_sol = max_flow;
			best_source = 0;
			best_sink = i;
		}
		max_flow = push_relabel_max_flow(G,i,0);
		if(max_flow < best_sol){
			best_sol = max_flow;
			best_source = i;
			best_sink = 0;
		}
	}
	long flow = push_relabel_max_flow(G,best_source, best_sink);
	//BFS to find vertex set from the start
	vector<int> vis(n,false);
	std::queue<int> Q;
	vis[best_source] = true;
	Q.push(best_source);
	while(!Q.empty()){
		const int u = Q.front();
		Q.pop();
		OutEdgeIt ebeg, eend;
		for(tie(ebeg,eend) = out_edges(u,G); ebeg != eend; ++ebeg){
			const int v = target(*ebeg,G);
			if(rescapacitymap[*ebeg] == 0 || vis[v]) continue;
			vis[v] = true;
			Q.push(v);
		}
	}
	cout<<flow<<endl<<count(vis.begin(),vis.end(),true);
	for(int i = 0; i < n; i++){
		if(vis[i]) cout<<" "<<i;
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}