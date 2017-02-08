#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

class Vertex{
public:
	int v;
	bool visited_odd_edges_odd_weight = false;
	bool visited_even_edges_odd_weight = false;
	bool visited_odd_edges_even_weight= false;
	bool visited_even_edges_even_weight = false;

	vector<pair<int,int> > edges;
};

class NextMove{
public:
	Vertex vertex;
	int sofar;
	int weight;
	NextMove(Vertex v, int w, int s){
		vertex = v;
		weight = w;
		sofar = s;
	}
	bool operator<(const NextMove & nm) const{
		return weight > nm.weight;
	}
	bool is_odd_weight(){
		return weight % 2 != 0;
	}
	bool is_odd_length(){
		return sofar % 2 != 0;
	}

};

void do_calc(){
	int n,m;
	cin>>n>>m;
	int s,t;
	cin>>s>>t;
	vector<Vertex> vertices(n);
	for(int i = 0; i < m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		vertices[u].edges.push_back(make_pair(v,w));
	}

	//total weight of shortest odd path (odd len and odd weight) from s to t
	//priority queue
	priority_queue<NextMove> pq;
	Vertex ve;
	ve.v = s;
	pq.push(NextMove(ve,0,0));
	int shortest_weight_sum = INT_MAX;
	while(!pq.empty()){
		NextMove cur_move = pq.top();
		pq.pop();
		if(cur_move.is_odd_weight()){
			if(cur_move.is_odd_length()){
				if(vertices[cur_move.vertex.v].visited_odd_edges_odd_weight){
					continue;
				}else{
					if(cur_move.vertex.v == t)
					{
						shortest_weight_sum = cur_move.weight;
						break;
					}
					vertices[cur_move.vertex.v].visited_odd_edges_odd_weight = true;
				}
			}else{
				//odd weight even len
				if(vertices[cur_move.vertex.v].visited_even_edges_odd_weight){
					continue; //already visited
				}else{
					vertices[cur_move.vertex.v].visited_even_edges_odd_weight = true;
				}
			}
		}else{
			//even weight
			if(cur_move.is_odd_length()){
				if(vertices[cur_move.vertex.v].visited_odd_edges_even_weight){
					continue;
				}else{
					vertices[cur_move.vertex.v].visited_odd_edges_even_weight = true;
				}
			}else{
				if(vertices[cur_move.vertex.v].visited_even_edges_even_weight){
					continue;
				}else{
					vertices[cur_move.vertex.v].visited_even_edges_even_weight = true;
				}
			}
		}
		//at this point we found edge that didnt visit in current config, visiti it
		vector<pair<int,int> > & edges = vertices[cur_move.vertex.v].edges;
		for(int i = 0; i < edges.size(); i++){
			Vertex vrt;
			vrt.v = edges[i].first;
			pq.push(NextMove(vrt,cur_move.weight+edges[i].second,cur_move.sofar+1));
		} 
	}
	if(shortest_weight_sum == INT_MAX){
		cout<<"no"<<endl;
	}else{
		cout<<shortest_weight_sum<<endl;
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}