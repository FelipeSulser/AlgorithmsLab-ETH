#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void do_calc(){
	int N, K;
	cin>>N>>K;
	vector<int> deck(N);
	for(int i = 0; i < N; i++){
		int card_i;
		cin>>card_i;
		deck[i] = card_i;
	}


	//initialization complete, now proceed to window search
	int i = 0;
	int j = 0;
	int min_i = 0;
	int min_j = 0;
	int sum = deck[0];
	int best = INT_MAX;
	while(i<N){
		//cout<<"i="<<i<<" and j="<<j<<endl;
		//cout<<"sum= "<<sum<<" and best="<<best<<" diff="<<abs(sum-K)<<endl;
		if(abs(sum-K) < best){

			min_i = i;
			min_j = j;
			best  = min(best,abs(sum-K)); 
		}
		//cout<<abs(sum-K)<<endl;
		//cout<<best<<endl;
		if(sum < K && j < N){
			j++;
			sum += deck[j];
		}else{
			sum -= deck[i];
			i++;

		}
	}
	//guaranteed to be lexicographical order since we start from 0,0
	cout<<min_i<<" "<<min_j<<endl;

}

int main(){
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}