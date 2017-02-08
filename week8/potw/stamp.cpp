#include <iostream>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <vector>
using namespace std;

// choose exact integral type
typedef CGAL::Gmpzf ET;

typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Segment_2 S;
// program and solution types
typedef CGAL::Quadratic_program<double> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

void do_calc(){
  int l,s,w;
  cin>>l>>s>>w;
  vector<P> lamp(l);

  for(int i = 0; i < l; i++){
    cin>>lamp[i];
  }
  vector<P> stamp(s);
  vector<int> max_brightness(s);
  for(int i = 0; i < s; i++){
      cin>>stamp[i];
      cin>>max_brightness[i];
  }
  vector<S> walls;

  for(int i = 0; i < w; i++){
    P p1,p2;
    cin>>p1>>p2;
    walls.push_back(S(p1,p2));
  }
   Program lp (CGAL::SMALLER, true, 1, true, 4096);
  for(int st_ix = 0; st_ix < s; st_ix++){
    for(int l_ix = 0; l_ix < l; l_ix++){
      S light_seg(lamp[l_ix],stamp[st_ix]);
      bool isBlocked = false;
      for(int k = 0; k < w; k++){
        if(CGAL::do_intersect(light_seg,walls[k])){
          isBlocked = true;
          break;
        }
      }
      if(!isBlocked){
        double dist = CGAL::to_double(1/light_seg.squared_length());
        //cout<<dist<<endl;
        lp.set_a(l_ix,st_ix,dist);
        lp.set_a(l_ix,s+st_ix,dist);
      }

    }
    lp.set_b(st_ix,max_brightness[st_ix]);
    lp.set_b(st_ix+s,1);
    lp.set_r(st_ix+s,CGAL::LARGER);
  }
  Solution sol = CGAL::solve_linear_program(lp,ET());
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
