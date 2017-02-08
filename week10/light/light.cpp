#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Edge_iterator  Edge_iterator;

void do_calc(){
  int m,n;
  cin>>m>>n;
  //m is num participants
  //n is num lamps
  vector<K::FT> radiuses(m);
  vector<K::Point_2> participants(m);

  for(int i = 0; i < m; i++){
    cin>>participants[i];
    cin>>radiuses[i];
  }

  int h;
  cin>>h;
  int radius = h;
  //rad = h/tan(45) = h
  vector<K::Point_2> lamps(n);
  for(int i = 0; i < n; i++){
    cin>>lamps[i];
  }
  //now for each participant, see nearest light
    Triangulation trs;
    trs.insert(lamps.begin(), lamps.end());

  int max_light_hit = -1;
  vector<int> min_light_hit(m,INT_MAX);

  for(int i = 0; i < m; i++){
    //for each participant
    K::Point_2 curr_partic = participants[i];
    K::Point_2 nearest_lamp = trs.nearest_vertex(curr_partic)->point();
    double max_dist_sq = std::pow(1.0*(radius+radiuses[i]),2);

    if(max_dist_sq <= CGAL::squared_distance(curr_partic,nearest_lamp)){
      continue;
    }
    for(int j = 0; j < n; j++){
      if(max_dist_sq > CGAL::squared_distance(lamps[j],curr_partic)){
        min_light_hit[i] = j;
        max_light_hit = max(max_light_hit,j);
        break;
      }
    }

  } 
  //cout<<m<<endl;

  vector<int> rank_list;
  for(int i = 0; i < m; i++){
    //cout<<min_light_hit[i]<<endl;
    if(min_light_hit[i] == INT_MAX){
      rank_list.push_back(i);
    }
  }
  if(rank_list.size() <= 0){
    for(int i = 0; i < m; i++){
      if(min_light_hit[i] == max_light_hit){
        rank_list.push_back(i);
      }
    }
  }
  std::sort(rank_list.begin(),rank_list.end());
  for(int i = 0; i < rank_list.size(); i++){
    cout<<rank_list[i]<<" ";
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
