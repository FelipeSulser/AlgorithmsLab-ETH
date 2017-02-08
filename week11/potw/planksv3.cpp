#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;


void back_track(int id, int ubound, vector<vector<int> > & F, vector<vector<int> > & assig, vector<int> & planks){
	if(id >= ubound){
		vector<int> tuple(4,0);
		for(int i = 0; i< 4; i++){
			for(int j = 0; j < assig[i].size(); j++){
				tuple[i] += planks[assig[i][j]];
			}
		}
		F.push_back(tuple);
		return;
	}
	for(int i = 0; i < 4; i++){
		assig[i].push_back(id);
		back_track(id+1,ubound,F,assig,planks);
		assig[i].pop_back();
	}
}

void do_calc(){
	int n;
	cin>>n;
	vector<int> lengths(n);
	for(int i = 0; i < n; i++){
		cin>>lengths[i];
	}

	int sum = 0;
	long long n_sol = 0;
	for(int i = 0; i < n; i++){
		sum+= lengths[i];
	}

	if(sum % 4 != 0){
		cout<<0<<endl;
		return;
	}
	
	vector<vector<int> > F1, assig(4);
	back_track(0,n/2,F1,assig,lengths);

	vector<vector<int> > F2,assig2(4);
	back_track(n/2,n,F2,assig2,lengths);

	std::sort(F2.begin(),F2.end());

	for(int idx = 0; idx < 4; idx++){
		vector<int> member = F1[idx];
		for(int i = 0; i < 4; i++){
			member[i] = sum/4 - member[i];
		}
		std::pair<vector<vector<int> > ::iterator,vector<vector<int> > ::iterator> bounds;
		bounds = std::equal_range(F2.begin(),F2.end(),member);
		long long counter = std::distance(bounds.first,bounds.second);
		n_sol += counter;

	}
	cout<<n_sol/24<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}