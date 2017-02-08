#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>

#include <vector>
#include <climits>
#include <map>

using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt EK;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;


double ceil_to_double(const EK::FT& x)
{
  double a = std::ceil(CGAL::to_double(x));
  while (a < x) a += 1;
  while (a-1 >= x) a -= 1;
  return a;
}
EK::FT transform(EK::FT & val){
  EK::FT deno = CGAL::sqrt(val)-1;
  deno = deno/2;
  return CGAL::sqrt(deno);
}
void do_calc(int n)
{

  int L,B,R,T;
  cin>>L>>B>>R>>T;
    map<K::Point_2,K::FT> mapper;
  vector<K::Point_2> bacteria(n);
  for(int i = 0; i < n; i++){
    cin>>bacteria[i];
    mapper[bacteria[i]] = INT_MAX;
  }
    Triangulation tr;
    tr.insert(bacteria.begin(), bacteria.end());

    for(int i = 0; i < n; i++){
      K::Point_2 pt = bacteria[i];
      K::FT distx = std::min(R-pt.x(), pt.x()-L);
      K::FT disty = std::min(T-pt.y(), pt.y()-B);
      K::FT minval = std::min(distx,disty);
      minval = 4*minval*minval;
      mapper[pt] = minval;
    }

  for (Edge_iterator e = tr.finite_edges_begin(); e != tr.finite_edges_end(); ++e){
    K::Segment_2 seg = tr.segment(e);
    K::Point_2 ori = seg.source();
    K::Point_2 dest = seg.target();
    K::FT dist = seg.squared_length();
    mapper[ori] = std::min(mapper[ori],dist);
    mapper[dest] = std::min(mapper[dest],dist);
  }

  //now that we have all, sort them by time
  vector<K::FT> timedist(n);
  for(int i = 0; i< n; i++){
    timedist[i] = mapper[bacteria[i]];
  } 
  std::sort(timedist.begin(), timedist.end());

  //now transform them
  EK::FT firstval = EK::FT(timedist[0]);
  EK::FT median = EK::FT(timedist[n/2]);
  EK::FT last = EK::FT(timedist[n-1]);


  cout<<ceil_to_double(transform(firstval))<<" " <<ceil_to_double(transform(median))<<" " <<ceil_to_double(transform(last))<<endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  while(true){
    int n;
    cin>>n;
    if(n == 0) return 0;
    do_calc(n);
  }
}