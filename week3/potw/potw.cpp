#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


bool cmp(const pair<int,int>& lhs,const pair<int,int>& rhs){
		return lhs.second < rhs.second;
	}

void clones(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int> > jedi(n);
	for(int i=0;i<n;i++){
		int f,t;
		cin >> f >> t;
		if(t < f){
			t += m;
		} 
		jedi[i] = make_pair(f,t);
	}
	sort(jedi.begin(),jedi.end(),cmp);
	int ct = 1;
	int idx = 0;
	int i = 0;
	while(i < n && jedi[idx].second - m < jedi[0].first){
		while(jedi[idx].second >= jedi[i].first){ 
			if(i == n){
				break;
			}
			i ++;
		}
		     
		idx = i;
		ct ++;
	}
	cout << ct - 1<< endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		clones();
	}
	return 0;
}
