#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void do_calc(){
	int n,k;
	cin>>n>>k;
	vector<int> deck(n); //deck of cards
	for(int i = 0; i < n; i++){
		cin>>deck[i];
	}

	//now do a window search
	int low = 0;
	int top = 0;
	int min_i = 0;
	int min_j = 0;
	int accum = deck[0];
	int best = INT_MAX;

	while(low < n){
		if(abs(k - accum) < best){
			min_i = low;
			min_j = top;
			best = abs(k-accum);
		}

		if(top  < n &&  accum < k){
			top++;
			accum += deck[top];
		}else{
			accum-= deck[low];
			low++;
		}
	}

	cout<<min_i<<" " <<min_j<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--)do_calc();

	return 0;
}