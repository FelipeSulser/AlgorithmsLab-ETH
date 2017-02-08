// ALGOLAB BGL Tutorial 1
// Code snippets demonstrating 
// - graph definitions
// - several algorithms (components, distance-based algorithms, maximum matching)
// - how to pass exterior property maps
// - use of iterators

// Compile and run with one of the following:
// g++ -std=c++11 -O2 bgl-code_snippets.cpp -o bgl-code_snippets; ./bgl-code_snippets
// g++ -std=c++11 -O2 -I path/to/boost_1_58_0 bgl-code_snippets.cpp -o bgl-code_snippets; ./bgl-code_snippets

// Includes
// ========
// STL includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
// Namespaces
using namespace std;
using namespace boost;


// BGL Graph definitions
// =====================
// Graph Type, OutEdgeList Type, VertexList Type, (un)directedS
typedef adjacency_list<vecS, vecS, undirectedS,		// Use vecS for the VertexList! Choosing setS for the OutEdgeList disallows parallel edges.
		no_property,				// interior properties of vertices	
		property<edge_weight_t, int> 		// interior properties of edges
		>					Graph;
typedef graph_traits<Graph>::edge_descriptor		Edge;		// Edge Descriptor: an object that represents a single edge.
typedef graph_traits<Graph>::vertex_descriptor		Vertex;		// Vertex Descriptor: with vecS vertex list, this is really just an int in the range [0, num_vertices(G)).	
typedef graph_traits<Graph>::edge_iterator		EdgeIt;		// to iterate over all edges
typedef graph_traits<Graph>::out_edge_iterator		OutEdgeIt;	// to iterate over all outgoing edges of a vertex
typedef property_map<Graph, edge_weight_t>::type	WeightMap;	// property map to access the interior property edge_weight_t


// Functions
// ========= 
void testcases() {
	int n,m;
	cin>>n>>m;
	int V = n;
	Graph G(V);	// creates an empty graph on n vertices
	WeightMap weightmap = get(edge_weight, G);
	for(int i = 0; i < m; i++){
		int u, v , w;
		cin>>u>>v>>w;
		Edge e;
		bool success;
		tie(e,success) = add_edge(u,v,G);
		weightmap[e] = w;
	}
	vector<Edge> mst;
	vector<Vertex> kruskalpredmap(n), rankmap(n);

	kruskal_minimum_spanning_tree(G,back_inserter(mst),rank_map(make_iterator_property_map(rankmap.begin(),get(vertex_index,G))).predecessor_map(make_iterator_property_map(kruskalpredmap.begin(),get(vertex_index,G))));
	long weightsum = 0;
	for(int i = 0; i < mst.size(); i++){
		Edge e = mst[i];
		weightsum += weightmap[e];
	}
	//nw dijkstra
	vector<Vertex> predmap(n);
	vector<int> distmap(n);
	Vertex start = 0;
	dijkstra_shortest_paths(G,start,
		predecessor_map(make_iterator_property_map(predmap.begin(),get(vertex_index,G))).distance_map(make_iterator_property_map(distmap.begin(),get(vertex_index,G))));
	long maxdist = 0;
	for(int i = 0; i < n; i++){
		if(distmap[i] < INT_MAX)
		{
			if(distmap[i] > maxdist){
				maxdist = distmap[i];
			}
		}
	}
	cout<<weightsum<<" " <<maxdist<<endl;
	return;
}

// Main function looping over the testcases
int main() {
	ios_base::sync_with_stdio(false); // if you use cin/cout. Do not mix cin/cout with scanf/printf calls!
	int T;	cin>>T;
	while(T--)	testcases();
	return 0;
}

