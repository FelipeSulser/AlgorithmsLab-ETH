#include <iostream>
#include <vector>

using namespace std;

void do_calc(){
	int N;
	cin>>N;
	vector<int> dominoes(N);
	for(int i = 0; i < N; i++){
		cin>>dominoes[i];
	}

	int max = dominoes[0]-1;
	int i;
	int current = 0;

	//maxjump technique
	for(i = 0; i < N; i++){
		if(max < 0) break;
		current = dominoes[i]-1;
		if(current > max){
			max = current;
			max--;
		}else{
			max--; // i could accelerate this and jump 
		}
	}
	cout<<i<<endl;


}

int main(){
	int t;
	cin>>t;
	while(t--) do_calc();
	return 0;
}


