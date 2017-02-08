#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int earnings(int i, int j, vector<int> & val, vector<vector<int> > & memo, int n, bool  myturn){
	if(i > n-1) return 0;
	if(j < 0) return 0;
	if(i > j){
		memo[i][j] = 0;
		return 0;
	}
	
	if(memo[i][j] != -1){
		return memo[i][j];
	}

	if(myturn){
		int ret = max(val[i]+earnings(i+1,j,val,memo,n,false), val[j]+earnings(i,j-1,val,memo,n,false));
		memo[i][j] = ret;
		return ret;
	}else{
		int ret = min(earnings(i+1,j,val,memo,n,true),earnings(i,j-1,val,memo,n,true));
		memo[i][j] = ret;
		return ret;
	}
	return -1;
}
void do_calc(){
	int n;
	cin>>n;
	vector<int> val(n);
	for(int i = 0; i < n; i++){
		cin>>val[i];
	}
	vector<vector<int> > memo(n, vector<int>(n,-1));
	int winning = earnings(0, n-1, val, memo, n, true);
	cout<<winning<<endl;
	return ;


}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}