#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;
typedef K::Point_2 P;
typedef Triangulation::Face_handle Face_handle;

void do_calc()
{
  int h,w,p;
  cin>>h>>w>>p;
  K::FT sq_dist = p*p;
  K::FT mindist = sq_dist/4;
  int q,s,r,t;
  cin>>q>>r>>s>>t;
  P start(q,r);
  P end(s,t);

  vector<K::Point_2> points;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      char word;
      cin>>word;
      if(word == '0'){
        //
        points.push_back(P(i,j));
        points.push_back(P(i,j+1));
        points.push_back(P(i+1,j));
        points.push_back(P(i+1,j+1));
      }
    }
  }
  set<K::Point_2> setp(points.begin(),points.end());
  vector<K::Point_2> nonrep;
  nonrep.assign(points.begin(),points.end());
    map<Face_handle,bool> mapper;
  Triangulation trs;
  trs.insert(points.begin(), points.end());

  for(auto f = trs.finite_faces_begin(); f != trs.finite_faces_end(); f++){
    mapper[f] = false;
  }
  Face_handle current = trs.locate(start);
  Face_handle target = trs.locate(end);
  P nearest = trs.nearest_vertex(start)->point();
     
  if(CGAL::squared_distance(nearest,start) < mindist){
    cout<<"no"<<endl;
    return;
  }
  vector<Face_handle> stack;
  stack.push_back(current);
  mapper[current] = true;

  while(!stack.empty()){

    Face_handle topval = stack.back();
    stack.pop_back();
    if(trs.is_infinite(topval))continue;
    if(topval == target){
      cout<<"yes"<<endl;
      return;
    }
    for(int j = 0; j < 3; j++){
      Face_handle neighbor = topval->neighbor(j);
      if(trs.segment(topval,j).squared_length() >= mindist && mapper[neighbor] != true){
        mapper[neighbor] = true;
         stack.push_back(neighbor);
      }
    }
  }
  cout<<"no"<<endl;

}
int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)do_calc();
  return 0;
}
