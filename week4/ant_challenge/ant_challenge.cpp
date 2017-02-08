#include <iostream>
#include <vector>
#include <climits>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/strong_components.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>

using namespace std;
using namespace boost;


typedef adjacency_list<vecS,vecS,undirectedS,
		no_property,
		property<edge_weight_t, int>
		>	Graph;
typedef graph_traits<Graph>::vertex_descriptor	Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef property_map<Graph,edge_weight_t>::type  WeightMap;


void do_calc()
{
	int N,E,S,A,B;
	cin>>N>>E>>S>>A>>B;

	vector<Graph> species(S);
	vector<WeightMap> weightmaps(S);
	vector<int> hives(S);

	//now we got the data
	//first compute prim for all and for each edge, we keep shortest
	Graph mingraph(N);
	WeightMap minweight = get(edge_weight,mingraph);
	for(int i = 0; i <E; i++){
		int u;
		int v;
		cin>>u>>v;
		//each edge
		for(int j = 0; j < S; j++){
			int w;
			cin>>w;
			Edge e;
			bool success;
			tie(e,success) = add_edge(u,v,species[j]);
			weightmaps[j][e] = w;
		}
		//add also an edge to min with infinite weight
		Edge ee;
		bool succ;
		tie(ee,succ) = add_edge(u,v,mingraph);
		minweight[ee] = INT_MAX;
	}
	for(int i = 0; i < S; i++){
		cin>>hives[i];
	}

	

	for(int i = 0; i <S; i++){
		vector<Vertex> primpredmap(N);
		Vertex start = hives[i];
		Graph G = species[i];
		prim_minimum_spanning_tree(species[i], make_iterator_property_map(primpredmap.begin(), get(vertex_index, species[i])),	// Prim from user-defined start,
				root_vertex(start));

		//for each edge get min
		for(int j = 0; j < N; j++){
			if(j != primpredmap[j]){
				Edge e;
				bool success;
				tie(e,success) = edge(j,primpredmap[j],G);

				Edge e2;
				bool success2;
				tie(e2,success2) = edge(j,primpredmap[j],mingraph);
				minweight[e2] = std::min(minweight[e2],weightmaps[i][e]);
			}
		}

	}

	//now we have final graph, do dijkstra and done
	vector<Vertex> predmap(N);
	vector<int> distmap(N);
	Vertex start = A;

dijkstra_shortest_paths(mingraph,start,
		predecessor_map(make_iterator_property_map(predmap.begin(),get(vertex_index,mingraph))).
		distance_map(make_iterator_property_map(distmap.begin(),get(vertex_index,mingraph))));

		cout<<distmap[B]<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();

	return 0;
}