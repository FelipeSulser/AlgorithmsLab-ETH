#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include <CGAL/Triangulation_face_base_2.h>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_vertex_base_with_info_2<int,K> Vb;
typedef CGAL::Triangulation_face_base_2<K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds> Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;
typedef Triangulation::Face_handle Face_handle;

struct Edge{
public:
  int u,v;
  K::FT sql;
  Edge(int x,int y, K::FT s){
    u = x;
    v = y;
    sql = s;
  }
};

bool compareEdge(Edge & e1, Edge & e2){
  return e1.sql < e2.sql;
}

void do_calc()
{ 
  int n,m;
  K::FT p;
  cin>>n>>m>>p;

  vector<pair<K::Point_2,int> > jammers(n);
  for(int i = 0; i < n; i++){
    K::Point_2 point;
    cin>>point;
    jammers[i] = make_pair(point,i);
  }
  Triangulation trs;
  trs.insert(jammers.begin(), jammers.end());
  vector<K::Point_2> start(m);
  vector<K::Point_2> end(m);

   map<Face_handle,int> mapper;
    for(auto f = trs.finite_faces_begin(); f != trs.finite_faces_end(); f++){
      mapper[f] = -1;
    }


  vector<Edge> edges(3*n);
  for(auto e = trs.finite_edges_begin(); e != trs.finite_edges_end(); e++){
    edges[i] = Edge(e->first->vertex((e->second+1)%3)->info(),
      e->first->vertex((e->second+2)%3)->info(),
      trs.segment(e).squared_length());
  }

  std::sort(edges.begin(),edges.end(),compareEdge);

  for(int i = 0; i < m; i++){
    cin>>start[i];
    cin>>end[i];

    //can we do start to end?
    //if and only if BFS start end and dist <= p/4
    vector<Face_handle> stack;
    K::Point_2 nearest_start = trs.nearest_vertex(start[i])->point();
    K::Point_2 nearest_end = trs.nearest_vertex(end[i])->point();
    Face_handle objective = trs.locate(end[i]);
    if(CGAL::squared_distance(nearest_start,start[i]) > p/4 || CGAL::squared_distance(nearest_end,end[i]) > p/4){
      cout<<"n";
    }else{
       bool found = false;
       Face_handle current = trs.locate(start[i]);
       mapper[current] = i;
       stack.push_back(current);
       while(!stack.empty()){
          current = stack.back();
          stack.pop_back();
          if(current == objective){
            cout<<"y";
            found = true;
            break;
          }
          for(int j = 0; j < 3; j++){
            Face_handle neighbor = current->neighbor(j);
            if(mapper[neighbor] < i && trs.segment(current,j).squared_length() < p/4){
              mapper[neighbor] = i;
              stack.push_back(neighbor);
            }
          }

       }
       if(!found)cout<<"n";
    }
  }
  cout<<endl;
  cout<<4*p<<endl;
  cout<<p<<endl;

  //now find min rad
  //min rad so that 
}


int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cout<<fixed<<setprecision(0);
  cin>>t;
  while(t--)do_calc();
  return 0;
}