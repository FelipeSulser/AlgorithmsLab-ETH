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
#include <boost/graph/biconnected_components.hpp>
// Namespaces
using namespace std;
using namespace boost;

namespace boost
{
  struct edge_component_t
  {
    enum
    { num = 555 };
    typedef edge_property_tag kind;
  }
  edge_component;
}


// BGL Graph definitions
// =====================
// Graph Type, OutEdgeList Type, VertexList Type, (un)directedS
typedef adjacency_list<vecS, vecS, undirectedS,		// Use vecS for the VertexList! Choosing setS for the OutEdgeList disallows parallel edges.
		no_property,				// interior properties of vertices	
		property<edge_component_t, int> 		// interior properties of edges
		>					Graph;
typedef graph_traits<Graph>::edge_descriptor		Edge;		// Edge Descriptor: an object that represents a single edge.
typedef graph_traits<Graph>::vertex_descriptor		Vertex;		// Vertex Descriptor: with vecS vertex list, this is really just an int in the range [0, num_vertices(G)).	
typedef graph_traits<Graph>::edge_iterator		EdgeIt;		// to iterate over all edges
typedef graph_traits<Graph>::out_edge_iterator		OutEdgeIt;	// to iterate over all outgoing edges of a vertex
typedef property_map<Graph, edge_component_t>::type	WeightMap;	// property map to access the interior property edge_weight_t


// Functions
// ========= 
void testcases() {
	// Create Graph, Vertices and Edges
	// ================================
	int N,M;
	cin>>N>>M;
	int V = N;
	Graph G(V);	// creates an empty graph on n vertices
	for (int i = 0; i < M; ++i) {
		Edge e;
		bool success;
		int u,v;
		cin>>u>>v;
		tie(e, success) = add_edge(u, v, G);	// Adds edge from u to v. If parallel edges are allowed, success is always true.
							// Caveat: if u or v don't exist in G, G is automatically extended!
	}

	property_map<Graph,edge_component_t>::type component = get(edge_component,G);
	// Connected components
	// ====================
	EdgeIt ebeg, eend;
	int size = biconnected_components(G, component); 
	vector<int> componentsize(size);
	// Iterate over all vertices
	for(tie(ebeg,eend) = edges(G); ebeg != eend; ++ebeg){
		componentsize[component[*ebeg]]++;
	}
	vector<pair<int,int> > bridges;
	for(tie(ebeg,eend) = edges(G); ebeg != eend; ++ebeg){
		if(componentsize[component[*ebeg]] == 1){
			//this is an important bridge
			Vertex u = source(*ebeg,G);
			Vertex v = target(*ebeg,G);
			bridges.push_back(make_pair(min(u,v),max(u,v)));
		}
	}
	std::sort(bridges.begin(),bridges.end());

	cout<<bridges.size()<<endl;
	for(int i = 0; i < bridges.size(); i++){
		cout<<bridges[i].first<<" " <<bridges[i].second<<endl;
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

