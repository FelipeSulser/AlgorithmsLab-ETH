#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int dp(int n, vector<int> & size,vector<vector<int> >& stack, vector<vector<vector<vector<vector<int> > > > > & memo){
	if(memo[size[0]][size[1]][size[2]][size[3]][size[4]] == -1){
		int perm = 1;
		int max_value = INT_MIN;
		for(int perm = 1; perm < 32; perm++){
			bool isValid = true;
			int chipstaken = 0;
			int color = -1;
			bool first = true;

			vector<int> newsize(5);
			for(int i = 0; i < 5; i++){
				if((perm & 1 << i ) != 0){
					if(size[i] == 0){
						isValid = false;
						break;
					}
					if(color == -1){
						color = stack[i][size[i]-1];

					}else{
						if(color != stack[i][size[i]-1]){
							isValid = false;
							break;
						}
					}
					chipstaken++;
					newsize[i] = size[i]-1;
					
				}else{
					newsize[i] = size[i];
				}

			}
			if(isValid){
				int score = 0;
				if(chipstaken <= 1){
					score = 0;
				}else{
					score = std::pow(2,chipstaken-2);
				}
				int val = score+dp(n,newsize,stack,memo);
				max_value = std::max(val,max_value);
					
			}
		}
		memo[size[0]][size[1]][size[2]][size[3]][size[4]] = max_value;
	}
	return memo[size[0]][size[1]][size[2]][size[3]][size[4]];
}
void do_calc(){
	int n;
	cin>>n;
	vector<int> size_stack(5,0);
	for(int i = 0; i < n; i++){
		cin>>size_stack[i];
	}
	vector<vector<int> > stack(5,vector<int>());
	for(int i = 0; i < n; i++){
		vector<int> ith(size_stack[i]);
		for(int j = 0; j < size_stack[i]; j++){
			cin>>ith[j];
		}
		stack[i] = ith;
	}


	//memoize
	vector<vector<vector<vector<vector<int> > > > >memo(size_stack[0]+1,
		vector<vector<vector<vector<int> > > >(size_stack[1]+1,
			vector<vector<vector<int> > > (size_stack[2]+1,
				vector<vector<int> > (size_stack[3]+1,
					vector<int>(size_stack[4]+1,-1)))));
	memo[0][0][0][0][0] = 0;

	int sol = dp(n,size_stack,stack,memo);
	cout<<sol<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
}