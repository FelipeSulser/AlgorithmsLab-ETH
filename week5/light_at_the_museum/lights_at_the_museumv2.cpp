#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;

vector<int> div_et_impera(vector<vector<int> > & possiblesolutions, int i, int j){
	if( i < j){
		int mid = (i+j)/2;
		vector<int> intersection;
		vector<int> first = div_et_impera(possiblesolutions,i,mid);
		vector<int> second = div_et_impera(possiblesolutions,mid+1,j);
		std::set_intersection(first.begin(),first.end(),
			second.begin(),second.end(),
			std::back_inserter(intersection));

		return intersection;
	}else{
		return possiblesolutions[i];
	}
}
void do_calc(){
	int n,m;
	cin>>n>>m;
	//N is number of switches
	//M number of rooms
	vector<int> numlights(m);
	for(int i = 0; i < m; i++){
		cin>>numlights[i];
	}

	vector<vector<int> > on(n,vector<int>(m,0));
	vector<vector<int> > off(n,vector<int>(m,0));
	vector<int> position(n, 0);//state of each switch
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>on[i][j];
			cin>>off[i][j];
		}
	}
	//now for each light, find valid solutions
	vector<vector<int> > possiblesolutions(m);
	vector<pair<int,vector<int> > > solset(m);
	for(int i = 0; i < m; i++){
		//generate a state of switches
		int perm = 0;
		for(; perm < pow(2,n); perm++){
			int target = numlights[i];
			
			//check if solves current room
			for(int j = 0; j < n; j++){
				
				if((perm & 1 << j) != 0){
					target -= off[j][i];
				}else{
					target -= on[j][i];
				}
			}
			
			if(target == 0){
				possiblesolutions[i].push_back(perm);
				
			} 
		}
	}
	
	vector<int> possible = div_et_impera(possiblesolutions,0,m-1);
	//these are the possible sets
	int minval = INT_MAX;
	for(int i = 0; i < possible.size(); i++){
		int current = possible[i];
		int ones = 0;
		for(int j = 0; j < n; j++){
			if((current & 1 << j) != 0)ones++;
		}
		minval = std::min(ones,minval);
	}
	if(possible.size() <= 0){
		cout<<"impossible"<<endl;
	}else{
		cout<<minval<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}