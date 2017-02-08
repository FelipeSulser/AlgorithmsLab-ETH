#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool possible_in_r(vector<int> & boxes, vector<int> & friends, int r, int n, int m){
	int i = 0;
	int j = 0;
	while(i < n && j < m){
		if(boxes[j] <= friends[i]){
			i++;
			j+=r; // this friend lifted r boxes
		}else{
			return false;
		}
		//cout<<"r="<<r<<" i="<<i<< " j=" <<j<<" " <<endl;
	}
	return j>=m;
}

void do_calc(){
	int n,m;
	cin>>n>>m;
	vector<int> friends(n);
	vector<int> boxes(m);
	for(int i = 0; i < n; i++){
		//friends strength
		cin>>friends[i];
	}

	std::sort(friends.rbegin(),friends.rend());


	for(int j = 0; j < m; j++){
		cin>>boxes[j];
	}
	std::sort(boxes.rbegin(),boxes.rend());

	//see if we can solve it in 
	if(boxes[0] > friends[0]){
		//boxes heavier than strongest friend
		cout<<"impossible"<<endl;
		return;
	}
	//cout<<possible_in_r(boxes,friends,4/3,n,m)<<endl;

	//now do a bin search
	//can we do it in r rounds?
	//first [0,m]
	int lmin = 0;
	int lmax = m*3;
	while(lmin < lmax){
		int mid = (lmin+lmax)/2;
		if(!possible_in_r(boxes,friends,mid/3,n,m)){
			lmin++;
		}else{
			lmax = mid;
		}
	}
	cout<<lmin-1<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) do_calc();
	return 0;
}