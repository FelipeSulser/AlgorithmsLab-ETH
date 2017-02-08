#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int dp(int vol, int i, vector<int> & cost, vector<int> & volume,vector<vector<int> > & memo){
	//cout<<vol<<" " <<i<<endl;
	if(i < 0 && vol > 0 ){
		
		return INT_MAX/2;
	} 
	if(i < 0){
		return 0;
	} 
	if(vol <= 0){
		return 0;
	} 
	if(memo[vol][i] == -1){

		int remainvol = vol;
		int it = 0;
		int itcost = 0;
		int val;
		int minval = INT_MAX;
		
		while(remainvol > 0){
			remainvol -= volume[i];
			itcost += cost[i];
			
			val = itcost + dp(remainvol,i-1,cost,volume,memo);
			//if(val > 0)
			if(val < minval){
				minval = val;

			}
			it++;
		}
		
		int val2 = dp(vol,i-1,cost,volume,memo);
		if(minval <= val2){
			memo[vol][i] = minval;
		}else{
			memo[vol][i] = val2;
			
		}
	}

	return memo[vol][i];
}
void do_calc(){
	int n,k;
	cin>>n>>k;
	vector<int> cost(n);
	vector<int> volume(n);
	for(int i = 0; i < n; i++){
		cin>>cost[i]>>volume[i];
	}

	//we need at least k
	
	vector<vector<int> > memo (k+1,vector<int>(n,-1));
	int sol = dp(k,n-1,cost,volume,memo);

	int i,j;
	i = j = 0;
	while(!(i == k && j == n-1){

		if(j > 0){
			if
		}
	}

	
	cout<<sol<<" " <<0<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}