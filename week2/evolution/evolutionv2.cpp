#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int binary_search(int b, vector<int> & path, vector<int> & age){
	//max age without tipping point 
	int lmin = 0;
	int lmax = path.size()-1;
	while(lmin < lmax){
		int d = (lmin+lmax)/2;
		if(age[path[d]] > b){
			//gotta go to the left
			lmin = d+1;
		}else{
			lmax = d;
		}
	}
	return path[lmin];
}
void dfs(int node, vector<vector<int> > & tree, vector<int> & path, vector<vector<pair<int,int> > > & query, vector<int> & result, vector<int> & age){
	for(int i = 0; i < query[node].size(); i++){
		result[query[node][i].second] = binary_search(query[node][i].first,path,age);//for current path
	}

	for(int i = 0; i < tree[node].size(); i++){
		int v = tree[node][i];
		path.push_back(v);
		dfs(v,tree,path,query,result,age);
	}
	path.pop_back();
}
void do_calc(){
	int num_species, num_queries;
	cin>>num_species>>num_queries;

	map<string,int> mapping;
	vector<string> names(num_species);
	vector<int> age_specie(num_species);
	for(int i = 0; i < num_species; i++){
		string name;
		cin>>name;
		int age;
		cin>>age;
		mapping[name] = i;
		names[i] = name;
		age_specie[i] = age;
	}

	vector<vector<int> > paths(num_species);
	for(int i = 0; i < num_species-1; i++){
		//here we construct the path
		string child;
		string father;
		cin>>child>>father;
		paths[mapping[father]].push_back(mapping[child]); // the first
	}
	int root = max_element(age_specie.begin(),age_specie.end()) - age_specie.begin();
	vector<vector<pair<int,int> > > queries(num_species);
	//now for the queries
	for(int i = 0; i < num_queries; i++){
		string name;
		cin>>name;
		int max_age;
		cin>>max_age;

		queries[mapping[name]].push_back(make_pair(max_age,i)); // there is a query for name up to max age 
	}
	vector<int>path;
	vector<int> result(num_queries);
	path.push_back(root); // always included
	dfs(root,paths,path,queries,result,age_specie);

	for(int i = 0; i < num_queries; i++){
		cout<<names[result[i]];
		if(i < num_queries-1) cout<<" ";
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