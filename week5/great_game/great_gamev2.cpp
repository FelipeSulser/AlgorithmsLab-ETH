#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
int winning(int start, int n, int m, vector<vector<int> > & transitions,vector<int> & memo_max, vector<int> & memo_min);
int get_min(int start, int n, int m, vector<vector<int> > & transitions, vector<int> & memo_max, vector<int> & memo_min){
	if(start == n-1)return 0;

	if(memo_min[start] == -1){
		int best_so_far = INT_MAX;
		//for(int i = 0; i < transitions[start].size(); i++){
		for(vector<int>::iterator iter = transitions.at(start).begin(); iter != transitions.at(start).end(); ++iter){
			int poss_max = winning(*iter,n,m,transitions,memo_max,memo_min);
			best_so_far = std::min(best_so_far,poss_max);
		}
		memo_min[start] = best_so_far+1;
	}
	return memo_min[start];
}
int winning(int start, int n, int m, vector<vector<int> > & transitions,vector<int> & memo_max, vector<int> & memo_min){
	if(start == n-1) return 0;

	if(memo_max[start] == -1){
		int best_so_far = -1;
		for(vector<int>::iterator iter = transitions.at(start).begin(); iter != transitions.at(start).end(); ++iter){
			int poss_max = get_min(*iter,n,m,transitions,memo_max,memo_min);
			best_so_far = std::max(best_so_far,poss_max);
		}
		memo_max[start] = best_so_far +1;
	}
	return memo_max[start];
}
void do_calc(){
	int n; int m;
	cin>>n>>m;
	//n is num of table pos
	//m is num of transitions

	int r,b;
	cin>>r>>b;

	//r red b black from 1 to n-1
	r--;
	b--;

	vector<vector<int> > transitions(n,vector<int>());

	for(int i = 0; i < m; i++){
		//transitions
		int u,v;
		cin>>u>>v;
		u--;
		v--;

		transitions[u].push_back(v);
	}

	vector<int> memo_max(n,-1);
	vector<int> memo_min(n,-1);
	int sherlock = get_min(r,n,m,transitions,memo_max,memo_min);
	int watson = get_min(b,n,m,transitions,memo_max,memo_min);

	int min_sher = -1;
	int min_mor = -1;
	if(sherlock % 2 == 0){
		min_sher = ((sherlock - 2 ) /2) *4+4;
	}else{
		min_sher = ((sherlock - 1)/2)*4+1;
	}

	if(watson % 2 == 0){
		min_mor = ((watson-2)/2)*4+3;
	}else{
		min_mor = ((watson-1)/2)*4+2;
	}
	//cout<<min_sher<<" " <<min_mor<<endl;
	
	if(min_sher < min_mor) cout<<"0"<<endl;
	else cout<<"1"<<endl;
	return;

}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}