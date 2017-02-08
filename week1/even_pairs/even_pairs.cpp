#include <iostream>
#include <vector>

using namespace std;

void do_calc(){
	int n;
	cin>>n;

	vector<int> bitarr(n);
	int counter_even = 0;
	int counter_odd = 0;
	vector<int> cumsum(n);
	for(int i = 0; i < n; i++){
		int val;
		cin>>val;
		bitarr[i] = val;
	}
	cumsum[0] = bitarr[0];
	for(int i = 1; i < n; i++){
		cumsum[i] = cumsum[i-1]+bitarr[i];
	}
	int total_ctr = 0;
	//now do a window search 1 pass is O(n)
	if(cumsum[0] % 2 == 0){
		counter_even++;
		total_ctr++;
	}else{
		counter_odd++;
	}

	for(int i = 1; i < n; i++){
		if(cumsum[i] % 2 == 0){
			counter_even += 1;
			total_ctr += counter_even;
		}else{
			total_ctr += counter_odd;
			counter_odd += 1;
		}
	}


	cout<<total_ctr<<endl;


}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}