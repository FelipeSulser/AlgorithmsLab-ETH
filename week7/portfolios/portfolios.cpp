#include <iostream>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>
#include <vector>
// choose exact floating-point type

using namespace std;
typedef CGAL::Gmpzf ET;

// program and solution types
typedef CGAL::Quadratic_program<double> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;


void do_calc(int n, int m){
  //n number of assets
  //m people that want a portfolio
  vector<int> cost(n);
  vector<int> returnval(n);

  for(int i = 0; i < n; i++){
    int c,r;
    cin>>c>>r;
    cost[i] = c;
    returnval[i] = r;
  }
  vector<vector<int> > cov(n,vector<int>(n,-0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>>cov[i][j];
    }
  }

  for(int i = 0; i < m; i++){
    int C,R,V;
    cin>>C>>R>>V;
    Program qp (CGAL::LARGER, true, 0, false, 0);
    int constraint = 0;
    for(int i = 0; i < n; i++)
    {
      qp.set_a(i,constraint,returnval[i]);
    }
    qp.set_b(constraint,R);
    constraint++;

    for(int i = 0; i <n; i++){
      qp.set_a(i,constraint,cost[i]);
    }
    qp.set_b(constraint,C);
    qp.set_r(constraint,CGAL::SMALLER);
    constraint++;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        qp.set_d(i,j,2*cov[i][j]);
      }
    }
     Solution s = CGAL::solve_quadratic_program(qp, ET());
    if(s.is_optimal() && s.objective_value() <= V){
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