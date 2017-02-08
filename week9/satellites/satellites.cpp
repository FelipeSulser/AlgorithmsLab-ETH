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

void DFS(int u, Graph & G, vector<bool> & visited, vector<Vertex> & mate){
	OutEdgeIt ebeg,eend;
	visited[u] = true;
	for(tie(ebeg,eend) = out_edges(u,G); ebeg != eend; ++ebeg){
		const int v  = target(*ebeg,G);
		if(!visited[v] && (((v == mate[u]) != (u<v)))){
			DFS(v,G,visited,mate);
		}
	}
}
// Functions
// ========= 
void testcases() {
	int g,s,l;
	cin>>g>>s>>l;
	Graph G(g+s);	// creates an empty graph on n vertices
	//WeightMap weightmap = get(edge_weight, G);
	for(int i = 0; i < l; i++)
	{
		int u,v;
		cin>>u>>v;
		Edge e;
		bool success;
		tie(e,success) = add_edge(u,v+g,G);

	}
	vector<Vertex> matemap(g+s);		// We MUST use this vector as an Exterior Property Map: Vertex -> Mate in the matching
	edmonds_maximum_cardinality_matching(G, make_iterator_property_map(matemap.begin(), get(vertex_index, G)));

	vector<bool> visited(g+s);
	vector<int> startpoints;
	for(int i = 0; i < g+s; i++){
		if(matemap[i] == graph_traits<Graph>::null_vertex() && i < g){
			startpoints.push_back(i);
		}
	}
	//DFS
	for(int i = 0; i < startpoints.size(); i++){
		DFS(startpoints[i],G,visited,matemap);
	}

	vector<int> out_ground_ids;
	vector<int> out_satellite_ids;
	for(int index = 0; index < g+s; index++){
		if(index < g && !visited[index]){
			out_ground_ids.push_back(index);
		}else if(index >= g && visited[index]){
			out_satellite_ids.push_back(index-g);
		}
	}
	cout<<out_ground_ids.size()<<" " <<out_satellite_ids.size()<<endl;

	for(int i = 0; i < out_ground_ids.size(); i++){
		cout<<out_ground_ids[i]<<" ";
	}
	for(int i = 0; i < out_satellite_ids.size(); i++){
		cout<<out_satellite_ids[i]<<" ";
	}
	cout<<endl;

	//collect unmarked
}

// Main function looping over the testcases
int main() {
	ios_base::sync_with_stdio(false); // if you use cin/cout. Do not mix cin/cout with scanf/printf calls!
	int T;
	cin>>T;
	while(T--)	testcases();
	return 0;
}

