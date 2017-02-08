#include <iostream>
#include <vector>
#include <algorithm>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <iostream>
#include <stdexcept>
#include <climits>

using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Segment_2 S;
typedef K::Triangle_2 T;


bool contains(vector<P> & triang, P & p){
	bool flag;
	flag = !CGAL::right_turn(triang[0],triang[1],p) && !CGAL::right_turn(triang[2],triang[3],p) && !CGAL::right_turn(triang[4],triang[5],p);
	return flag;
}
void do_calc(){
	int m,n;
	cin>>m>>n;

	vector<P> checkpoints(m);
	vector<S> legs(m-1);
	for(int i = 0; i < m; i++){
		P p1;
		cin>>p1;
		checkpoints[i] = p1;
	}


	vector<vector<int> >triangles_taken(n);
	for(int i = 0; i < n; i++){
		//triangles are three points
		vector<P> triang;
		for(int i = 0; i < 6; i++){
			P point;
			cin>>point;
			triang.push_back(point);
		}
		for(int j = 0; j < 6; j+=2){
			if(CGAL::right_turn(triang[j],triang[j+1],triang[(j+2)%6])){
				std::swap(triang[j],triang[j+1]);
			}
		}

		//check which leg is in the current triang
		bool prev = contains(triang,checkpoints[0]);

		for(int j = 1; j < m; j++){
			if(contains(triang,checkpoints[j])){
				if(prev)triangles_taken[i].push_back(j-1);
				else prev = true;
			}else prev = false; //not contained,goes to prev
		}

	}

	vector<int> covered(m-1,0);
	int uncovered = m-1;
	int best = n; //best range
	int upper = 0;
	int lower = 0;

	vector<int> candidates_upper;
	int min = INT_MAX;
	//make biggest so that its covered
	bool state = true;

	int i = -1;
	int j = 0;
	//true means increment set
	while(true){
		if(upper > i){
			state = true;
		}
		if(j>= n){
			break;
		}
		if(state){
			if(i>=n-1){
				state = false;
				continue;
			}
			++i;

			for(int k = 0; k < triangles_taken[i].size(); k++){
				int leg = triangles_taken[i][k];
				if(covered[leg] == 0){
					uncovered--;
				}
				covered[leg]++;
			}
		}else{
			for(int k = 0; k < triangles_taken[j].size(); k++){
				int leg = triangles_taken[j][k];
				covered[leg]--;
				if(covered[leg] == 0)uncovered++;
			}
			j++;
		}
		if(uncovered == 0){//all covered
			min = std::min(min,i-j+1);
			state = false;
		}else{
			state = true; // keep lookin
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