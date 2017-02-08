#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <vector>
#include <climits>
#include <iostream>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>

// choose exact integral type
typedef CGAL::Gmpzf ET;

// program and solution types
typedef CGAL::Quadratic_program<double> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

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

  //sol is minlen
  double prevsol = CGAL::to_double(CGAL::sqrt(min_len)/2);

  //now do a LP
  //max sum(ri)
  //s.t.
  // ri >= prevsol
  //ri+rj <= dist(i,j)

  Program lp(CGAL::SMALLER, true,0,false,0);
  for(int i = 0; i< n; i++){
    lp.set_c(i,1);
  }

  //variables ri
  for(int i = 0; i < n; i++){
    lp.set_a(i,i,1);
    lp.set_b(i,prevsol);
    lp.set_r(i,CGAL::LARGER);
  }
  int ix  = n;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      lp.set_a(i,ix,1);
      lp.set_a(j,ix,1);
      K::FT sqdist = CGAL::squared_distance(cannons[i],cannons[j]);
      double dist = CGAL::to_double(CGAL::sqrt(sqdist));
      lp.set_b(ix,dist);
      ix++;
    }
  }
  Solution sol = CGAL::solve_linear_program(lp,ET());
  cout<<CGAL::to_double(sol.objective_value())<<endl;
 

}

int main()
{
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)do_calc();
  return 0;
}
