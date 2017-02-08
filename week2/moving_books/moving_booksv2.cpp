#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool can_do_r_rounds(vector<int> & friends, vector<int>& boxes, int r, int n, int m){
	int i = 0; int j = 0;

	while(i<n && j < m){
		if(friends[i] >= boxes[j]){
			//he can lift it bro
			i++;
			j += r; //can lift r boxes because its sorted in decreasing
		}else{
			return false;
		}
	}
	//if lifted them all gg
	return j>=m; //j needs to be covered
}
void do_calc(){
	int num_friends, num_boxes;
	cin>>num_friends>>num_boxes;

	vector<int> friends(num_friends);
	for(int i = 0; i < num_friends; i++){
		cin>>friends[i];
	}	
	vector<int> boxes(num_boxes);
	for(int i = 0; i < num_boxes; i++){
		cin>>boxes[i];
	}

	std::sort(boxes.rbegin(),boxes.rend());
	std::sort(friends.rbegin(),friends.rend());
	if(boxes[0] > friends[0]) {
		cout<<"impossible"<<endl;
		return;
	}
	//now do a lil bin search
	int lmin = 0;
	int lmax = 3*num_boxes; //max time

	while(lmin < lmax){
		int mid = (lmin+lmax)/2;
		if(!can_do_r_rounds(friends,boxes,mid/3,num_friends,num_boxes)){
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
	while(t--)do_calc();
	return 0;
}