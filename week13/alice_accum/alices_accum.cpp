#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void do_calc(){
	int k;
	cin>>k;
	vector<vector<int> > ballvalues(k);
	for(int i = 1; i <= k; i++){
		vector<int> layer;
		for(int j = 1; j <= i; j++){	
			int val;
			cin>>val;
			layer.push_back(val);
		}
		ballvalues[i-1] = layer;
	}

	//now that i have the structure
	//do a lil dp to precumpute sums of x,y

	vector<vector<int> > P(k,vector<int>(k,0));
	for(int i = k-1; i >= 0; i--){
		for(int j = 0; j < i; j++){
			if(i == k-1){
				P[i][j] = ballvalues[i][j];
			}else{
				if(i == k-2){
					//cout<<"here"<<endl;
					//cout<<ballvalues[i][j]<<endl;
					P[i][j] = ballvalues[i][j]+P[i+1][j]+P[i+1][j+1];
					//cout<<"here2"<<endl;
				}else{
					P[i][j] = ballvalues[i][j] + P[i+1][j]+P[i+1][j+1]-P[i+2][j+1];
				}
			}
		}
	}

	int max = -1;
	for(int i = 0; i < k; i++){
		for(int j = 0; j < i; j++){
			max = std::max(max,P[i][j]);
		}
		
	}

	cout<<max<<endl;


}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}