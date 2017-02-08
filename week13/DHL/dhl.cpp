#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;


long long dp(int n, vector<int> & A, vector<int> & B){
	vector<vector<long long> > memo(n+1,vector<long long>(n+1,0));
	//too big, reduce size of table
	

	memo[0][0] = 0;
	for(int x = 1; x <= n; x++){
		memo[x][0] = INT_MAX/2;
		memo[0][x] = INT_MAX/2;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){

			long long minima = INT_MAX/2;
			long long sumx = 0;
			
			for(int x = 1; x <= i ; x++){
				sumx += A[i-x];

				long long sumy = 0;
				for(int y = 1; y <= j; y++){
					sumy += B[j-y];
					int costx = sumx - x;
					int costy = sumy - y;

					int totalcost = costx*costy;
					long long valtable = memo[i-x][j-y];
					long long sum = totalcost + valtable;
					
					if(sum > INT_MAX/2) continue;
					if(sum < minima){
						minima =sum;
					}

				}
			}
			memo[i][j] = minima;
		}
	}

	
	return memo[n][n];
}
void do_calc(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i = 0; i < n; i++){
		cin>>A[i];
	}

	vector<int> B(n);
	for(int i = 0; i < n; i++){
		cin>>B[i];
	}

	//long long sol = memoized(memo,n,n,n,A,B,accum_a,accum_b);
	long long sol = dp(n,A,B);
	cout<<sol<<endl;

}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}