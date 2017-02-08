#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void do_calc(){
	int N,K;
	cin>>N>>K;
	//1 is > , -1 is < and 2 is eq 0 is unassigned
	vector<char> totalset(1005,'x'); 
	vector<int> set_1(505);
	vector<int> set_2(505);
	for(int k = 0; k < K; k++){
		int count;
		cin>>count;
		vector<int> isUsed(1005,0);

		for(int i = 0; i < count; i++){
			int s1;
			cin>>s1;
		
			set_1[i] = s1;
			isUsed[s1] = 1;
		}

		for(int i = 0; i < count; i++){
			int s2;
			cin>>s2;
			
			set_2[i] = s2;
			isUsed[s2] = 1;
		}
		char symbol;
		cin>>symbol;
		if(symbol == '>'){
			set_1.swap(set_2);
		}
		if(symbol == '='){ //eq
			//remove marked
			for(int l = 0; l < count; l++){
				totalset[set_1[l]] = '=';
				totalset[set_2[l]] = '='; // mark them as clean
			}
		}else{
			for(int i = 0; i < count; i++){
				if(totalset[set_1[i]] == 'x')
					totalset[set_1[i]] = '<';
				if(totalset[set_1[i]] == '>')
					totalset[set_1[i]] = '=';
				if(totalset[set_2[i]] == 'x')
					totalset[set_2[i]] = '>';
				if(totalset[set_2[i]] == '<')
					totalset[set_2[i]] = '=';
			}
			for(int j = 1; j <= N; j++){
			if(isUsed[j] != 1)
				totalset[j] = '=';
			}
		
		}
		
	}

	int pos = -1;
	for(int i = 1; i <= N; i++){
		if(pos == -1 && totalset[i] != '='){
			pos = i;

		}else if(totalset[i] != '='){
			pos = 0;//means there are more than 1 candidate
		}
	}
	cout<<pos<<endl;

}

int main(){
	int t;
	cin>>t;
	while(t--) do_calc();
	return 0;
}