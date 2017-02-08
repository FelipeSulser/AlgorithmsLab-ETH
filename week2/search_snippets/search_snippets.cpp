#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <climits>

using namespace std;

class PairCompare{
public:
	bool operator()(pair<int,int> & l, pair<int,int> & r){
		return l.first > r.first;
	}
};

void do_calc(){
	int N;
	cin>>N;
	vector<int> occurences(N);
	for(int i = 0; i < N; i++){
		cin>>occurences[i];
	}
	priority_queue<pair<int,int>,vector<pair<int,int> > , PairCompare> locations;
	for(int index = 0; index < N; index++){
		for(int i = 0; i < occurences[index]; i++)
		{
			int loc;
			cin>>loc;
			locations.push(make_pair(loc,index));
		}
	}

	vector<int> first_set_loc(N,-1);
	set<pair<int,int> > words;
	int words_found = 0;
	int last_loc = INT_MIN;
	while(!locations.empty() && words_found != N){
		pair<int,int> current = locations.top();
		locations.pop();
		if(first_set_loc.at(current.second) == -1){
			words_found++;
		}else{
			words.erase(make_pair(first_set_loc.at(current.second),current.second));
		}
		first_set_loc.at(current.second) = current.first;
		words.insert(current);
		last_loc = current.first;
	}

	int min_dist = last_loc-words.begin()->first;

	while(!locations.empty()){
		pair<int,int> cur = locations.top();
		locations.pop();

		words.erase(make_pair(first_set_loc.at(cur.second),cur.second));
		words.insert(cur);
		first_set_loc.at(cur.second) = cur.first;

		int d = cur.first - words.begin()->first;
		min_dist = min(min_dist,d);
	}

	cout<<min_dist +1<<endl;
}

bool all_set(int bitset, int N){
	int target = pow(2,N)-1;
	if(bitset == target) return true;
	else return false;
}

int set_val(int bitset, int bit){
	int x = bitset;
	x|= 1 << bit;
	return x;
}

bool is_set(int bitset, int bit){
	return (bitset & 1 << bit) != 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) do_calc();
	return 0;
}