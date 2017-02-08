#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

void back_track(int id, int ubound, vector<vector<int> > & F1, vector<vector<int> > & curval,vector<int> & planks){
	if(id >= ubound){	
		vector<int> tuple(4,0);
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < curval[i].size(); j++){
				tuple[i]+=planks[curval[i][j]];
			}
		}
		F1.push_back(tuple);
		return;
	}
	for(int i = 0; i < 4; i++){
		curval[i].push_back(id);
		back_track(id+1,ubound,F1,curval,planks);
		curval[i].pop_back();
	}

}

void do_calc(){
	int n;
	cin>>n;
	vector<int> planks(n);
	long long n_sol = 0;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>planks[i];
	}

	for(int i = 0; i < n; i++){
		sum+=planks[i];
	}
	if(sum % 4 != 0){
		cout<<0<<endl;
		return;
	}
	//now do all possible subsums into 4 variables
	vector<vector<int> > F1;
	vector<vector<int> > F2;

	vector<vector<int> > curval(4);
	back_track(0,n/2,F1,curval, planks);

	vector<vector<int> >curval2(4);

	back_track(n/2,n,F2,curval2, planks);

	std::sort(F2.begin(),F2.end());

	for(int idx = 0; idx < F1.size(); idx++){
		vector<int> current = F1[idx];
		for(int i = 0; i < 4; i++){
			current[i] = sum/4 - current[i];// find same tuple in F1 now
		}
		std::pair<vector<vector<int> > ::iterator,vector<vector<int> > ::iterator> pq;
		pq = std::equal_range(F2.begin(), F2.end(),current);
		long long n_count = std::distance(pq.first,pq.second);
		n_sol+=n_count;
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