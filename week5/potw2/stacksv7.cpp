#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int dp(vector<vector<vector<vector<vector<int> > > > > & memo, vector<int> & size, vector<vector<int> > & chips){

	if(memo[size[0]][size[1]][size[2]][size[3]][size[4]] == -1){
		//generate a permutation that represents the coins taken from each stack
		int perm = 1;
		int maxval = -1;
		for(; perm < 32; perm++){
			bool isValid = true;
			vector<int> newsizes(5,0);
			int color = -1;
			int numtaken = 0;
			for(int i = 0; i < 5; i++){
				if((perm & 1 <<i) != 0){
					//means we take it
					if(size[i] <= 0){
						isValid = false;
						break;
					}
					if(color == -1){
						color = chips[i][size[i]-1];
						//numtaken++;
					}else{
						if(color != chips[i][size[i]-1]){
							isValid = false;
							break;
						}
					}

					numtaken++;
					newsizes[i] = size[i]-1;
				}else{
					newsizes[i] = size[i];
				}
			}
			if(isValid){
				//we do the dp
				int winval = 0;
				if(numtaken > 1){
					winval = pow(2,numtaken-2);
				}else{
					winval = 0;
				}
				int value = winval + dp(memo,newsizes,chips);
				maxval = std::max(maxval,value);
			}
		}
		memo[size[0]][size[1]][size[2]][size[3]][size[4]] = maxval;
	}


	return memo[size[0]][size[1]][size[2]][size[3]][size[4]];
}

void do_calc(){
	int n;
	cin>>n;
	//n is number of stacks --> 1...5

	vector<int> size(5,0);
	for(int i = 0; i < n; i++){
		cin>>size[i];
	}
	vector<vector<int> > chips(n);
	for(int i = 0; i < n; i++){
		vector<int> stack_i;
		for(int j = 0; j < size[i]; j++){
			int val;
			cin>>val;
			stack_i.push_back(val);
		}
		chips[i] = stack_i;
	}

	//now do a lil dp
	vector<vector<vector<vector<vector<int> > > > > memo(size[0]+1,
		vector<vector<vector<vector<int> > > >(size[1]+1,
			vector<vector<vector<int> > > (size[2]+1,
				vector<vector<int> >(size[3]+1,
					vector<int>(size[4]+1,-1)))));
	memo[0][0][0][0][0] = 0;

	int val = dp(memo,size,chips);

	cout<<val<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}