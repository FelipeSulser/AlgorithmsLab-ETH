// ALGOLAB BGL Tutorial 2
// Flow example demonstrating
// - interior graph properties for flow algorithms
// - custom edge adder

// Compile and run with one of the following:
// g++ -std=c++11 -O2 flows.cpp -o flows ./flows
// g++ -std=c++11 -O2 -I path/to/boost_1_58_0 flows.cpp -o flows; ./flows

// Includes
// ========
// STL includes
#include <iostream>
#include <vector>
#include <algorithm>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/edmonds_karp_max_flow.hpp>
// Namespaces
using namespace std;
using namespace boost;

// Graph Type with nested interior edge properties for Flow Algorithms
typedef adjacency_list_traits<vecS , vecS , directedS> Traits ;
typedef adjacency_list <vecS , vecS , directedS , no_property ,
property<edge_capacity_t , long ,
property<edge_residual_capacity_t , long ,
property<edge_reverse_t , Traits :: edge_descriptor ,
property <edge_weight_t , long> > > > >Graph;
// Interior Property Maps
 
typedef property_map<Graph , edge_capacity_t >:: type EdgeCapacityMap;
typedef property_map<Graph , edge_residual_capacity_t >:: type  ResidualCapacityMap;
typedef property_map<Graph , edge_reverse_t >:: type  ReverseEdgeMap;
typedef graph_traits<Graph>::vertex_descriptor		Vertex;	
typedef graph_traits<Graph>::edge_descriptor    Edge;
typedef	graph_traits<Graph>::out_edge_iterator			OutEdgeIt;
typedef property_map<Graph,edge_weight_t>::type EdgeWeightMap;

// Custom Edge Adder Class, that holds the references
// to the graph, capacity map and reverse edge map
// ===================================================
class EdgeAdder {
	Graph &G;
	EdgeCapacityMap	&capacitymap;
	ReverseEdgeMap	&revedgemap;

public:
	// to initialize the Object
	EdgeAdder(Graph & G, EdgeCapacityMap &capacitymap, ReverseEdgeMap &revedgemap):
		G(G), capacitymap(capacitymap), revedgemap(revedgemap){}

	// to use the Function (add an edge)
	void addEdge(int from, int to, long capacity) {
		Edge e, reverseE;
		bool success;
		tie(e, success) = add_edge(from, to, G);
		tie(reverseE, success) = add_edge(to, from, G);
		capacitymap[e] = capacity;
		capacitymap[reverseE] = 0;
		revedgemap[e] = reverseE;
		revedgemap[reverseE] = e;
	}
};

void dfs(int x,Graph & G, vector<bool> & isCovered){
	OutEdgeIt ebeg, eend;
	isCovered[x] = 1;
	for(tie(ebeg,eend) = out_edges(x,G); ebeg != eend; ++ebeg){
		Vertex v = target(*ebeg,G);
		if(!isCovered[v]){
			dfs(v,G,isCovered);
		}
	}
}
// Functions
// =========
// Function for an individual testcase
void testcases() {
	int n;
	cin>>n;
	int m;
	cin>>m;
	//n is number of rooms, vertices 
	//m is number of corridors, edges

	int s;
	cin>>s;
	Graph G(n+2);
	vector<int> du(n,0);
	EdgeCapacityMap capacitymap = get(edge_capacity, G);
	ReverseEdgeMap revedgemap = get(edge_reverse, G);
	ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
	EdgeAdder eaG(G, capacitymap, revedgemap);
	int start = n;
	int end = n+1;
	vector<int> ss;
	for(int i = 0; i < s; i++){
		int val;
		cin>>val;
		du[val]++;
		ss.push_back(val);
		eaG.addEdge(start,val,1); // 1 unit of input flow
	}

	for(int i = 0; i < s; i++){
		int val;
		cin>>val;
		du[val]--;
		eaG.addEdge(val,end,1);
	}
	
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		du[u]++;
		du[v]++;
		eaG.addEdge(u,v,1); // 1 unit of flow max per corridor
		eaG.addEdge(v,u,1);
	}
	vector<bool> isCovered(n+2);
	for(int i = 0; i < ss.size(); i++)
		dfs(ss[i],G,isCovered);


	bool has_even_degree = true;
	for(int vertex = 0; vertex < n; vertex++){
		if(du[vertex] < 0 || du[vertex] % 2 != 0){
			has_even_degree = false;
			break;
		}
	}
	if(!has_even_degree){
		cout<<"no"<<endl;
		return;
	}
	long flow1 = push_relabel_max_flow(G, start, end);
	if(s != flow1){
		cout<<"no"<<endl;
		return;
	}

	for(int i = 0; i < n; i++){
		if(!isCovered[i]){
			cout<<"no"<<endl;
			return;
		}
	}
	cout<<"yes"<<endl;

}

// Main function to loop over the testcases
int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for (; T > 0; --T)	testcases();
	return 0;
}
