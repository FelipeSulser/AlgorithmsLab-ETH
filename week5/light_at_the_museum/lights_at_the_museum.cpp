#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool isSol(int n,int assigned, vector<int> & target, vector<vector<int> > & on, vector<vector<int> > & off){
	//cout<<"here"<<endl;
	for(int i = 0; i < target.size(); i++){
		int cumsum = 0;
		int obj = target[i];
		for(int j = 0; j  < n; j++){
			if((assigned & 1 << j) != 0){
				cumsum+= on[j][i];
			}else{
				cumsum+= off[j][i];
			}
		}
		if(cumsum != obj) return false;
	}
	return true;
}

int memoized(vector<vector<int> > & memo,int i, int assigned, int n,int m,vector<int> & target, vector<vector<int> > & on_switch, vector<vector<int> > & off_switch){
	//cout<<i<<" " <<assigned<<endl;
	if(i > n){
		return 0;
	}
	if(i == n){
		if(isSol(n,assigned,target,on_switch,off_switch)){
			//cout<<"here2"<<endl;
			return 0;
		}else{
			//cout<<"here2"<<endl;
			return INT_MAX/2;
		}
	}
	if(memo[i][assigned] != -1){
		return memo[i][assigned];
	}else{

		//now both
		if(!((assigned & 1 << i) != 0)){
			assigned |= 1 <<i;
		}
		int val1 = memoized(memo,i+1,assigned,n,m,target,on_switch,off_switch);


		if((assigned & 1 << i) != 0){
			assigned &= ~(1<<i);
		}	
		int val2 =1+ memoized(memo,i+1,assigned,n,m,target,on_switch,off_switch);
		memo[i][assigned] = min(val1,val2);
		return min(val1,val2);
	}


}

void do_calc(){
	int n,m;
	cin>>n>>m;

	//now target brightness
	vector<int> target(m);
	for(int i = 0; i < m; i++){
		cin>>target[i];
	}
	vector<vector<int> > switches_on(n);
	vector<vector<int> > switches_off(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int on_j;
			int off_j;
			cin>>on_j;
			cin>>off_j;
			switches_on[i].push_back(on_j);
			switches_off[i].push_back(off_j);
		}
	}
	int assigned = 0;
	int maxsize = pow(2,n);
	//cout<<"maxsize = "<<maxsize<<" n= "<<n<<endl;
	vector<vector<int> > memo(n,vector<int>(maxsize,-1));
	//vector<vector<int> > & memo,int i, int assigned, int n,int m,vector<int> & target, vector<vector<int> > & on_switch, vector<vector<int> > & off_switch){

	int sol = memoized(memo,0,assigned,n,m,target,switches_on,switches_off);
	if(sol >= INT_MAX/2) {
		cout<<"impossible"<<endl;
	}else{
		cout<<sol<<endl;
	}


}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();

	return 0;
}