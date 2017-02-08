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


bool satisfies_conditions(int roi, vector<vector<int> > & cov, vector<int> & cost, vector<int> & ret, int Ci, int Vi, int n){

  Program qp (CGAL::SMALLER, true, 0, false, 0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      qp.set_d(i,j,cov[i][j]*2);
    }
  }

  //restrict total cost
  for(int i = 0; i < n; i++){
    qp.set_a(i,0,cost[i]);
  }
  qp.set_b(0,Ci);

  for(int i = 0; i < n; i++){
    qp.set_a(i,1,ret[i]);
  }
  qp.set_r(1,CGAL::LARGER);
  qp.set_b(1,roi);



  // solve the program, using ET as the exact type
  Solution sol = CGAL::solve_nonnegative_quadratic_program(qp, ET());
  if(sol.is_optimal() && sol.objective_value() <= Vi){
    return true;
  }else{
    return false;
  }
  // output

}
void do_calc(int n, int m) {

  //is number of assets
  //m is number of friends
  vector<int> cost(n);
  vector<int> ret_value(n);
  for(int i = 0; i < n; i++){
    cin>>cost[i];
    cin>>ret_value[i];
  }

  vector<vector<int> > cov(n,vector<int>(n,0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>>cov[i][j];
    }
  }

  for(int i = 0; i < m; i++){
    int Ci,Vi;
    cin>>Ci>>Vi; //max cost allowed and max variance allowed

   int upperbound = 1;
   do{
    upperbound *= 2;
   }while(satisfies_conditions(upperbound,cov,cost,ret_value,Ci,Vi,n));
    
    //now that we have upperbound that does not satisfy, do binsearch
   int lmin = 1;
   int lmax = upperbound;
   while(lmin < lmax){

    int med = (lmin+lmax)/2;
    if(satisfies_conditions(med,cov,cost,ret_value,Ci,Vi,n)){
      lmin = med+1;
    }else{
      lmax =med;
    }
   }
   cout<<lmin-1<<endl;
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
}
