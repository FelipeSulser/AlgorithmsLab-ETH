#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int invest(int i, int j, bool turn, vector<int> & coins, vector<vector<int> > & memo, int n){
	if(i > n-1)return 0;
	if(j < 0) return 0;

	if(i > j){
		memo[i][j]= 0;
		return 0;
	}
	if(memo[i][j] == -1){
		if(turn){
			int val = max(coins[i]+invest(i+1,j,false,coins,memo,n),coins[j]+invest(i,j-1,false,coins,memo,n));
		}else{
			int val = min(invest(i+1,j,true,coins,memo,n), invest(i,j-1,true,coins,memo,n));
			memo[i][j] = val;
			return val;
		}
	}else{
		return memo[i][j];
	}
}

void do_calc(){
	int n;
	cin>>n;
	vector<int> coins(n);
	for(int i = 0; i < n; i++){
		cin>>coins[i];
	}

	vector<vector<int> > memo(n,vector<int>(n,-1));
	int max_ret = invest(0,n-1,true,coins,memo,n);

	cout<<max_ret<<endl;
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();

	return 0;
}