#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int dp(int n, vector<int> & cap, vector<vector<int> > & chips, vector<vector<vector<vector<vector<int> > > > > & memo){
	if(memo[cap[0]][cap[1]][cap[2]][cap[3]][cap[4]] == -1){
		//permutation that is valid
		int bestsol = INT_MIN;
		for(int perm = 1; perm < 32; perm++){
			bool isValid = true;
			int chipstaken = 0;
			int color = -1;
			vector<int> newsize(5);
			for(int i = 0; i < 5; i++){
				if((perm & 1 << i ) != 0){
					if(cap[i] == 0){
						isValid = false;
						break;
					}
					if(color == -1){
						color = chips[i][cap[i]-1];
						
					}else{
						if(color != chips[i][cap[i]-1]){
							isValid = false;
							break;
						}
					}
					chipstaken++;
					newsize[i] = cap[i]-1; // took one
				}else{
					newsize[i] = cap[i];
				}
			}
			if(isValid){
				int score = 0;
				if(chipstaken <= 1){
					score = 0;
				}else{
					score = std::pow(2,chipstaken-2);

				}
				int val = score + dp(n,newsize,chips,memo);
				bestsol = std::max(val,bestsol);
			}
		}
		memo[cap[0]][cap[1]][cap[2]][cap[3]][cap[4]] = bestsol;
	}

	return memo[cap[0]][cap[1]][cap[2]][cap[3]][cap[4]];
}
void do_calc(){
	int n; 
	cin>>n;
	vector<int> capacity(5,0);
	for(int i = 0; i < n; i++){
		cin>>capacity[i];
	}
	vector<vector<int> > chips(5,vector<int>());
	for(int i = 0; i < n; i++){
		vector<int> stack_i(capacity[i]);
		for(int j = 0; j < capacity[i]; j++){
			cin>>stack_i[j];
		}
		chips[i] = stack_i;
	}

	//do a lil memoized approach
	vector<vector<vector<vector<vector<int> > > > > memo(capacity[0]+1,
		vector<vector<vector<vector<int> > > >(capacity[1]+1,
			vector<vector<vector<int> > > (capacity[2]+1,
				vector<vector<int> >(capacity[3]+1,
					vector<int>(capacity[4]+1,-1)))));
	memo[0][0][0][0][0] = 0;
	int sol = dp(n,capacity,chips,memo);

	cout<<sol<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}