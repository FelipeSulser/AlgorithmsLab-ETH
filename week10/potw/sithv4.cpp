#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include <CGAL/Triangulation_face_base_with_info_2.h>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_vertex_base_with_info_2<int,K> Vb;
typedef CGAL::Triangulation_face_base_2<K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds> Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;
typedef Triangulation::Vertex_handle Vertex_handle;
typedef Triangulation::Face_handle Face_handle;
typedef Triangulation::Finite_vertices_iterator VertexIt;
typedef Triangulation::Vertex_circulator VertexCir;


int dfs(Vertex_handle vi, K::FT rad, vector<int> & components, Triangulation & trs){
  int val = 1;
  VertexCir cir = trs.incident_vertices(vi);
  do{
    if(!trs.is_infinite(cir)){
      //if dist <= rad
      if(CGAL::squared_distance(cir->point(), vi->point()) <= rad){
        if(components[cir->info()] == -1){
          components[cir->info()] = components[vi->info()];
          val += dfs(cir,rad,components,trs);
        }
      }
    }
  }while(++cir != trs.incident_vertices(vi));
  return val;
}
void do_calc()
{

  int n;
  K::FT rad;
  cin>>n>>rad;
  rad = rad*rad;

  if(rad == 0){
    cout<<1<<endl;
    return;
  }

  vector<pair<K::Point_2,int> > planets(n);
  for(int i = 0; i < n; i++){
    K::Point_2 p1;
    cin>>p1;
    planets[i] = make_pair(p1,i); // we need to keep track of its index
  }

  //now we try to find the first planet that we can conquer without interferring with the empire
  int lmin = 0;
  int lmax = n-1;
  vector<int> components(n,0);
  while(lmin < lmax){
    int med = (lmin+lmax)/2;
    Triangulation trs;
    trs.insert(planets.begin()+med,planets.end());
    //lets see how many we can conquer in this subset
    for(int i = med; i < n; i++){
      components[i] = -1;
    }
    int maxval = 1;
    int label = 1;
    for(auto vi = trs.finite_vertices_begin(); vi != trs.finite_vertices_end(); vi++){
      if(components[vi->info()] == -1){
        components[vi->info()] = label;

        int numvals = dfs(vi,rad,components,trs);
        maxval = std::max(maxval,numvals);
      }
    }
    if(maxval >= med){
      lmin = med+1;
    }else{
      lmax = med;
    }
  }
  cout<<lmin-1<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)do_calc();
  return 0;
}