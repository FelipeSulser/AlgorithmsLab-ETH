#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int backtrack(int posini, int posend, vector<int> & values, int n, bool myturn, vector<vector<int> > & memo){
	if(posini > n-1)return 0;
	if(posend < 0) return 0;
	if(posini > posend){
		memo[posini][posend] = 0;
		return 0;
	}
	if(memo[posini][posend] != -1){
		return memo[posini][posend];
	}
	if(myturn){
		int ret = std::max(values[posini]+backtrack(posini+1,posend,values,n,false,memo),values[posend]+backtrack(posini,posend-1,values,n,false,memo));
		memo[posini][posend] = ret;
		return ret;
	}else{
		int ret = std::min(backtrack(posini+1,posend,values,n,true,memo),backtrack(posini,posend-1,values,n,true,memo));
		memo[posini][posend] = ret;
		return ret;
	}
	return -1;
}
void do_calc(){
	int n;
	cin>>n;
	vector<int> values(n);
	for(int i = 0; i < n; i++){
		cin>>values[i];
	}

	//largest amount guaranteed to win
	int posini = 0;
	int posend = n-1;
	vector<vector<int > > memo(n,vector<int>(n,-1));
	int val = backtrack(posini,posend,values,n,true,memo);
	cout<<val<<endl;

}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}