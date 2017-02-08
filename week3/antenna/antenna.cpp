#include <iostream>
#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Min_circle_2.h>
#include <CGAL/Min_circle_2_traits_2.h>
#include <CGAL/number_utils.h>


using namespace std;

// typedefs
typedef  CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt K;
typedef  CGAL::Min_circle_2_traits_2<K>  Traits;
typedef  CGAL::Min_circle_2<Traits>      Min_circle;
typedef  K::Point_2 P;

double floor_to_double(const K::FT& x){
	double a = std::floor(CGAL::to_double(x));
	while(a>x) a-=1;
	while(a+1 <= x) a+=1;
	return a;
}

long long ceil_to_double(const K::FT& x)
{
	double a = std::ceil(CGAL::to_double(x));
	while (a < x) a += 1;
	while (a-1 >= x) a -= 1;
	return (long long) a;
}
void do_calc(int val)
{
	P citizen[val];
	for(int i = 0; i < val; i++){
		double x,y;
		cin>>x>>y;
		P p;
		
		p = P(x,y);
		citizen[i] = p;
	}
	Min_circle mc(citizen, citizen+val,true);
	Traits::Circle c = mc.circle();
	//rad = std::sqrt(CGAL::to_double(c.squared_radius()));
	cout<<ceil_to_double(CGAL::sqrt(c.squared_radius()))<<endl;

}


int main(){
	ios_base::sync_with_stdio(false);
	cout<<std::fixed;
	cout<<std::setprecision(0);
	int val;
	while(true){
		cin>>val;
		if(val == 0)return 0;
		do_calc(val);
	}
}