#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int dp(int v, vector<vector<int> > & tree, vector<int> & memo){

	if(memo[v] == -1){
		int val1 = 0;
		for(int i = 0; i < tree[v].size();i++){
			val1 += dp(tree[v][i],tree,memo);
		}

		int val2;
		int maxval = -1;
		for(int i = 0; i < tree[v].size(); i++){
			int val = 0;
			for(int j = 0; j < tree[v].size(); j++){
				if(j != i){
					val += dp(tree[v][j],tree,memo);
				}
			}

			for(int j = 0; j < tree[tree[v][i]].size(); j++){
				val += dp(tree[tree[v][i]][j],tree,memo);
			}
			val += 1;
			maxval = std::max(maxval,val);
		}
		memo[v] = std::max(val1,maxval);
	}

	return memo[v];
}

void do_calc(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > tree(n);
	bool first = true;
	int root  = -1;
	for(int i = 0; i < m; i++){
		int s,t;
		cin>>s>>t;
		if(first){
			root = s;
			first = false;
		}
		//s -> t
		tree[s].push_back(t);
	}

	//now the d
	vector<int> memo1(n,-1);
	vector<int> memo2(n,0);
	for(int i = 0; i < n; i++){
		if(tree[i].size() == 0){
			//leaf
			memo1[i] = 0;//base case
		}
	}
	int sol = dp(root,tree,memo1);

	cout<<sol<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}