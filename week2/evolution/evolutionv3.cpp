#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int binsearch(int maxage, vector<int> & path, vector<int> & age){
	int lmin = 0;
	int lmax = path.size()-1;
	while(lmin <lmax){
		int mid = (lmin+lmax)/2;
		if(age[path[mid]] > maxage){
			lmin = mid+1;
		}else{
			lmax = mid;
		}
	}
	return path[lmin];
}
void dfs(int node, vector<vector<int> > & ancestors, vector<int> & path, vector<vector<pair<int,int> > > & query, vector<int> & result, vector<int> & age){
	//for current node, for each ancestor do a query
	for(int i = 0; i < query[node].size(); i++){
		result[query[node][i].second] = binsearch(query[node][i].first,path,age);
	}

	//now do dfs
	for(int i = 0; i < ancestors[node].size(); i++){
		int u = ancestors[node][i];
		//add to path and traverse
		path.push_back(u);
		dfs(u,ancestors,path,query,result,age);
	}
	path.pop_back();
}

void do_calc(){
	int n,q;
	cin>>n>>q;
	vector<string> species(n);
	vector<int> age(n);
	map<string,int> assig;
	for(int i = 0; i < n; i++){
		string name;
		int age_i;
		cin>>name>>age_i;
		species[i] = name;
		age[i] = age_i;
		assig[name] = i;
	}
	vector<vector<int> > ancestors(n);
	for(int i = 0; i < n-1; i++){
		string s1,s2;
		cin>>s1>>s2;
		ancestors[assig[s2]].push_back(assig[s1]);

	}
	int root = max_element(age.begin(),age.end())-age.begin();
	vector<vector<pair<int,int> > > query(n); 
	for(int i = 0; i < q; i++){
		string name;
		int age;
		cin>>name>>age;
		query[assig[name]].push_back(make_pair(age,i));

	}

	vector<int> path;
	path.push_back(root);
	vector<int> result(q);
	dfs(root,ancestors,path,query,result,age);
	for(int i = 0; i < q; i++){
		cout<<species[result[i]];
		if(i < q-1) cout<<" ";
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}