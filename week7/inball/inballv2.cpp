// example: decide whether there exists a disk that covers a given set
// of points R in the plane and is disjoint from another set of points B
#include <iostream>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>
#include <vector>

using namespace std;


// choose exact integral type
typedef CGAL::Gmpz ET;

// program and solution types
typedef CGAL::Quadratic_program<int> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

void do_calc(int n,int d){
   Program lp (CGAL::SMALLER, false, 0, false, 0);

  for(int i = 0; i < n; i++){
    double norm = 0.0;
    for(int j = 0; j < d; j++){
      int a;
      cin>>a;
      norm += a*a;
      lp.set_a (j, i, a);
    }
    int b;
    cin>>b;
    double norm_norm = std::floor(std::sqrt(norm));
    lp.set_a(d,i,norm_norm);

    lp.set_b(i,b);
  
  }
  lp.set_c(d,-1);
  lp.set_l(d,true,0);
  Solution s = CGAL::solve_linear_program(lp, ET());
  if(s.is_infeasible()){
    cout<<"none"<<endl;
  }else{
    if(s.is_unbounded()){
      cout<<"inf"<<endl;
    }else{
      ET out = -(s.objective_value().numerator()/s.objective_value().denominator());
      cout<<out<<endl;
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  while(true){
    int n;
    cin>>n;
    if(n == 0) return 0;
    int d;
    cin>>d;
    do_calc(n,d);
  }
}

 