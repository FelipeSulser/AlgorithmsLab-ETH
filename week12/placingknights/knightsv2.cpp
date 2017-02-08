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
	vector<vector<int> > board(n, vector<int>(n,0));
	for(int i = 0;i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>board[i][j];
			if(board[i][j] == 0) holes++;
		}
	}

	int V = n*n;
	Graph G(V);	// creates an empty graph on n vertices

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int curr = i + j*n;
			if(board[i][j] == 1){
				if(i-1 >= 0 && j-2 >= 0 && board[i-1][j-2]){
					add_edge(curr,(i-1)+(j-2)*n,G);
				}

				if(i-1 >= 0 && j+2 < n && board[i-1][j+2]){
					add_edge(curr,(i-1)+(j+2)*n,G);
				}

				if(i+1 < n && j-2 >= 0 && board[i+1][j-2]){
					add_edge(curr,(i+1)+(j-2)*n,G);
				}
				if(i+1 < n && j+2 < n && board[i+1][j+2]){
					add_edge(curr,(i+1)+(j+2)*n,G);
				}
				if(i-2 >= 0 &&  j-1 >= 0 && board[i-2][j-1]){
					add_edge(curr,(i-2)+(j-1)*n,G);
				}
				if(i-2 >= 0 && j+1 < n && board[i-2][j+1]){
					add_edge(curr,(i-2)+(j+1)*n,G);
				}
				if(i+2 < n && j-1 >= 0 && board[i+2][j-1]){
					add_edge(curr,(i+2)+(j-1)*n,G);
				}
				if(i+2 < n && j+1 < n && board[i+2][j+1]){
					add_edge(curr,(i+2)+(j+1)*n,G);
				}
			}
		}
	}
	vector<Vertex> matemap(V);		// We MUST use this vector as an Exterior Property Map: Vertex -> Mate in the matching
	edmonds_maximum_cardinality_matching(G, make_iterator_property_map(matemap.begin(), get(vertex_index, G)));
	// Using the matemap 
	// =================
	const Vertex NULL_VERTEX = graph_traits<Graph>::null_vertex();	// unmatched vertices get the NULL_VERTEX as mate.
	int matchingsize = matching_size(G, make_iterator_property_map(matemap.begin(), get(vertex_index, G)));
	cout<<(n*n - holes) - matchingsize<<endl;
}

// Main function looping over the testcases
int main() {
	ios_base::sync_with_stdio(false); // if you use cin/cout. Do not mix cin/cout with scanf/printf calls!
	int T;
	cin>>T;
	while(T--)	testcases();
	return 0;
}

