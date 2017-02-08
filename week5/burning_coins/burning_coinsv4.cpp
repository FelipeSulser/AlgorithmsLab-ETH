#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int dp(int i, int j, bool turn, vector<int> & coins, vector<vector<int> > & memo, int n){
	if(i > n-1) return 0;
	if(j < 0) return 0;

	if(memo[i][j] == -1){
		if(turn){
			int val = max(coins[i]+dp(i+1,j,false,coins,memo,n),coins[j]+dp(i,j-1,false,coins,memo,n));
			memo[i][j] = val;
		}else{
			int val = min(dp(i+1,j,true,coins,memo,n),dp(i,j-1,true,coins,memo,n));
			memo[i][j] = val;
		}
	}

	return memo[i][j];
}
void do_calc(){
	int N;
	cin>>N;
	//N is number of coins

	vector<int> coins(N);
	for(int i = 0; i < N; i++){
		cin>>coins[i];
	}
	vector<vector<int> > memo(N,vector<int>(N,-1));
	for(int i = 0; i < N; i++){
		for(int j = 0; j <i; j++){
			memo[i][j] = 0;
		}
	}
	int maxguarantee = dp(0,N-1,true,coins,memo,N);
	cout<<maxguarantee<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}