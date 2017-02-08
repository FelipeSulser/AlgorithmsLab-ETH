#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>

// choose exact integral type
using namespace std;
typedef CGAL::Gmpzf ET;

// program and solution types
typedef CGAL::Quadratic_program<double> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Segment_2 Seg;

void do_calc()
{
  int L,S,W;
  cin>>L>>S>>W;
  //L is number of lamps
  //S is number of stamps
  //W is number of walls

  vector<P> lamps(L);
  for(int i = 0; i < L; i++){
    cin>>lamps[i];
  }
  vector<P> stamps(S);
  vector<int> max_intensity(S);
  for(int i = 0; i < S; i++){
    cin>>stamps[i];
    cin>>max_intensity[i];
  }
  vector<Seg> walls(W);
  for(int i = 0; i < W; i++){
    P p1,p2;
    cin>>p1>>p2;
    walls[i] = Seg(p1,p2);
  }

  //now for each stamp for each light see if they intersect
  vector<vector<int> > stamp_gets_light(S);
  for(int i = 0; i < L; i++){
    for(int j = 0; j < S; j++){
      Seg seg(lamps[i],stamps[j]);
      bool isBlocked = false;
      for(int k = 0; k < W; k++){
        if(CGAL::do_intersect(seg,walls[k])){
          
          isBlocked = true;
          break;
        }
      }
      if(!isBlocked){
        stamp_gets_light[j].push_back(i);
      }
    }
  }

  //now for the lp
  Program lp (CGAL::SMALLER, true, 1, true, 4096);
  for(int i = 0; i < S; i++){
    for(int j = 0; j < stamp_gets_light[i].size(); j++){
      K::FT dist = CGAL::squared_distance(stamps[i],lamps[stamp_gets_light[i][j]]);
      lp.set_a(stamp_gets_light[i][j],i,CGAL::to_double(1/dist));
      lp.set_a(stamp_gets_light[i][j],i+S,CGAL::to_double(1/dist));
    }
    lp.set_b(i,max_intensity[i]);
    lp.set_r(i+S,CGAL::LARGER);
    lp.set_b(i+S,1);
  }

   Solution sol = CGAL::solve_linear_program(lp, ET());
  if(sol.is_infeasible()){
    cout<<"no"<<endl;
  }else{
    cout<<"yes"<<endl;
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)do_calc();
  return 0;
}