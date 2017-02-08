#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Min_circle_2.h>
#include <CGAL/Min_circle_2_traits_2.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// typedefs
typedef  CGAL::Exact_predicates_exact_constructions_kernel K;
typedef  CGAL::Min_circle_2_traits_2<K>  Traits;
typedef  CGAL::Min_circle_2<Traits>      Min_circle;

typedef K::Point_2 P;
P capital;

double ceil_to_double(const K::FT& x)
{
	double a = std::ceil(CGAL::to_double(x));
	while (a < x) a += 1;
	while (a-1 >= x) a -= 1;
	return a;
}
bool comparator(P  p1, P  p2){
	return  squared_distance(p1,capital) > squared_distance(p2,capital);
}

void do_calc()
{

	int N;
	cin>>N;
	vector<P> points(N);
	cin>>capital;
	for(int i = 0; i < N-1; i++){
		P p;
		cin>>p;
		points[i] = p;
	}

	if(N <= 2){
		cout<<0<<endl;
		return;
	}
	std::sort(points.begin(),points.end(),comparator);

	vector<K::FT> distances(N); //to the capital
	for(int i = 0; i < N; i++){
		distances[i] = squared_distance(points[i],capital);
		//cout<<distances[i]<<endl;
	}
	//antenna on hauptstadt
	K::FT rad1 = distances[0]; //encompasses all theirland
	K::FT old_rad1 = rad1;


	K::FT rad2 = 0.0;
	K::FT old_rad2 =0.0;


	Min_circle mc(points.begin(), points.begin()+1,true);
	Traits::Circle circ2;
	int ix = 0;
	while(rad2 < rad1){
		//we increase new antennas radius
		old_rad1 = rad1;
		old_rad2 = rad2;

		mc.insert(points[ix]);
		//add a new city to our
		circ2 = mc.circle();

		//update, we decrease
		ix++;
		rad1 = distances[ix];
		rad2 = circ2.squared_radius();


	}
	K::FT result = min(max(rad1,rad2),max(old_rad1,old_rad2));
	cout<<ceil_to_double(result)<<endl;

	/*
	Min_circle mc(points.begin(), points.begin()+1, true);
	Traits::Circle c = mc.circle();
	std::cout << c.center() << " " << c.squared_radius() << std::endl;
	*/
}


int main(){
	
	ios_base::sync_with_stdio(false);
	cout<<fixed<<setprecision(0);
	int t;
	cin>>t;
	while(t--)do_calc();
	return 0;
}


