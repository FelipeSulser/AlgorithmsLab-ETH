// STL includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
#include <string>
#include <set>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
#include <boost/functional/hash.hpp>
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

int hash_val(string & s){
	boost::hash<std::string> string_hash;
	return string_hash(s);
}
// Functions
// ========= 
void testcases() {
	int N,M,F;
	cin>>N>>M>>F;
	vector<set<int>> likes(N);
	for(int i = 0; i< N; i++){
		for(int j = 0; j < M; j++){
			string keyword;
			cin>>keyword;
			likes[i].insert(hash_val(keyword));
		}
	}


	int V = N;
	Graph G(V);	// creates an empty graph on n vertices
	set<int> curr_i;
	set<int> curr_j;
	for(int i = 0; i < N; i++){
		curr_i = likes[i];
		for(int j = i+1; j < N; j++){
			curr_j = likes[j];
			//compute intersection

			vector<int> inter;
			set_intersection(curr_i.begin(),curr_i.end(),
				curr_j.begin(),curr_j.end(),
				std::back_inserter(inter));
			if(inter.size() > F){
				Edge e;
				bool success;
				tie(e,success) = add_edge(i,j,G);
			}

		}
	}

	vector<Vertex> matemap(V);		// We MUST use this vector as an Exterior Property Map: Vertex -> Mate in the matching
	edmonds_maximum_cardinality_matching(G, make_iterator_property_map(matemap.begin(), get(vertex_index, G)));
	
	int matchingsize = matching_size(G,&matemap[0]);
	if(matchingsize == N/2){
		//this is optimal, so other one wasnt
		cout<<"not optimal"<<endl;

	}else{
		cout<<"optimal"<<endl;
	}
}

// Main function looping over the testcases
int main() {
	ios_base::sync_with_stdio(false); // if you use cin/cout. Do not mix cin/cout with scanf/printf calls!
	int T;	cin>>T;
	while(T--)	testcases();
	return 0;
}

