#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <vector>
#include <climits>

using namespace std;

typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;

double floor_to_double(const K::FT& x)
{
  double a = std::floor(CGAL::to_double(x));
  while (a > x) a -= 1;
  while (a+1 <= x) a += 1;
  return a;
}
void do_calc(){
  int n;
  cin>>n;
  vector<K::Point_2> cannons(n);
  for(int i = 0; i < n; i++){
    cin>>cannons[i];
  }
  Triangulation t;
  t.insert(cannons.begin(), cannons.end());
  // output all edges
  K::FT min_len = INT_MAX;
  for (Edge_iterator e = t.finite_edges_begin(); e != t.finite_edges_end(); ++e){
    K::Segment_2 seg = t.segment(e);
    min_len = std::min(min_len, seg.squared_length());
  } 

  cout<<(CGAL::to_double(CGAL::sqrt(min_len))/2)<<endl;
 

}

int main()
{
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)do_calc();
  return 0;
}
