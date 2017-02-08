#include <iostream>
#include <algorithm>
#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <stdexcept>
#include <climits>



using namespace std;


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Segment_2 S;

bool covers(vector<P> & t, P & p){
	bool flag;
	//if none of them has a right turn, means all left so inside
	return !CGAL::right_turn(t[0],t[1],p) && !CGAL::right_turn(t[2],t[3],p) && !CGAL::right_turn(t[4],t[5],p);
}

void do_calc(){
	int m, n;
	cin>>m>>n;
	vector<P> checkpoints(m);
	for(int i = 0; i < m; i++){
		P point;
		cin>>point;
		checkpoints[i] = point;
	}

	vector<vector<int> > triangle_coverage(n);
	for(int i = 0; i < n; i++){
		//triangles
		vector<P> triangle_points(6);
		for(int j = 0; j < 6; j++){
			P p;
			cin>>p;
			triangle_points[j] = p;
		}

		//make them turn left
		for(int j = 0; j < 6; j+=2){
			if(CGAL::right_turn(triangle_points[j],triangle_points[j+1],triangle_points[(j+2)%6])){
				std::swap(triangle_points[j],triangle_points[j+1]); //ensure are all left turning 
			}
		}
		//check how many legs this guy covers
		//legs 0 -- m-1
		bool prev = covers(triangle_points,checkpoints[0]);
		for(int j = 1; j < m; j++){
			bool current = covers(triangle_points,checkpoints[j]);
			if(prev && current){
				//triangle i covers leg j-1
				triangle_coverage[i].push_back(j-1);
			}
			if(!current) prev = false;
			else prev = true;
		}

	}


	//now do a window search left and right
	int min = INT_MAX;
	bool increase = true;
	int upper = -1;
	int lower = 0;



	vector<int> num_coverage(m-1,0);
	int uncovered = m-1;

	while(true){
		if(lower > upper) increase = true;
		if(lower >= n){
			break;
		}

		if(increase){
			if(upper >= n-1){
				increase = false;
				continue; 
				//reach max capacity
			}
			upper++;
			for(int k = 0; k < triangle_coverage[upper].size(); k++){
				int leg = triangle_coverage[upper][k];
				if(num_coverage[leg] == 0) uncovered--;
				num_coverage[leg]++;
			}
		}else{
			//delete lower and increase lower iterator
			for(int k = 0; k < triangle_coverage[lower].size(); k++){
				int leg = triangle_coverage[lower][k];
				num_coverage[leg]--;
				if(num_coverage[leg] == 0){
					uncovered++;
				}
			}
			lower++;
		}
		if(uncovered == 0){
			min = std::min(min, upper-lower+1);
			increase = false;
		}else{
			increase = true; //not all covered
		}
	}

	cout<<min<<endl;

}


int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)do_calc();

	return 0;
}