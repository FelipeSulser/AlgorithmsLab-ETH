#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void do_calc(){
	int n;
	cin>>n;
	int k;
	cin>>k;
	int x;
	cin>>x;

	vector<int> bulb(n);

	vector<int> desired_pattern(k,0);
	for(int i = 0; i < k; i++){
		if((x & 1 << i) != 0){
			desired_pattern[i] = 1;
		}
	}

	for(int i = 0; i < n; i++){
		cin>>bulb[i];
	}
	int swapping_all = 1;
	int single_switching = 0;
	int num_groups = (int)n/k;
	for(int i = num_groups; i > 0; i--)
	{
		int from = i*k-k;

		int local_swap_all = 0;
		int local_swap_single = 0;

		for(int j = 0; j < k; j++){
			if(bulb[from+j] != desired_pattern[j]){
				local_swap_single++;
			}else{
				local_swap_all++;
			}
		}
		int tmp_swapped = min(
			min(
				swapping_all + local_swap_all,
				swapping_all + 2 + local_swap_single),
			min(
				single_switching + 1 + local_swap_all,
				single_switching + 1 + local_swap_single)
			);
		int tmp_single_change = min(
			min(
				single_switching + local_swap_single,
				single_switching + 2 + local_swap_all),
			min(
				swapping_all + 1 + local_swap_single,
				swapping_all + 1  + local_swap_all)
			);
		swapping_all = tmp_swapped;
		single_switching = tmp_single_change;
	}
	cout<<min(swapping_all, single_switching)<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}