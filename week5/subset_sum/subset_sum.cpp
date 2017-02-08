#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

bool exists_k2(int k2, vector<int> & subsum){
	//ordered in increased order
	int lmin = 0;
	int lmax = subsum.size();
	while(lmin < lmax){
		int mid = (lmin+lmax)/2;
		if(subsum[mid] == k2) return true;
		if(k2 < subsum[mid]){
			lmax = mid;
		}else{
			lmin = mid+1;
		}
	}
	return false;
}
void do_calc(){
	int n;
	//guaranteed n eve, not a huge deal tho
	cin>>n;
	int k;
	cin>>k;

	vector<int> val(n);
	for(int i = 0; i < n; i++){
		cin>>val[i];
	}
	int divide = n/2;
	vector<int> set1;
	vector<int> set2;
	for(int i = 0; i <n/2; i++){
		set1.push_back(val[i]);
	}
	for(int i = n/2; i < n; i++){
		set2.push_back(val[i]);
	}
	//std::sort(set2.begin(),set2.end());

	//get all subset sums
	int perm = 0;
	//val = (pow(2,divide))-1;
	perm = pow(2,divide);
	
	
	

	vector<int> sub_sum1;
	vector<int> sub_sum2;
	while(perm != 0){
		perm--; //until 0
		
		int k1 = 0;
		int k2 = 0;
		for(int i = 0; i < divide; i++){
			if((perm & 1 << i) != 0){
				k1 += set1[i];
				k2 += set2[i];
			}
		}
		sub_sum1.push_back(k1);
		sub_sum2.push_back(k2);
		
	}

	std::sort(sub_sum2.begin(), sub_sum2.end());
	std::sort(sub_sum1.begin(),sub_sum1.end());
	//cout<<sub_sum1[0]<<endl;
	//cout<<sub_sum2[0]<<endl;

	//bin search
	for(int i = 0; i < sub_sum1.size(); i++){
		int k2 = k-sub_sum1[i];
		//cout<<k2<<endl;
		if(exists_k2(k2,sub_sum2)){
			cout<<"yes"<<endl;
			return;
		}
	}
	cout<<"no"<<endl;

}


int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)do_calc();


	return 0;
}