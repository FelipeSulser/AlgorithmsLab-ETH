#include <iostream>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>
#include <vector>


using namespace std;

// choose exact floating-point type
typedef CGAL::Gmpzf ET;

// program and solution types
typedef CGAL::Quadratic_program<double> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

void do_calc(int n, int m){

  vector<int> cost(n);
  vector<int> ret(n);
  for(int i = 0; i < n; i++){
    int ci,ri;
    cin>>ci>>ri;
    cost[i] = ci;
    ret[i] = ri;
  }
  vector<vector<int> > cov(n,vector<int>(n,0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>>cov[i][j];
    }
  }
  for(int i = 0; i <m; i++){
    int C,R,V;
    cin>>C>>R>>V;

    Program qp(CGAL::LARGER,true,0,false,0);
    //set the goal of min variance
   // qp.set_d(val,eq_num,coeff*2);
    for(int i =0; i < n; i++){
      for(int j = 0;  j < n; j++){
        qp.set_d(i,j,2*cov[i][j]);
      }
    }
    //now set the requirements
    //sum of costs cannot be greater than c
    //and return min
    for(int i = 0; i < n; i++){
      qp.set_a(i,0,ret[i]);
    }

    qp.set_b(0,R); //at least ret R
    for(int i = 0; i < n; i++){
      qp.set_a(i,1,cost[i]);
    }
    qp.set_b(1,C);
    qp.set_r(1,CGAL::SMALLER);
    Solution s = CGAL::solve_quadratic_program(qp, ET());
    assert (s.solves_quadratic_program(qp));
    if(s.is_optimal()&&CGAL::to_double(s.objective_value()) <= V){
      cout<<"Yes."<<endl;
    }else{
      cout<<"No."<<endl;
    }


  }

}

int main(){
  ios_base::sync_with_stdio(false);
  while(true){
    int n,m;
    cin>>n>>m;
    if(n == 0 && m == 0) return 0;
    do_calc(n,m);
  }
  return 0;
}