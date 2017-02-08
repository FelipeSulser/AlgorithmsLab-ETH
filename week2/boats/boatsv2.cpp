#include <iostream>
#include <climits>
#include <queue>
#include <set>
#include <vector>
using namespace std;
class Triple{
public:
	int len, ring, endPos;
	Triple(int l, int r){
		len = l;
		ring = r;
		endPos = r; //greedily put ship to left until ring -- last pos
	}
	bool operator< (const Triple & t) const{
		if(t.endPos == endPos){
			return ring > t.ring;
		}else{
			return endPos > t.endPos;
		}
	}
};

void do_calc(){
	int N;
	cin>>N;
	priority_queue<Triple> queue;
	for(int i = 0; i < N; i++){

		int len, ringpos;
		cin>>len>>ringpos;
		queue.push(Triple(len,ringpos)); // sorts according to endpos and if equal to ring,
	}


	//now first is base case
	int shift = queue.top().endPos;
	queue.pop();
	int count = 1;
	while(!queue.empty()){
		Triple val = queue.top();
		queue.pop();
		if(val.endPos - val.len >= shift){
			//it fits
			count++;
			shift = val.endPos;
		}else{
			if(shift <= val.ring){
				int newsize = val.len + shift;
				if(newsize >= val.ring){
					Triple t = Triple(val.len,val.ring);
					t.endPos = newsize;
					queue.push(t);
				}
			}
		}
	}
	cout<<count<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) do_calc();
	return 0;
}