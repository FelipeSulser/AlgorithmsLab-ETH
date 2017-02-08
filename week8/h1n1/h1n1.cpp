#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_face_base_with_info_2.h>
#include <iostream>
#include <climits>
#include <vector>
#include <map>

using namespace std;
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_vertex_base_2<K> Vb;
typedef CGAL::Triangulation_face_base_with_info_2<int,K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds> Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;
typedef Triangulation::Face_handle Face_handle;

void do_calc(int n){

  vector<K::Point_2> zeds(n);
  for(int i = 0; i < n; i++)
  {
    cin>>zeds[i];
  }
   Triangulation t;
  t.insert(zeds.begin(), zeds.end());
  int m;
  cin>>m;
  map<Face_handle,int> identifier;
  for(Triangulation::Face_iterator it = t.finite_faces_begin(); it != t.finite_faces_end(); it++){
    identifier[it] = -1;
  }

  for(int i = 0; i < m ; i++){
    K::Point_2 user_pos;
    cin>>user_pos;

    K::FT dist;
    cin>>dist;
    bool possible = false;
    vector<Face_handle> stack;
    Face_handle f = t.locate(user_pos);
    f->info() = i+1;
    identifier[f] = i;
    if(dist <= 0 || CGAL::squared_distance(user_pos,t.nearest_vertex(user_pos)->point()) < dist){
      possible = false;
    }else{
      stack.push_back(f);
      while(!stack.empty() && !possible){
        f = stack.back();
        stack.pop_back();
        if(t.is_infinite(f)){
          possible = true;
          break;
        }
        for(int j = 0; j < 3; j++){
          Face_handle neighbor = f->neighbor(j);
         // cout<<"Dist : "<<t.segment(Triangulation::Edge(f,j)).squared_length()<<" min "<<4*dist<<endl;
          //cout<<"info "<<neighbor->info()<<endl;
          if(identifier[neighbor] != i && t.segment(Triangulation::Edge(f,j)).squared_length() >= 4*dist){
            identifier[neighbor] = i;
            stack.push_back(neighbor);
          }
        }
      }
    }
    if(possible){
      cout<<"y";
    }else{
      cout<<"n";
    }
  }
  cout<<endl;
  //for each user find if he can escape


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
