#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

class Center{
public:
	vector<int> sup;
	map<int,map<int,int> > extsup;
	map<int,int> bestmap;
	Center(){}

	Center(int n){
		sup = vector<int>(n,0);
	}
};

int best(vector<Center> & centers, int c, int s, int mask){
	auto bestit = centers[c].bestmap.find(mask);
	if(bestit != centers[c].bestmap.end()){
		return (*bestit).second;
	}
	int max = 0;
	for(int i = 0; i < (0x1<<s); i++){
		if((i & mask) != 0){
			continue;
		}
		bool valid = true;
		for(int j = 0; j < s && valid; j++){
			if((i & (0x1<<j)) && ((i& centers[c].sup[j]) != 0)){
				valid = false;
			}
		}
		if(!valid) continue;

		int count = 0;
		for(int j = 0; j < s; j++){
			if(i & (0x1 << j)){
				count++;
			}
		}
		for(auto& esup: centers[c].extsup){
			int nmask = 0;
			for(auto& p : esup.second){
				if(i & (0x1 << p.first)){
					nmask |= p.second;
				}
			}
			count += best(centers,esup.first,s,nmask);
		}
		max = std::max(max,count);
	}
	centers[c].bestmap[mask] = max;
	return max;
}
void do_calc(){
	int k,s,m;
	cin>>k>>s>>m;
	vector<Center> centers(k,Center(s));
	for(int i = 0; i < m; i++){
		int u,v,h;
		cin>>u>>v>>h;

		if(u == v){
			for(int j = 0; j < h; j++){
				int x,y;
				cin>>x>>y;
				centers[u].sup[x] |= 0x1 << y; //set y-th bit to 1, in center u, x is supervised

			}
		}else{
			map<int,int> esup;
			for(int j = 0; j < h; j++){
				int x,y;
				cin>>x>>y;
				esup[x] |= 0x1<<y;
			}
			centers[u].extsup[v] = esup;
		}
	}
	cout<<best(centers,0,s,0)<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)do_calc();

	return 0;
}