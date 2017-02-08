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

void do_calc(){
	int N,E,S,A,B;
	cin>>N>>E>>S>>A>>B;
	vector<Graph> species(S);
	vector<WeightMap> weights(S);

	for(int i = 0; i < S; i++){
		Graph g(N);
		WeightMap map = get(edge_weight,g);
		species[i] = g;
		weights[i] = map;
	}

	Graph mingraph(N);
	WeightMap minweight = get(edge_weight,mingraph);

	for(int i = 0; i < E; i++){
		int u,v;
		cin>>u>>v;

		for(int j = 0; j < S; j++)
		{	
			int w;
			cin>>w;
			Edge e;
			bool succ;
			tie(e,succ) = add_edge(u,v,species[j]);
			weights[j][e] = w;
		}

		//initialize the min graph to infinity all its edges
		Edge e2;
		bool succ2;
		tie(e2, succ2) = add_edge(u,v,mingraph);
		minweight[e2] = INT_MAX;
	}


	vector<int> hives(S);
	//now to find the hives, start for prim
	for(int i = 0; i < S; i++){
		cin>>hives[i];
	}

	//for every species, compute prim and minimize the global graph with each edge
	for(int i = 0; i < S; i++){
		Graph G = species[i];
		WeightMap wm = weights[i];
		vector<Vertex> primpredmap(N);	// We MUST use this vector as an Exterior Property Map: Vertex -> Prim Predecessor
		Vertex start = hives[i];
		prim_minimum_spanning_tree(species[i], make_iterator_property_map(primpredmap.begin(), get(vertex_index, species[i])),root_vertex(start));	
		for(int j = 0; j < N; j++){
			if(primpredmap[j] != j){
				Edge e;
				bool success;
				tie(e,success) = edge(j,primpredmap[j],species[i]);

				Edge e2;
				bool succ;
				tie(e2,succ) = edge(j,primpredmap[j],mingraph);
				minweight[e2] = std::min(minweight[e2],weights[i][e]);
			}
		}
	}

	//now do good old dijkstra
	vector<Vertex> predmap(N);
	vector<int> distmap(N);
	Vertex start = A;
	dijkstra_shortest_paths(mingraph, start, // We MUST provide at least one of the two maps
		predecessor_map(make_iterator_property_map(predmap.begin(), get(vertex_index, mingraph))).	// predecessor map as Named Parameter
		distance_map(make_iterator_property_map(distmap.begin(), get(vertex_index, mingraph))));	// distance map as Named Parameter


	cout<<distmap[B]<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();

	return 0;
}