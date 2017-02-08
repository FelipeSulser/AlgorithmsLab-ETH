#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
class Ball{
public:
	int ix;
	int time;
	int father_left;
	int father_right;
	bool dependent;
	Ball(int i, int t, int n){
		ix = i;
		time = t;
		dependent = (i <= ((n-3)/2));
		if(dependent){
			father_left = 2*i+1;
			father_right = 2*i+2;

		}else{
			father_right = -1;
			father_left = -1;
		}
	}

	bool operator< (const Ball & a) const{
		if(a.time != time){
			return time > a.time;
		}
		return dependent; // we want independent
	}

};

bool disarmBall(Ball & b, int & time, vector<bool>& disarmed){
	if(disarmed[b.ix])return true;

	if(time >= b.time) return false;

	//else we disarm it and add 1 minute
	time++;
	disarmed[b.ix] = true;
	return true;
}
void do_calc(){
	int n;
	cin>>n;

	//sort them in pqueue
	priority_queue<Ball> pq;
	vector<Ball> ball_index;
	for(int i = 0; i < n; i++){
		int timer;
		cin>>timer;
		ball_index.push_back(Ball(i,timer,n));
		pq.push(Ball(i,timer,n));
	}

	int time = 0;
	vector<bool> disarmed(n,false);
	//now we traverse them all and defuse them in order of queue
	while(!pq.empty()){
		Ball elem = pq.top();
		pq.pop();

		//cases, dependent or not
		if(!elem.dependent){
			//independent, if can defuse on time ok else fail
			if(!disarmBall(elem,time,disarmed)){
				cout<<"no"<<endl;
				return;
			}
		}else{
			//means dependent
			bool conditions = true;
			Ball father_left = ball_index[elem.father_left];
			Ball father_right = ball_index[elem.father_right];
			if(father_right.time < father_left.time){
				conditions = disarmBall(father_right,time,disarmed);
				conditions = conditions && disarmBall(father_left,time,disarmed);
			}else{
				conditions = disarmBall(father_left,time,disarmed);
				conditions = conditions && disarmBall(father_right, time, disarmed);
			}
			conditions = conditions && disarmBall(elem,time,disarmed);
			if(!conditions){
				cout<<"no"<<endl;
				return;
			}
		}
	}
	cout<<"yes"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) do_calc();
	return 0;
}