#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/max_cardinality_matching.hpp>

using namespace boost;
using namespace std;


typedef adjacency_list<vecS,vecS,undirectedS,no_property> Graph;
typedef adjacency_list<vecS,vecS,directedS,no_property, property<edge_weight_t,int> > DiGraph;
typedef property_map<DiGraph,edge_weight_t>::type WeightMap;
typedef graph_traits<DiGraph>::vertex_descriptor Vertex;
typedef graph_traits<DiGraph>::edge_descriptor Edge;


void do_calc(){
	int N,M,A,S,C,D;
	cin>>N>>M>>A>>S>>C>>D;

	DiGraph G(N);
	WeightMap weight_map = get(edge_weight,G);

	for(int i = 0; i < M; i++){
		char w;
		int x, y , z;
		cin>>w>>x>>y>>z;

		Edge e;
		bool success;
		tie(e,success) = add_edge(x,y,G);
		weight_map[e] = z;
		if(w == 'L'){
			tie(e,success) = add_edge(y,x,G);
			weight_map[e] = z;
		}
	}

	vector<vector<int> > distmap(A,vector<int>(N));
	for(int i = 0; i < A; i++){
		int j; cin>>j;
		dijkstra_shortest_paths(G,j,distance_map(make_iterator_property_map(distmap[i].begin(),
			get(vertex_index,G))));
	}

	vector<vector<int> > T(A,vector<int>(S));
	for(int i = 0; i < S; i++){
		int j;
		cin>>j;
		for(int k = 0; k  < A; k++){
			T[k][i] = distmap[k][j];
		}
	}

	int lmin = 0;
	int lmax = INT_MAX;
	while(lmin < lmax)
	{
		int mid = lmin+(lmax-lmin)/2;
		Graph GG(A+C*S);
		for(int i = 0; i < A; i++){
			for(int j = 0; j < S; j++){
				if(T[i][j]  == INT_MAX) continue;
				for(int c = 0; c < C; c++){
					if(T[i][j] + (c+1)*D <= mid){
						add_edge(i,A+c*S+j,GG);
					}
				}
			}
		}
		vector<Vertex> matemap(A+C*S);
		edmonds_maximum_cardinality_matching(GG,make_iterator_property_map(matemap.begin(),get(vertex_index,GG)));

		const Vertex NULL_VERTEX = graph_traits<Graph>::null_vertex();
		int matching_size = 0;
		for(int i = 0; i < A; i++){
			matching_size+=(matemap[i] != NULL_VERTEX);
		}
		if(matching_size == A){
			lmax = mid;
		}else{
			lmin = mid+1;
		}
	}
	cout<<lmin<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}