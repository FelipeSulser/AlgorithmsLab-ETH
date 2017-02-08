#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
#include <set>
#include <string>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
#include <boost/functional/hash.hpp>
#include <map>
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

int hashCode(string & s){
	boost::hash<string> string_hash;
	return string_hash(s);
}

// Functions
// ========= 
void testcases() {
	int N,C,F;
	cin>>N>>C>>F;
	int V = N;
	Graph G(V);	// creates an empty graph on n vertices
	map<int,set<int> > students;
	for(int i = 0; i < N; i++){
		set<int> charac;
		for(int j = 0; j < C; j++){
			string keyword;
			cin>>keyword;
			charac.insert(hashCode(keyword));
		}
		students[i] = charac;
	}
	set<int> v1;
	set<int> v2;
	for(int i = 0; i < N; i++){
		v1 = students[i];
		for(int j = i+1; j< N; j++){
			vector<int> v_intersection;
			//if they share more than F add to graph
			
			v2 = students[j];
			std::set_intersection(v1.begin(), v1.end(),
                          v2.begin(), v2.end(),
                          std::back_inserter(v_intersection));
			if(v_intersection.size() > F){
				bool success;
				Edge e;
				tie(e,success) = add_edge(i,j,G);

			}

		}
	}
	
	vector<Vertex> matemap(V);		// We MUST use this vector as an Exterior Property Map: Vertex -> Mate in the matching
	edmonds_maximum_cardinality_matching(G, make_iterator_property_map(matemap.begin(), get(vertex_index, G)));
	// Using the matemap 
	// =================
	int matchingsize = matching_size(G,&matemap[0]);
	if(matchingsize == N/2){
		//current is optimal, but professors fuzzy wasnt
		cout<<"not optimal"<<endl;
	}else{
		cout<<"optimal"<<endl;
	}
}

// Main function looping over the testcases
int main() {
	ios_base::sync_with_stdio(false); // if you use cin/cout. Do not mix cin/cout with scanf/printf calls!
	int T;
	cin>>T;
	while(T--)	testcases();
	return 0;
}

