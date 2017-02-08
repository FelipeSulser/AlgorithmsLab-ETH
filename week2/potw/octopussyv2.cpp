#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class Ball{
public:
	int index;
	bool dependent;
	int time_explosion;
	int first_parent;
	int second_parent;
	Ball(){};
	Ball(int t, int ix, int n){
		dependent = (ix <= ((n-3)/2));
		index = ix;
		time_explosion = t;
		if(dependent){
			first_parent = 2*ix+1;
			second_parent = 2*ix+2;
		}else{
			first_parent = -1;
			second_parent = -1;
		}
	}

	bool operator< (const Ball & a) const{
		if(time_explosion != a.time_explosion){
			return time_explosion > a.time_explosion;
		}
		return dependent;
	}	

};


bool disarm(Ball & b, int &time , vector<bool> & ball_disarmed){
	if(ball_disarmed[b.index]){
		return true;
	}
	if(time >= b.time_explosion) return false;

	ball_disarmed[b.index] = true;
	time++;
	return true;
}
void do_calc(){
	int n;
	cin>>n;
	priority_queue<Ball> balls;
	vector<Ball> ball_vec(n);
	for(int i = 0; i < n; i++){
		int timer;
		cin>>timer;
		balls.push(Ball(timer,i,n));
		ball_vec[i] = Ball(timer,i,n);
	}

	vector<bool> ball_disarmed(n,false);

	vector<int> ball_ix(n);
	for(int i = 0; i < n; i++){
		ball_ix[ball_vec[i].index] = i;
	}
	

	int time = 0;
	for(int i = 0; i < n; i++){
		Ball current = balls.top();
		balls.pop();
		if(current.dependent){
			Ball &first_parent = ball_vec[current.first_parent];
			Ball &second_parent = ball_vec[current.second_parent];
			bool flag = true;
			if(first_parent.time_explosion < second_parent.time_explosion){
				//defuse first first
				flag = disarm(first_parent,time,ball_disarmed);
				flag = flag && disarm(second_parent,time,ball_disarmed);
			}else{
				flag = disarm(second_parent,time,ball_disarmed);
				flag = flag && disarm(first_parent,time,ball_disarmed);
			}
			flag = flag && disarm(current,time,ball_disarmed);
			if(!flag){
				cout<<"no"<<endl;
				return;
			}

		}else{
			if(!disarm(current,time,ball_disarmed)){
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
	while(t--)do_calc();

	return 0;
}