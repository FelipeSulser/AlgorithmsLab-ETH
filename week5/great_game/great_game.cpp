#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int get_min(int pos, vector<vector<int> > & jumps, int n, vector<int> & memo);
int get_max(int pos, vector<vector<int> > & jumps, int n, vector<int> & memo){
	if(pos == n-1){
		return 0;
	}

	if(memo[pos] == -1){
		int max_val = INT_MIN;
		for(int i = 0; i < jumps[pos].size(); i++){
			int poss_max = get_min(jumps[pos][i],jumps,n,memo);
			max_val = max(max_val, poss_max);
		}
		memo[pos] = max_val;

	}

	return memo[pos];
}

int get_min(int pos, vector<vector<int> > & jumps, int n, vector<int> & memo){
	if(pos == n-1) return 0; //end case

	if(memo[pos] == -1){
		int min_val = INT_MAX;
		for(int i = 0; i <  jumps[pos].size(); i++){
			int poss_min = get_max(jumps[pos][i],jumps,n,memo); // i jumped

			min_val = min(min_val,poss_min);
		}
		memo[pos] = min_val+1;
	}



	return memo[pos];
}

void do_calc(){
	int n,m;
	cin>>n>>m;

	//n is number of pos and m transitions
	int r,b;
	//r start red b start black
	cin>>r>>b;
	r--;
	b--;
	vector<vector<int> > jumps(n);
	vector<int> from(m);
	vector<int> to(m);
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		jumps[u].push_back(v);
		from[i] = u;
		to[i] = v;
	}

	//holmes is red starting
	int iter = 0;

	//0 is red 1 is black
	vector<int> memored(n,-1);
	vector<int> memoblack(n,-1);

	int min_steps_red  = get_min(r,jumps,n,memored);
	int min_steps_black = get_min(b,jumps,n,memoblack);

	int sherlock = 0;
	int moriarty = 0;
	if(min_steps_red % 2 == 0){
		sherlock = ((min_steps_red-2)/2)*4+4;
	}else{
		sherlock = ((min_steps_red-1) / 2)*4+1;
	}

	if(min_steps_black % 2 == 0){
		moriarty = ((min_steps_black-2)/2)*4+3;
	}
	else{
		moriarty = ((min_steps_black-1)/2)*4+2;
	}

	if(sherlock < moriarty){
		cout<<"0"<<endl;
	}else{
		cout<<"1"<<endl;
	}
	//cout<<min_steps_black<<" " <<min_steps_red<<endl;


}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();

	return 0;
}