#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int mydp(int d, int r1, int r2,vector<vector<vector<int> > > & memo, vector<vector<int> > & shelves, int n){
	cout<<d<<" " <<r1 <<" " <<r2<<endl;
	if(memo[d][r1][r2] == -1){
		
		int coincount = 0;
		int x1 ,x2;
		x1 = d-r1;
		x2 = d-r2;
		if(r1 != r2) coincount = shelves[d][x1] + shelves[d][x2];
		else coincount = shelves[d][x1]; //only one
		int maxval = -1;
		int currval = coincount + mydp(d+1,r1,r2,memo,shelves,n);
		maxval = std::max(maxval,currval);
		if(r1 < n-1){
			currval = coincount + mydp(d+1,r1+1,r2,memo,shelves,n);
			maxval =  std::max(maxval,currval);
		}
		if(r2 < n-1){
			currval =coincount+ mydp(d+1,r1,r2+1,memo,shelves,n);
			maxval = std::max(maxval,currval);
		}
		if(r1 < n-1 && r2 < n-1){
			currval = coincount+ mydp(d+1,r1+1,r2+1,memo,shelves,n);
			maxval = std::max(maxval,currval);
		}
		memo[d][r1][r2] = maxval;
	}
	return memo[d][r1][r2];
}

void do_calc(){
	int n;
	cin>>n;

	vector<vector<int> > table(n,vector<int>(n,0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>table[i][j];
		}
	}	
	vector<vector<vector<int> > > memo(2*n-1,
		vector<vector<int> > (n,
		vector<int>(n,-1)));
	cout<<"base case: "<<2*n-1<<" " <<n-1<<" "<<n-1<<endl;
	cout<<"size: "<<n<<endl;
	memo[2*n-2][n-1][n-1] = 0;
	//now that we have the table, do a dp doing both paths at the same time
	int maxcoins = mydp(0,0,0,memo,table,n);
	cout<<maxcoins<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}