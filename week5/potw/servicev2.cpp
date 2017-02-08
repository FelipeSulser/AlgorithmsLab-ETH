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
typedef adjacency_list<vecS, vecS, directedS,		// Use vecS for the VertexList! Choosing setS for the OutEdgeList disallows parallel edges.
		no_property,				// interior properties of vertices	
		property<edge_weight_t, int> 		// interior properties of edges
		>		DiGraph;
typedef graph_traits<DiGraph>::edge_descriptor		Edge;		// Edge Descriptor: an object that represents a single edge.
typedef graph_traits<DiGraph>::vertex_descriptor		Vertex;		// Vertex Descriptor: with vecS vertex list, this is really just an int in the range [0, num_vertices(G)).	
typedef graph_traits<DiGraph>::edge_iterator		EdgeIt;		// to iterate over all edges
typedef graph_traits<DiGraph>::out_edge_iterator		OutEdgeIt;	// to iterate over all outgoing edges of a vertex
typedef property_map<DiGraph, edge_weight_t>::type	WeightMap;	// property map to access the interior property edge_weight_t


// Functions
// ========= 
void testcases() {
	int N,M,A,S,C,D;
	cin>>N>>M>>A>>S>>C>>D;

	DiGraph directed(N);
	WeightMap weight = get(edge_weight,directed);

	for(int i = 0; i < M; i++){
		char w;
		int x,y,z;
		cin>>w>>x>>y>>z;
		Edge e;
		bool success;
		tie(e,success) = add_edge(x,y,directed);
		weight[e] = z;

		if(w == 'L'){
			tie(e,success) = add_edge(y,x,directed);
			weight[e] = z;
		}

	}
	vector<vector<int> > distances(A,vector<int>(N));
	for(int i = 0; i < A; i++){
		int start;
		cin>>start;
		vector<Vertex> predmap(N);
		dijkstra_shortest_paths(directed, start, // We MUST provide at least one of the two maps
		distance_map(make_iterator_property_map(distances[i].begin(), get(vertex_index, directed))));
	}

	//dist to objectives
	vector<vector<int> > timed(A,vector<int>(S));
	for(int i = 0; i < S; i++){
		int pos;
		cin>>pos;
		for(int j = 0; j < A; j++){
			timed[j][i] = distances[j][pos];
		}
	}

	int lmin = 0;
	int lmax = INT_MAX;
	while(lmin < lmax){
		int mid = (lmin+lmax)/2;
		//create graph
		Graph G(A+C*S);
		//no weight
		for(int i = 0; i < A; i++){
			for(int j = 0; j < S; j++){
				if(timed[i][j] != INT_MAX){
					for(int k = 0; k < C; k++){
						if(timed[i][j] + (k+1)*D <= mid){
							//if i have time
							add_edge(i,A+S*k+j,G);
						}
					}
				}
			}
		}
		vector<Vertex> matemap(A+C*S);		// We MUST use this vector as an Exterior Property Map: Vertex -> Mate in the matching
		edmonds_maximum_cardinality_matching(G, make_iterator_property_map(matemap.begin(), get(vertex_index, G)));
		const Vertex NULL_VERTEX = graph_traits<Graph>::null_vertex();	// unmatched vertices get the NULL_VERTEX as mate.
		int matchingsize = matching_size(G, make_iterator_property_map(matemap.begin(), get(vertex_index, G)));
		
		if(matchingsize == A){
			//can be lower
			lmax = mid;
		}else{
			lmin = mid+1;
		}
	}
	cout<<lmin<<endl;
}

// Main function looping over the testcases
int main() {
	ios_base::sync_with_stdio(false); // if you use cin/cout. Do not mix cin/cout with scanf/printf calls!
	int T;
	cin>>T;
	while(T--)	testcases();
	return 0;
}

