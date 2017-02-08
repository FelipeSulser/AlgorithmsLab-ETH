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
bool try_two_coloring(Triangulation & tr, K::FT & rad_sqr){
  for(auto v = tr.finite_vertices_begin(); v != tr.finite_vertices_end(); v++){
   // mapper[v->point()] = make_pair(0,false);
    v->info() = make_pair(0,false);
  }

  int components = 0;
  Triangulation trg0,trg1;
  for(auto v = tr.finite_vertices_begin(); v != tr.finite_vertices_end(); v++){
    if(v->info().first == 0){
      //not visited yet
      //mapper[v->point()].first = ++components;
      v->info().first = ++components;
      std::vector<Vertex_handle> stack;
      stack.push_back(v);
      while(!stack.empty()){
        Vertex_handle v1 = stack.back();
        stack.pop_back();
        Vertex_circulator vc = tr.incident_vertices(v1);
        do{ 
          if(!tr.is_infinite(vc) && CGAL::squared_distance(vc->point(),v1->point()) <= rad_sqr){
            //if(mapper[vc->point()] == mapper[v1->point()]) return false; //cannot color it
            if(vc->info() == v1->info())return false; //cannot have a coloring
            if(vc->info().first == 0){
          //  if(mapper[vc->point()].first == 0){
              vc->info() = make_pair(components,!v1->info().second);
             // mapper[vc->point()] = make_pair(components,!mapper[v1->point()].second);
              stack.push_back(vc);
            }
          }

        }while(++vc != tr.incident_vertices(v1));
      }
    }
    if(v->info().second)trg1.insert(v->point());
    else trg0.insert(v->point());
    
  }

  return !has_interference(trg0,rad_sqr) && !has_interference(trg1,rad_sqr);
}
void do_calc(){
  cout<<sizeof(long)<<endl;
  int n,m;
  K::FT r;
  cin>>n>>m>>r;
  vector<K::Point_2> stations(n);
  for(int i = 0; i < n; i++){
    cin>>stations[i];
  }

  Triangulation trs;
  trs.insert(stations.begin(),stations.end());
  K::FT sq_rad = r*r;
  bool succ = try_two_coloring(trs,sq_rad); //squared radius

  vector<K::Point_2> clue_sherlock(m);
  vector<K::Point_2> clue_watson(m);

  for(int i = 0; i < m; i++){
    cin>>clue_sherlock[i];
    cin>>clue_watson[i];
    if(succ){
      if(CGAL::squared_distance(clue_watson[i],clue_sherlock[i]) <=sq_rad){
        cout<<"y";
        continue;
      }
      auto nearest_holmes = trs.nearest_vertex(clue_sherlock[i]);
      auto nearest_watson = trs.nearest_vertex(clue_watson[i]);
      //if in the same connected component and distance to the point close enough then yes
     
      if(nearest_holmes->info().first == nearest_watson->info().first &&
        CGAL::squared_distance(nearest_watson->point(),clue_watson[i]) <= sq_rad &&
        CGAL::squared_distance(nearest_holmes->point(), clue_sherlock[i]) <= sq_rad){
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
