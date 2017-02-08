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


// BGL Graph definitions
// =====================
// Graph Type with nested interior edge properties for Flow Algorithms
typedef	adjacency_list_traits<vecS, vecS, directedS> Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
	property<edge_capacity_t, long,
		property<edge_residual_capacity_t, long,
			property<edge_reverse_t, Traits::edge_descriptor> > > >	Graph;
// Interior Property Maps
typedef	property_map<Graph, edge_capacity_t>::type		EdgeCapacityMap;
typedef	property_map<Graph, edge_residual_capacity_t>::type	ResidualCapacityMap;
typedef	property_map<Graph, edge_reverse_t>::type		ReverseEdgeMap;
typedef	graph_traits<Graph>::vertex_descriptor			Vertex;
typedef	graph_traits<Graph>::edge_descriptor			Edge;


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


// Functions
// =========
// Function for an individual testcase
void testcases() {
	int n,m;
	cin>>n>>m;
	Graph G(m+n+2);
	int start = m+n;
	int end = m+n+1;
	EdgeCapacityMap capacitymap = get(edge_capacity, G);
	ReverseEdgeMap revedgemap = get(edge_reverse, G);
	ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
	EdgeAdder eaG(G, capacitymap, revedgemap);

	for(int i = 0; i < m; i++){
		eaG.addEdge(start,i,1);
	}
	for(int i = 0; i < m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(c != 0){
			if(c == 1)
				eaG.addEdge(i,m+a,1);
			else
				eaG.addEdge(i,m+b,1);
		}else{
			eaG.addEdge(i,m+a,1);
			eaG.addEdge(i,m+b,1);
		}
	}
	int totalscore = 0;
	for(int i = 0; i < n; i++){
		int val;
		cin>>val;
		totalscore+= val;
		eaG.addEdge(i+m,end,val);
	}
	long flow1 = push_relabel_max_flow(G, start, end);
	if(flow1 == totalscore && m == totalscore){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}
}

// Main function to loop over the testcases
int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for (; T > 0; --T)	testcases();
	return 0;
}
