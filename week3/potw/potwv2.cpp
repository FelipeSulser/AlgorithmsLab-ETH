#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

void do_calc(){
	int num_jedi, num_segments;
	cin>>num_jedi>>num_segments;
	vector<pair<int,int> > jedis(num_jedi);
	for(int i = 0; i < num_jedi; i++){
		int a,b;
		cin>>a;
		cin>>b;
		jedis[i] = make_pair(b,a); //so that i sort them according to a
	}

	/*int j = 0;
	int d = 0;
	int k0 = -1;
	while(j< num_jedi)
	{
		j = 0; 
		d = 0;
		k0++;
		while(d<=10 && j < num_jedi){
			if((jedis[j].second <= k0) + (k0<=jedis[j].first)+(jedis[j].first < jedis[j].second) == 2){
				d++;
			}
			j++;
		}
	}
	*/
	int a,b,x,y;
	bool canbreak;
	int count;
	int k0;
	for(int i = 0; i <num_jedi; i++){
		a = jedis[i].second;
		b = jedis[i].first;
		canbreak = false;
		if(a <= b){
			for(int k = a; k <= b; k++){
				count = 0;
				for(int j = 0; j < num_jedi; j++){
					x = jedis[j].second;
					y = jedis[j].first;
					if(x <= y){
						if(k <= y && k >= x)count++;
					}else{
						if(k>=x || k<=y)count++;
					}
				}
				if(count <= 10){
					k0 = k;
					canbreak = true;
					break;
				}
			}
			if(canbreak) break;
		}else{
			for(int k = a; k <= num_segments; k++){
				count = 0;
				for(int j = 0; j < num_jedi; j++){
					x = jedis[j].second;
					y = jedis[j].first;
					if(x <= y){
						if(k <= y && k >= x) count++;
					}else{
						if(k >= x || k <= y) count++;
					}
				}
				if(count <= 10){
					k0 = k;
					canbreak = true;
					break;
				}
			}
			if(canbreak) break;

			for(int k = 1; k <= b; k++){
				count = 0;
				for(int j = 0; j < num_jedi; j++){
					x = jedis[j].second;
					y = jedis[j].first;
					if(x <= y){
						if(k <= y && k >= x)count++;
					}else{
						if(k >= x || k <=y)count++;
					}
				}
				if(count <= 10){
					k0 = k;
					canbreak = true;
					break;
				}
			}
			if(canbreak) break;
		}
	}
	int ix =k0;
	vector<pair<int,int> > cutK;
	vector<pair<int,int> > nocutK;
	int numcut = 0;
	//find one with less or equal than 10
	for(int i = 0; i < num_jedi; i++){
		int ai,bi;
		ai = jedis[i].second - ix;
		bi = jedis[i].first - ix;
		if(ai < 0) ai += num_segments;
		if(bi < 0) bi += num_segments;

		jedis[i].second = ai;
		jedis[i].first = bi;
		if(bi < ai){
			cutK.push_back(jedis[i]);
			numcut++;
		}else{
			nocutK.push_back(jedis[i]);
		}
	}

	std::sort(nocutK.begin(), nocutK.end());


	//so once i have this, i sort the jedis by ending time and assign them
	int result = 0;
	int lastpos = -1;
	for(int i = 0; i < num_jedi-numcut; i++){
		if(nocutK[i].second > lastpos){
			result++;
			lastpos = nocutK[i].first;
		}
	}
	int resultC;
	//same algo but starting with each cutter
	for(int c = 0; c  < numcut; c++){
		resultC = 1;
		lastpos = cutK[c].first;
		for(int i = 0; i < num_jedi - numcut; i++){
			if(nocutK[i].second > lastpos && nocutK[i].first < cutK[c].second){
				resultC++;
				lastpos = nocutK[i].first;
			}
		}
		if(resultC > result){
			result = resultC;
		}
	}
	cout<<result<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}