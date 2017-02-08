#include <iostream>
#include <vector>

using namespace std;

void do_calc(){
	int n;
	cin>>n;
	vector<vector<int> > bitmatrix(n+1,vector<int>(n+1,0));
	int counter_even = 0;
	int counter_odd = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int val;
			cin>>val;
			bitmatrix[i][j] = val;
		}
	}	


	vector<vector<int> > cumMatrix(n+1,vector<int>(n+1,0));
	for(int i = 0; i <= n; i++){
		cumMatrix[i][0] = 0;
		cumMatrix[0][i] = 0; //initial values
	}
	
	//first calculate the cumulative values
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cumMatrix[i][j] = bitmatrix[i][j] + cumMatrix[i-1][j] + cumMatrix[i][j-1] - cumMatrix[i-1][j-1];
		}
	}
	int total_counter = 0;
	for(int i1 = 1; i1 <= n; i1++){
		for(int i2 = i1; i2 <= n; i2++){
			//calculate the array
			vector<int> linear_vec(n+1);
			vector<int> sum_vec(n+1);
			linear_vec[0] = 0;
			for(int k = 1; k <= n; k++){
				linear_vec[k] = cumMatrix[i2][k]-cumMatrix[i2][k-1] - cumMatrix[i1-1][k]+cumMatrix[i1-1][k-1];
				sum_vec[k] = sum_vec[k-1]+linear_vec[k];
			}

			int even_counter = 0;
			int odd_counter = 0;
			int counter = 0; 
			
			for(int k = 1; k <= n; k++){
				if(sum_vec[k] % 2 == 0){
					even_counter += 1;
					counter += even_counter;
				}else{
					counter += odd_counter;
					odd_counter += 1;
				}
			}
			total_counter += counter;


		}
		
	}

	cout<<total_counter<<endl;


}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}