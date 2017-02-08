#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/edmonds_karp_max_flow.hpp>
#include <algorithm>

using namespace std;
using namespace boost;

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

class EdgeAdder {
	Graph &G;
	EdgeCapacityMap	&capacitymap;
	ReverseEdgeMap	&revedgemap;

public:
	// to initialize the Object
	EdgeAdder(Graph & G, EdgeCapacityMap &capacitymap, ReverseEdgeMap &revedgemap):
		G(G), capacitymap(capacitymap), revedgemap(revedgemap){}
	// to use the Function (add an edge)
	void addEdge (int from, int to, long capacity) {
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
void do_calc(){
	int m, n, k,C;
	cin >> m >> n >> k>>C;

	Graph G(2*m*n+2);
	EdgeCapacityMap capacitymap = get(edge_capacity, G);
	ReverseEdgeMap revedgemap = get(edge_reverse, G);
	ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
	EdgeAdder eaG(G, capacitymap, revedgemap);
	 /*
		We have the following vertices:
		[knights | intersec_edges to hallways | hallways to intersec | start | end]

	 */
	// start and end
	int start = 2*m*n;
	int end = start+1;

	// knights
	for(int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		eaG.addEdge(start,y*m+x,1); //dual node is intersection node
	}

	// add missing edges
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			// edge from intersec to hallways with constraint C
			eaG.addEdge(i+j*m,m*n+i+j*m,C); //primal to dual
			

			//from dual to primal cost 1
			if(i - 1 >= 0) {
				eaG.addEdge(m*n+i+j*m,(i-1)+j*m,1);				
			}

			if(i + 1 < m) {
				eaG.addEdge(m*n+i+j*m,(i+1)+j*m,1);				
			}

			if(j - 1 >= 0) {
				eaG.addEdge(m*n+i+j*m,i+(j-1)*m,1);
			}

			if(j + 1 < n) {
				eaG.addEdge(m*n+i+j*m,i+(j+1)*m,1);
			}

			// add end edge to hallways -> all are exit
			if(i == 0 || i + 1 == m || j == 0 || j + 1 == n) {
				if(i == 0 && j == 0){
					eaG.addEdge(m*n+i+j*m,end,2);
				}else{
					if(i == m-1 && j == 0){
						eaG.addEdge(m*n+i+j*m,end,2);
					}else{
						if(i == 0 &&j == n-1){
							eaG.addEdge(m*n+i+j*m,end,2);
						}else{
							if(i == m-1 && j == n-1){
								eaG.addEdge(m*n+i+j*m,end,2);
							}else{
								eaG.addEdge(m*n+i+j*m,end,1);
							}
						}
					}
				}
				
				//eaG.addEdge(k+i+j*m,end,1);
			}
		}
	}

	//Max flow = number of escaped knights
	long flow = push_relabel_max_flow(G, start, end);
	cout << flow << endl;

}

int main() {
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while(T--) do_calc();
		

	return 0;
}