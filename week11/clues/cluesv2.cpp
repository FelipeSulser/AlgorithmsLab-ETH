#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_data_structure_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

typedef std::pair<int,bool> info_t;
typedef CGAL::Triangulation_vertex_base_with_info_2<info_t,K> vertex_t;
typedef CGAL::Triangulation_face_base_2<K> face_t;
typedef CGAL::Triangulation_data_structure_2<vertex_t,face_t> triangulation_t;
typedef CGAL::Delaunay_triangulation_2<K,triangulation_t> Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;
typedef Triangulation::Vertex_handle Vertex_handle;
typedef Triangulation::Vertex_circulator Vertex_circulator;


bool has_interference(Triangulation & tr, K::FT & rr){
  for(auto e = tr.finite_edges_begin(); e != tr.finite_edges_end(); e++){
    if(tr.segment(*e).squared_length() <= rr) return true;
  }
  return false;
}

bool two_coloring(Triangulation & tr, K::FT & rad){
  //attempt to perform a two coloring
  //start at a vertex
  for(auto v = tr.finite_vertices_begin(); v != tr.finite_vertices_end(); v++){
    v->info() = make_pair(0,false);
  }

  int components = 0;
  Triangulation tr1,tr2;
  for(auto v = tr.finite_vertices_begin(); v != tr.finite_vertices_end(); v++){
    if(v->info().first == 0){
      v->info().first = ++components;
      std::vector<Vertex_handle> stack;
      stack.push_back(v);
      while(!stack.empty()){
        Vertex_handle topval = stack.back();
        stack.pop_back();
        Vertex_circulator vc = tr.incident_vertices(topval);
        do{
          if(!tr.is_infinite(vc) && CGAL::squared_distance(vc->point(),topval->point()) <= rad){
            if(vc->info() == topval->info()) return false; //impossible to color it
            if(vc->info().first == 0){
              vc->info() = make_pair(components,!topval->info().second);
              stack.push_back(vc);
            }
          }

        }while(++vc != tr.incident_vertices(topval));
      }
    }
    if(v->info().second){
      tr1.insert(v->point());
    }else{
      tr2.insert(v->point());
    }
  }
  return !has_interference(tr1,rad) && !has_interference(tr2,rad);

}
void do_calc(){
  int n,m;
  K::FT r;
  cin>>n>>m>>r;
  vector<K::Point_2> stations(n);
  for(int i = 0; i < n; i++){
    cin>>stations[i];
  }

  Triangulation trs;
  trs.insert(stations.begin(),stations.end());
  K::FT sq_dist = r*r;
  bool succ = two_coloring(trs,sq_dist);

  for(int i = 0; i < m; i++){
    K::Point_2 p1,p2;
    cin>>p1>>p2;
   if(succ){
    if(CGAL::squared_distance(p1,p2) <= sq_dist){
      cout<<"y";
      continue;
    }
    auto nearestsherlock = trs.nearest_vertex(p1);
    auto nearestwatson = trs.nearest_vertex(p2);

    if(nearestsherlock->info().first == nearestwatson->info().first &&
      CGAL::squared_distance(nearestsherlock->point(),p1) <= sq_dist
      &&
      CGAL::squared_distance(nearestwatson->point(), p2) <= sq_dist){
      cout<<"y";
      continue;
    }

   }
   
    cout<<"n";
  }
  cout<<endl;

}

int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)do_calc();
  return 0;
}