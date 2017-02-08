#include <iostream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>
#include <CGAL/Delaunay_triangulation_2.h>
using namespace std;
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
// choose exact integral type
typedef CGAL::Gmpzf ET;

// program and solution types

typedef CGAL::Quadratic_program<double> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

void do_calc() {

  int A,S,B;
  cin>>A>>S>>B;
  //A is number of particles
  //S is number of laser shots
  //B is number of bounty hunters

  int E;
  cin>>E;

  vector<K::Point_2> particles(A);
  vector<int> densities(A);

  for(int i = 0; i < A; i++){
    cin>>particles[i];
    cin>>densities[i];
  }
  vector<K::Point_2> shot_loc(S);
  for(int i = 0; i < S; i++){
    cin>>shot_loc[i];
  }

  vector<K::Point_2> bhunters(B);
  for(int i = 0; i < B; i++){
    cin>>bhunters[i];
  }
  Triangulation trs;
  trs.insert(bhunters.begin(),bhunters.end());

  vector<K::FT> max_rad(S,INT_MAX);

  for(int i = 0; i < S; i++){
    if(B>0){
      K::FT dist = CGAL::squared_distance(shot_loc[i],trs.nearest_vertex(shot_loc[i])->point());
      max_rad[i] = dist;
    }
  }
  // by default, we have a nonnegative LP with Ax <= b
  Program lp (CGAL::LARGER, true, 0, false, 0);

  for(int i = 0; i < S; i++){
    lp.set_c(i,1);
  }
  for(int i = 0; i < A; i++){
    for(int j = 0; j <  S; j++){
      K::FT dist_to = CGAL::squared_distance(shot_loc[j],particles[i]);
      if(dist_to < max_rad[j]){
        K::FT denom;
        if(dist_to > 0){
          lp.set_a(j,i,1/(CGAL::to_double(dist_to)));
        }else{
          lp.set_a(j,i,1);
        }
      }
    }
    lp.set_b(i,densities[i]);
  }
  // solve the program, using ET as the exact type
  Solution sol = CGAL::solve_linear_program(lp, ET());
  if(sol.is_infeasible() || (sol.objective_value() > E)){
    cout<<"n"<<endl;
  }else{
    cout<<"y"<<endl;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)do_calc();
  return 0;
}
