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
void testcases() {
	int h,w,p;
	cin>>h>>w>>p;

	vector<pair<int,int> > entrances(p);
	vector<pair<int,int> > exits(p);
	for(int i = 0; i < p; i++){
		int q,r,s,t;
		cin>>q>>r>>s>>t;
		entrances[i] = make_pair(q,r);
		exits[i] = make_pair(s,t);
	}
	vector<vector<int> > floorplan(h,vector<int>(w,0));
	Graph G(h*w);	// creates an empty graph on n vertices
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			char car;
			cin>>car;
			if(car == '1'){
				floorplan[i][j] = 1;
			}else{
				floorplan[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			
			if(floorplan[i][j] != 0){
				if(i > 0 && floorplan[i-1][j] != 0){
					//cout<<"Edge from "<<i<<" "<<j<<" to "<<i-1<<" "<<j<<endl;
					add_edge(i+j*h,(i-1)+j*h,G);
				}
				if(i < h-1 && floorplan[i+1][j] != 0){
					//cout<<"Edge from "<<i<<" "<<j<<" to "<<i+1<<" "<<j<<endl;
					add_edge(i+j*h,(i+1)+j*h,G);
				}
				if(j > 0 && floorplan[i][j-1] != 0){
					//cout<<"Edge from "<<i<<" "<<j<<" to "<<i<<" "<<j-1<<endl;
					add_edge(i+j*h,i+(j-1)*h,G);
				}
				if(j < w-1 && floorplan[i][j+1] != 0){
					//cout<<"Edge from "<<i<<" "<<j<<" to "<<i<<" "<<j+1<<endl;
					add_edge(i+j*h,i+(j+1)*h,G);
				}
			}
		}
		
	}

	int V = h*w;
	vector<int> componentmap(V);	// We MUST use such a vector as an Exterior Property Map: Vertex -> Component
	int ncc = connected_components(G, make_iterator_property_map(componentmap.begin(), get(vertex_index, G))); 
	
	for(int i = 0; i < p; i++){
		int q = entrances[i].first;
		int r = entrances[i].second;
		int s = exits[i].first;
		int t = exits[i].second;
		q--;
		r--;
		s--;
		t--;
		//cout<<componentmap[q+r*h]<<endl;
		//cout<<componentmap[s+t*h]<<endl;
		if(componentmap[q+r*h] == componentmap[s+t*h]){
			if((q+r) % 2 != (s+t)% 2){
				cout<<"y";
			}else{
				cout<<"n";
			}
		}else{
			cout<<"n";
		}
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

