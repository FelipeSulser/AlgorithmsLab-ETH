#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt EK;

typedef Triangulation::Edge_iterator  Edge_iterator;

double ceil_to_double(const EK::FT& x)
{
  double a = std::ceil(CGAL::to_double(x));
  while (a < x) a += 1;
  while (a-1 >= x) a -= 1;
  return a;
}

EK::FT transform(EK::FT val){
  EK::FT val2 = CGAL::sqrt((CGAL::sqrt(val)-1)/2);
  return val2;
}

void do_calc(int n){
  K::FT l,b,r,t;
  cin>>l>>b>>r>>t;
  vector<K::Point_2> bacteria(n);
  for(int i = 0; i < n; i++){
    cin>>bacteria[i];
  }
  map<K::Point_2,K::FT> mapper;

  Triangulation trs;
  trs.insert(bacteria.begin(), bacteria.end());

  //first for all vertices, find the distance closest to wall
  for(auto v = trs.finite_vertices_begin(); v != trs.finite_vertices_end(); v++){
    K::Point_2 pt = v->point();
    K::FT minhor = std::min(pt.y()-b,t-pt.y());
    K::FT minvert = std::min(pt.x()-l,r-pt.x());
    K::FT minval = std::min(minhor,minvert);
    mapper[pt] = 4*minval*minval;
  }

  for(auto e = trs.finite_edges_begin(); e != trs.finite_edges_end(); e++){
    K::Point_2 p1,p2;
    K::Segment_2 seg = trs.segment(e);
    p1 = seg.source();
    p2 = seg.target();
    K::FT sqlen = seg.squared_length();
    mapper[p1] = std::min(mapper[p1],sqlen);
    mapper[p2] = std::min(mapper[p2],sqlen);
  }

  vector<K::FT> times;
  int i = 0;
  for(auto v = trs.finite_vertices_begin(); v != trs.finite_vertices_end(); v++){
    times.push_back(mapper[v->point()]);
  }

  std::sort(times.begin(),times.end());
  EK::FT min = transform(EK::FT(times[0]));
  EK::FT median = transform(EK::FT(times[n/2]));
  EK::FT maxval = transform(EK::FT(times[n-1]));
  cout<<ceil_to_double(min)<<" "<<ceil_to_double(median)<<" " <<ceil_to_double(maxval)<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  while(true){
    int n;
    cin>>n;
    if(n == 0) return 0;
    do_calc(n);
  }
  return 0;
}
