#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

bool dp(int x,int y,int i, int k, vector<int> & disks, vector<vector<int> > & memo)
{
	
	if(memo[x][y] != -1){
		if(memo[x][y] == 1)return false;
		else return true;
	}
	
	if(x == 0){
		int val = y+disks[x];
		if((val % k ) == (i % k)){
			return true;
		}else{
			return false;
		}
	}
	bool val1 = dp(x-1,y,i,k, disks,memo);
	bool val2 = dp(x-1,(y+disks[x])% k,i,k, disks,memo);
	bool res = val1 || val2;
	if(res)
	{
		memo[x][y] = 2;//true
	}else{
		memo[x][y] = 1;
	}
	return res;


}
void do_calc(){
	int n,i,k;
	cin>>n>>i>>k;
	vector<int> disks(n);
	for(int j = 0; j < n; j++){
		cin>>disks[j];
	}
	vector<vector<int> > memo(n,vector<int>(k,-1));
	bool sol = dp(n-1,0,i,k,disks,memo);
	if(sol)cout<<"yes"<<endl;
	else cout<<"no"<<endl;

}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}