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

void DFS(int u, Graph & G, vector<bool> & visited, vector<Vertex> & matemap){
	OutEdgeIt ebeg, eend;
	visited[u] = true;
	for(tie(ebeg,eend) = out_edges(u,G); ebeg != eend; ebeg++){
		int v = target(*ebeg,G);
		if(!visited[v] && (((v == matemap[u]) != (u<v)))){
			DFS(v,G,visited,matemap);
		}
	}
}
// Functions
// ========= 
void testcases() {
	int num_ground,num_sat,links;
	cin>>num_ground>>num_sat>>links;
	Graph G(num_ground+num_sat);	// creates an empty graph on n vertices
	WeightMap weightmap = get(edge_weight, G);	// start by defining property maps for all interior properties defined in Lines 37, 38
	for(int i = 0; i < links; i++){
		int u,v;
		cin>>u>>v;
		//u is ground
		//v is sat
		Edge e;
		bool succ;
		tie(e,succ) = add_edge(u,num_ground+v,G);
	}

	vector<Vertex> matemap(num_ground+num_sat);		// We MUST use this vector as an Exterior Property Map: Vertex -> Mate in the matching
	edmonds_maximum_cardinality_matching(G, make_iterator_property_map(matemap.begin(), get(vertex_index, G)));
	const Vertex NULL_VERTEX = graph_traits<Graph>::null_vertex();	// unmatched vertices get the NULL_VERTEX as mate.
	
	//find which edge is not in matching

	vector<int> sats;
	vector<int> grounds;
	vector<int> startp;
	for(int i = 0; i <num_ground+num_sat; i++){
		if(matemap[i] == NULL_VERTEX && i < num_ground){
			startp.push_back(i);
		}
	}

	vector<bool> visited(num_ground+num_sat,false);
	for(int i = 0; i < startp.size(); i++){
		DFS(startp[i],G,visited,matemap);
	}
	for(int i = 0; i < num_ground+num_sat; i++){
		if(i < num_ground && !visited[i]){
			grounds.push_back(i);
		}else{
			if(i >= num_ground && visited[i]){
				sats.push_back(i-num_ground);
			}
		}
	}
	cout<<grounds.size()<<" " <<sats.size()<<endl;
	for(int i = 0; i < grounds.size(); i++){
		cout<<grounds[i]<<" ";
	}
	for(int i = 0; i  < sats.size(); i++){
		cout<<sats[i]<<" ";
	}
	cout<<endl;
}

// Main function looping over the testcases
int main() {
	ios_base::sync_with_stdio(false); // if you use cin/cout. Do not mix cin/cout with scanf/printf calls!
	int T;
	cin>>T;
	while(T--)	testcases();
	return 0;
}

