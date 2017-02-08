//=======================================================================
#include <boost/config.hpp>
#include <vector>
#include <list>
#include <boost/graph/biconnected_components.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <iterator>
#include <iostream>

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

using namespace boost;
using namespace std;

typedef adjacency_list < vecS, vecS, undirectedS,
    no_property, property < edge_component_t, std::size_t > >Graph;

typedef property_map<Graph,edge_component_t>::type ComponentMap;
typedef graph_traits<Graph>::edge_iterator EdgeIt;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;

void do_calc(){
	int N,M;
	cin>>N>>M;
	Graph g(N);
	for(int i = 0; i<  M; i++){
		int u,v;
		cin>>u>>v;
		add_edge(u,v,g);

	}

	property_map < Graph, edge_component_t >::type
	component = get(edge_component, g);

	int num_comps = biconnected_components(g, component);
	
	vector<int> componentsize(num_comps);
	EdgeIt ebeg, eend;
	for(tie(ebeg,eend) = edges(g); ebeg != eend; ++ebeg){
		componentsize[component[*ebeg]]++;
	}
	vector<pair<int,int> > bridges;
	for(tie(ebeg,eend) = edges(g); ebeg != eend; ++ebeg){
		if(componentsize[component[*ebeg]] == 1){
			int u = source(*ebeg,g);
			int v = target(*ebeg,g);
			bridges.push_back(make_pair(min(u,v),max(u,v)));
		}
	}
	sort(bridges.begin(),bridges.end());
	cout<<bridges.size()<<endl;
	for(int i = 0; i < bridges.size(); i++){
		cout<<bridges[i].first<<" " <<bridges[i].second<<endl;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}