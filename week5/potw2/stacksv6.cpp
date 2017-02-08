#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int dp(vector<int> & numchips, vector<vector<int> > & chips, vector<vector<vector<vector<vector<int> > > > > & memo){
	if(memo[numchips[0]][numchips[1]][numchips[2]][numchips[3]][numchips[4]] == -1){
		int perm;
		int maxval = -1;
		for(perm = 1; perm < 32; perm++){
			//for this permutation check bits
			vector<int> newnumchips(5);
			bool isValid = true;
			int numtaken = 0;
			int color = -1;
			for(int i = 0; i < 5; i++){
				if((perm & 1 << i) != 0){
					if(numchips[i] == 0){
						isValid = false;
						break;
					}
					if(color == -1){
						color = chips[i][numchips[i]-1];

					}else{
						if(color != chips[i][numchips[i]-1]){
							isValid = false;
							break;
						}
					}
					numtaken++;
					newnumchips[i] = numchips[i]-1;

				}else{
					newnumchips[i] = numchips[i];
				}
			}
			if(isValid){
				int score;
				if(numtaken > 1){
					score = pow(2,numtaken-2);
				}else{
					score = 0;
				}
				int sol = score + dp(newnumchips,chips,memo);
				maxval = std::max(maxval,sol);
			}
		}
		memo[numchips[0]][numchips[1]][numchips[2]][numchips[3]][numchips[4]] = maxval;
	}


	return memo[numchips[0]][numchips[1]][numchips[2]][numchips[3]][numchips[4]];
}

void do_calc(){
	int n;
	cin>>n;
	vector<int> numchips(5,0);
	for(int i = 0; i < n; i++){
		cin>>numchips[i];
	}

	vector<vector<int> > chips(5,vector<int>());
	for(int i = 0; i < n; i++){
		vector<int> stacki(numchips[i]);
		for(int j = 0; j < numchips[i]; j++){
			cin>>stacki[j];
		}
		chips[i] = stacki;
	}

	vector<vector<vector<vector<vector<int> > > > >memo(numchips[0]+1,
		vector<vector<vector<vector<int> > > > (numchips[1]+1,
			vector<vector<vector<int> > > (numchips[2]+1,
				vector<vector<int> > (numchips[3]+1,
					vector<int> (numchips[4]+1,-1)))));
	memo[0][0][0][0][0] = 0;
	int sol = dp(numchips,chips,memo);
	cout<<sol<<endl;


	//do a lil dp programming with 5 
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}