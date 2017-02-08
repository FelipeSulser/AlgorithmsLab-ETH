#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void back_track(int current, int max, vector<vector<int> > & F1, vector<vector<int> > & assig, vector<int> & planks){
	if(current >= max){
		//return current
		vector<int> tuple(4,0);
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < assig[i].size(); j++){
				tuple[i] += planks[assig[i][j]];
			}
		}
		F1.push_back(tuple);
		return;
	}
	for(int i = 0; i < 4; i++){
		assig[i].push_back(current); // add to 4 sets
		back_track(current+1,max,F1,assig,planks);
		assig[i].pop_back();
	}
}
void do_calc(){
	int n;
	cin>>n;

	vector<int> planks(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>planks[i];
		sum+= planks[i];
	}

	//now do it
	if(sum % 4 != 0){
		cout<<0<<endl;
		return;
	}	
	long long n_sol = 0;

	vector<vector<int> > F1;
	vector<vector<int> > assig(4);
	back_track(0,n/2,F1,assig,planks);

	vector<vector<int> > F2;
	vector<vector<int> > assig2(4);
	back_track(n/2,n,F2,assig2,planks);

	std::sort(F2.begin(),F2.end());
	//now iterate over it
	for(int i = 0; i < F1.size(); i++){
		//target is vec

		vector<int> target = F1[i];
		for(int j = 0; j < 4; j++){
			target[j] = sum/4 - target[j];
		}	
		pair<vector<vector<int> > ::iterator,vector<vector<int> > :: iterator> ranges;
		ranges = std::equal_range(F2.begin(),F2.end(),target);
		int dist = std::distance(ranges.first,ranges.second);
		n_sol += dist;
		//see how many hits
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