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
	int n;
	cin>>n;
	int holes = 0;
	Graph G(n*n);	// creates an empty graph on n vertices
	//N is length of chessboard
	vector<vector<bool> > isHole(n,vector<bool>(n,false));
	for(int i = 0; i< n; i++){
		for(int j = 0; j< n; j++){
			int val;
			cin>>val;
			if(val == 1) isHole[i][j] = false;
			else{
				isHole[i][j] = true;
				holes++;
			} 
		}
	}

	//so know we mark the relationshps for each pos i,j that a knight will have,
	//if theres a hole there will not be any relationship

	for(int i = 0; i < n; i++)	
	{
		for(int j = 0; j < n; j++){
			if(isHole[i][j]) continue;

			//
			int u = i*n+j;

			int x,y;

			x = i-1;
			y = j-2;
			if(x >=0 && y >= 0 && !isHole[x][y]){
				add_edge(u,x*n+y,G);
			}

			x = i-1;
			y = j+2;
			if(x >= 0 && y < n & !isHole[x][y]){
				add_edge(u,x*n+y,G);
			}

			x = i+1;
			y = j-2;
			if(x < n && y >= 0 && !isHole[x][y]){
				add_edge(u,x*n+y,G);
			}
			x = i+1;
			y = j+2;
			if(x < n && y < n && !isHole[x][y]){
				add_edge(u,x*n+y,G);
			}
			x = i-2;
			y = j-1;
			if(x >= 0 && y >= 0 && !isHole[x][y]){
				add_edge(u,x*n+y,G);
			}
			x = i-2;
			y = j+1;
			if(x >= 0 && y < n && !isHole[x][y]){
				add_edge(u,x*n+y,G);
			}

			x = i+2;
			y = j-1;
			if(x < n && y >= 0 && !isHole[x][y]){
				add_edge(u,x*n+y,G);
			}
			x = i+2;
			y = j+1;
			if(x < n && y < n && !isHole[x][y]){
				add_edge(u,x*n+y,G);
			}


		}
	}


	vector<Vertex> matemap(n*n);		// We MUST use this vector as an Exterior Property Map: Vertex -> Mate in the matching
	edmonds_maximum_cardinality_matching(G, make_iterator_property_map(matemap.begin(), get(vertex_index, G)));
	
	const Vertex NULL_VERTEX = graph_traits<Graph>::null_vertex();	// unmatched vertices get the NULL_VERTEX as mate.
	int matchingsize = matching_size(G, make_iterator_property_map(matemap.begin(), get(vertex_index, G)));
	cout<<(n*n-holes) - matchingsize<<endl;
}

// Main function looping over the testcases
int main() {
	ios_base::sync_with_stdio(false); // if you use cin/cout. Do not mix cin/cout with scanf/printf calls!
	int T;
	cin>>T;
	while(T--)	testcases();
	return 0;
}

