#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <vector>
#include <map>
#include <climits>

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

EK::FT transform(EK::FT in){
  return CGAL::sqrt((CGAL::sqrt(in)-1)/2);
}
void do_calc(int n)
{

  int l,b,r,t;
  cin>>l>>b>>r>>t;

  vector<K::Point_2> germs(n);
  for(int i = 0; i < n; i++){
    cin>>germs[i];
  }

  vector<K::FT> death_time;

  map<K::Point_2,K::FT> mapper;
  Triangulation trs;
  trs.insert(germs.begin(), germs.end());

  for(auto vi = trs.finite_vertices_begin(); vi != trs.finite_vertices_end(); vi++){
    K::Point_2 pval = vi->point();
    K::FT minvert = std::min(pval.x()-l,r-pval.x());
    K::FT minhor = std::min(pval.y()-b, t-pval.y());
    K::FT minwall = min(minvert,minhor);
    mapper[pval] = 4*minwall*minwall;
  }
  for (Edge_iterator e = trs.finite_edges_begin(); e != trs.finite_edges_end(); ++e){
      K::Segment_2 seg = trs.segment(e);
      K::FT dist = seg.squared_length();
      K::Point_2 src = seg.source();
      K::Point_2 trg = seg.target();

      mapper[src] = std::min(mapper[src],dist);
      mapper[trg] = std::min(mapper[trg],dist);
  }

  int i = 0;
  for(auto vi = trs.finite_vertices_begin(); vi != trs.finite_vertices_end(); vi++){
    death_time.push_back(mapper[vi->point()]);
  }

  std::sort(death_time.begin(),death_time.end());
  EK::FT mintime = transform(EK::FT(death_time[0]));
  EK::FT median = transform(EK::FT(death_time[n/2]));
  EK::FT lasttime = transform(EK::FT(death_time[n-1]));

  cout<<ceil_to_double(mintime)<<" " <<ceil_to_double(median)<<" " <<ceil_to_double(lasttime)<<endl;
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
