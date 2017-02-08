#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int memoize(int n, vector<int> & size, vector<vector<int> > & chips,vector<vector<vector<vector<vector<int> > > > > & memo){
	if(memo[size[0]][size[1]][size[2]][size[3]][size[4]] == -1){
		//create a permutation and check if its a valid one
		int perm = 1;
		int max = 32;
		int max_val = INT_MIN;
		for(perm = 1; perm < 32; perm++){
			int chipstaken = 0;
			int color = -1;
			bool isValid = true;
			vector<int> changed_quant(5,0);
			for(int i = 0; i<  5; i++){
				if((perm & 1 << i) != 0){
					if(size[i] == 0){
						isValid = false;
						break;
					}
					if(color == -1){
						color = chips[i][size[i]-1];
						chipstaken++;
					}else{
						chipstaken++;
						if(color != chips[i][size[i]-1]){
						isValid = false;
						break;
						}
					}
					changed_quant[i] = size[i]-1;
				}else{
					changed_quant[i] = size[i];
				}
			}
			if(isValid){
				//this could be 
				int cost = 0;
				if(chipstaken > 1){
					cost = pow(2,chipstaken-2);
				}else{
					cost = 0;
				}
				int val = cost+memoize(n,changed_quant,chips,memo);
				max_val = std::max(max_val,val);

			}
		}
		memo[size[0]][size[1]][size[2]][size[3]][size[4]] = max_val;
	}


	return memo[size[0]][size[1]][size[2]][size[3]][size[4]];
}

void do_calc(){
	int n;
	cin>>n;
	//n is number of stacks
	vector<int> size_stacks(5,0);
	for(int i = 0; i < n; i++){
		cin>>size_stacks[i];
	}
	vector<vector<int> > chips(5,vector<int>());
	for(int i = 0; i < n; i++){
		for(int j = 0; j < size_stacks[i]; j++){
			int val;
			cin>>val;
			chips[i].push_back(val);
		}
	}

	//memoized
	//for size of stack
	vector<vector<vector<vector<vector<int> > > > > table(size_stacks[0]+1,
		vector<vector<vector<vector<int> > > >(size_stacks[1]+1,
			vector<vector<vector<int> > > (size_stacks[2]+1,
				vector<vector<int> > (size_stacks[3]+1,
					vector<int>(size_stacks[4]+1,-1)))));
	table[0][0][0][0][0] = 0; // initial
	int val = memoize(n,size_stacks,chips,table);

	cout<<val<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}