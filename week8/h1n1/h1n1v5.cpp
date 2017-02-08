#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;
typedef Triangulation::Face_handle Face_handle;

void do_calc(int n){
  vector<K::Point_2> infected(n);
  for(int i = 0; i < n; i++){
    cin>>infected[i];
  }

  Triangulation trs;
  trs.insert(infected.begin(), infected.end());
  int m;
  cin>>m;

  //m is number of escapees
   map<Face_handle,int> visited;

   for(auto fi = trs.finite_faces_begin(); fi != trs.finite_faces_end(); fi++){
    visited[fi] = -1;
   }
  for(int i = 0; i <m; i++){
    K::Point_2 pos;
    cin>>pos;
    K::FT dist;
    cin>>dist;

    K::Point_2 near_zombie = trs.nearest_vertex(pos)->point();
    if(CGAL::squared_distance(near_zombie,pos) < dist){
      cout<<"n";
      continue;
    }

   
    //if not do a face iter until reach final face
    Face_handle fh = trs.locate(pos);
    vector<Face_handle> qq;
    qq.push_back(fh);
    visited[fh] = i;
    bool found = false;
    while(!qq.empty()){
      Face_handle current = qq.back();
      qq.pop_back();

      if(trs.is_infinite(current))
      {
        found = true;
        break;
      }
      //now for the neighbors
      for(int j = 0; j < 3; j++){
        Face_handle neigh = current->neighbor(j);
        K::Segment_2 segg = trs.segment(current,j);
        if(visited[neigh] != i && segg.squared_length() >= 4*dist){
          visited[neigh] = i;
          qq.push_back(neigh);
        }
      }

    }
    if(!found)cout<<"n";
    else cout<<"y";
  }
  cout<<endl;


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
