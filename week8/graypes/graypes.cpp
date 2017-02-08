#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <vector>
#include <iostream>

typedef CGAL::Exact_predicates_inexact_constructions_kernel IK;
typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt EK;
typedef CGAL::Delaunay_triangulation_2<IK>  Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;

using namespace std;

double ceil_to_double(EK::FT const & x){
  double a = std::ceil(CGAL::to_double(x));
  while(a < x) a+= 1;
  while(a-1 >= x) a-=1;
  return a;
}


void do_calc(int n){
  vector<IK::Point_2> points(n);

  for(int i = 0; i < n; i++){
    cin>>points[i];
  }

  Triangulation t;
  t.insert(points.begin(),points.end());
  IK::FT dist_min = INT_MAX*1.0;
  for (Edge_iterator e = t.finite_edges_begin(); e != t.finite_edges_end(); ++e){
    IK::Segment_2 seg = t.segment(e);
    if(seg.squared_length() <= dist_min){
      dist_min = seg.squared_length();
    }
  }
  EK::FT time_cs = 50*CGAL::sqrt(EK::FT(dist_min));
  cout<<ceil_to_double(time_cs)<<endl;

}
int main(){
  ios_base::sync_with_stdio(false);
  while(true){
    int n;
    cin>>n;
    if(n == 0) return 0;
    do_calc(n);
  }
  
}
