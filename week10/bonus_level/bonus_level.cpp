#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;
int dp(vector<vector<int> > & shelves, vector<vector<int> > & memodown, vector<vector<int> > & memoup, int i, int j, bool isRet){
	if(i >= shelves.size()) return 0;
	if(j >= shelves.size()) return 0;
	if(i < 0) return 0;
	if(j < 0) return 0;
	int curr = shelves[i][j];
	shelves[i][j] = 0;
	int val;
	if(!isRet){
		if(memodown[i][j] == -1){
			if(i == shelves.size()-1 && j == shelves.size()-1){
				 val = dp(shelves,memodown,memoup,i,j,true);
			}else{
				 val = std::max(curr+dp(shelves,memodown,memoup,i,j+1,false),curr+dp(shelves,memodown,memoup,i+1,j,false));
				}
		}
		memodown[i][j] = val;
	
	}else{
		if(memoup[i][j] == -1){
			if(i == 0 && j == 0){
				return shelves[i][j]; //guaranteed to be 0
			} 
			 val = std::max(curr+dp(shelves,memodown,memoup,i-1,j,true),curr+dp(shelves,memodown,memoup,i,j-1,true));
		}
		memoup[i][j] = val;
	
	}
	shelves[i][j] = curr;
	if(!isRet) return memodown[i][j];
	else return memoup[i][j];
}
void do_calc(){
	int n;
	cin>>n;
	vector<vector<int> > shelves(n,vector<int>(n,0) );
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>shelves[i][j];
		}
	}
	vector<vector<int> > memodown(n,vector<int>(n,-1));
	vector<vector<int> > memoup(n,vector<int>(n,-1));
	
	int sol = dp(shelves,memodown,memoup,0,0,false);
	cout<<sol<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}