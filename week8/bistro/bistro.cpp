#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <vector>
#include <iostream>

using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;

void do_calc(int n){
  vector<K::Point_2> locs(n);
  for(int i = 0; i < n; i++){
    cin>>locs[i];
  }
  Triangulation t;
  t.insert(locs.begin(), locs.end());

  int m;
  cin>>m;
  for(int i = 0; i < m; i++){
    K::Point_2 nearest_p,p;
    cin>>p;
    nearest_p = t.nearest_vertex(p)->point();
    cout<<CGAL::squared_distance(p,nearest_p)<<endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  while(true){
    int n;
    cin>>n;
    if(n == 0)return 0;
    do_calc(n);
  }
}
