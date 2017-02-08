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
typedef adjacency_list<vecS, vecS, directedS,		// Use vecS for the VertexList! Choosing setS for the OutEdgeList disallows parallel edges.
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
	int k;
	cin>>k;
	vector<vector<int> > graph(k,vector<int>(k,-1));
	int size = 0;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= i; j++){
			int val;
			size++;
			cin>>val;
			graph[i-1][j-1] = val;
		}
	}
	//create the graph now from the table
	size = k*k;
	int V = size*2; //dual vertex to represent weight by inner edge
	Graph G(V);	// creates an empty graph on n vertices
	WeightMap weightmap = get(edge_weight, G);	// start by defining property maps for 
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= i; j++){
			//connect it to the others
			int x = i-1;
			int y = j-1;
			//go to dual
			//cout<<"FROM "<<x<<" " <<y<<endl;
			Edge e;
			bool succ;
			tie(e,succ) = add_edge(x+y*k,size+x+y*k,G);
			weightmap[e] = graph[x][y];
			if(x-1 >= 0 && graph[x-1][y] != -1){
				//can go up
				//go from dual to primal of next
				//cout<<"To "<<x-1<<" " <<y<<endl;
				int val1 = size+x+y*k;
				int val2 = (x-1)+y*k;
				//if(val1 >= V || val2 >= V) cout<<"HERE1"<<endl;
				tie(e,succ) = add_edge(val1,val2,G);
				//cout<<succ<<endl;
				weightmap[e] = 0;
			}
			if(y-1 >= 0 && graph[x][y-1] != -1){
				//cout<<"To "<<x<<" "<< y-1<<endl;
				int val1 = size+x+y*k;
				int val2 = (x)+(y-1)*k;

				
				tie(e,succ) = add_edge(val1,val2,G);
				//cout<<succ<<endl;
				weightmap[e] = 0;
			}
			if(y+1 < k && graph[x][y+1] != -1){	
				//cout<<"To "<<x<<" "<<y+1<<endl;
				int val1 = size+x+y*k;
				int val2 = (x)+(y+1)*k;
				
				tie(e,succ) = add_edge(val1,val2,G);
				//cout<<succ<<endl;
				weightmap[e] = 0;
			}
			if(x+1 < k && graph[x+1][y] != -1){
				//cout<<"To "<<x+1<<" " <<y<<endl;
				int val1 = size+x+y*k;
				int val2 = (x+1)+y*k;
				
				tie(e,succ) = add_edge(val1,val2,G);
				//cout<<succ<<endl;
				weightmap[e] = 0;
			}
			if(x+1 < k && y+1 < k && graph[x+1][y+1] != -1){
				//cout<<"To "<<x+1<<" " <<y+1<<endl;
				int val1 = size+x+y*k;
				int val2 = (x+1)+(y+1)*k;
				
				tie(e,succ) = add_edge(val1,val2,G);
				//cout<<succ<<endl;
				weightmap[e] = 0;
			}
			if(x-1 >= 0 && y-1 >= 0 && graph[x-1][y-1] != -1){
				//cout<<"To "<<x-1<<" " <<y-1<<endl;
				int val1 = size+x+y*k;
				int val2 = (x-1)+(y-1)*k;
				
				tie(e,succ) = add_edge(val1,val2,G);
				weightmap[e] = 0;
			}
		}
	
	}
	//cout<<"ok2"<<endl;
	vector<vector<int> > distmaps(3,vector<int>(V));
	vector<int> start_x = {0,k-1,k-1};
	vector<int> start_y = {0,0,k-1};
	//cout<<"Size "<<V<<endl;
	for(int i = 0; i < 3; i++)	
	{
		Vertex start = start_x[i]+start_y[i]*k;
		vector<Vertex> predmap(V);	// We will use this vector as an Exterior Property Map: Vertex -> Dijkstra Predecessor
		vector<int> distmap(V);		// We will use this vector as an Exterior Property Map: Vertex -> Distance to source
		dijkstra_shortest_paths(G, start, // We MUST provide at least one of the two maps
			distance_map(make_iterator_property_map(distmap.begin(), get(vertex_index, G))));	// distance map as Named Parameter
		distmaps[i] = distmap;
	}
	//cout<<"ok3"<<endl;
	//for each ball candidate
	//if dist is min then select it
	int mincost = INT_MAX;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
			//cout<<"VALUE :"<<i<< " "<<j<<endl;
			int x = i-1;
			int y = j-1;
			Vertex vx = size+x+y*k;
				long long costval = 0;
				bool valid = true;
				for(int k = 0; k < 3; k++){
						costval += distmaps[k][vx];		
				}
				if(costval < mincost)
					mincost = costval;

			}
	}
	cout<<mincost<<endl;
}

// Main function looping over the testcases
int main() {
	ios_base::sync_with_stdio(false); // if you use cin/cout. Do not mix cin/cout with scanf/printf calls!
	int T;
	cin>>T;
	while(T--)	testcases();
	return 0;
}

