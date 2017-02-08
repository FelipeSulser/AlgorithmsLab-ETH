#include <iostream>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>
#include <vector>
using namespace std;
// choose exact floating-point type
typedef CGAL::Gmpz ET;

// program and solution types
typedef CGAL::Quadratic_program<ET> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;



bool can_solve(int d, vector<int> & x_healthy, vector<int> & y_healthy, vector<int> & z_healthy, vector<int> & x_tumor, vector<int> & y_tumor, vector<int> & z_tumor){

  // by default, we have a QP with Ax >= b
  Program qp (CGAL::LARGER, false, 0, false, 0);
  for(int cell = 0; cell < x_healthy.size(); cell++){
    int var_index = 0;
    for(int x_dim = 0; x_dim <= d; x_dim++){
      for(int y_dim = 0; y_dim <= d; y_dim++){
        for(int z_dim = 0; z_dim <= d; z_dim++){
          if(x_dim+y_dim+z_dim <= d){
            double val = pow(x_healthy[cell],x_dim)*pow(y_healthy[cell],y_dim)*pow(z_healthy[cell],z_dim);
            qp.set_a(var_index,cell,val);
            var_index++;
          }else{
            break;
          }
        }
      }
    }
    qp.set_r(cell,CGAL::LARGER);
    qp.set_b(cell,1); //separate
  }

  for(int cell = 0; cell < x_tumor.size(); cell++){
     int var_index = 0;
      for(int x_dim = 0; x_dim <= d; x_dim++){
        for(int y_dim = 0; y_dim <= d; y_dim++){
          for(int z_dim = 0; z_dim <= d; z_dim++){
            if(x_dim+y_dim+z_dim <= d){
              double val = pow(x_tumor[cell],x_dim)*pow(y_tumor[cell],y_dim)*pow(z_tumor[cell],z_dim);
              qp.set_a(var_index,cell+x_healthy.size(),val);
              var_index++;
            }else{
              break;
            }
          }
        }
      }
    qp.set_r(cell+x_healthy.size(),CGAL::SMALLER);
    qp.set_b(cell+x_healthy.size(),-1); //separate
  }

 
  // solve the program, using ET as the exact type
  CGAL::Quadratic_program_options options;
  options.set_pricing_strategy(CGAL::QP_BLAND);
  Solution sol = CGAL::solve_quadratic_program(qp, ET(),options);
  if(sol.is_infeasible()){
    return false;
  }else{
    return true;
  }
}
void do_calc() {

  int h,t;
  cin>>h>>t;
  //h is number of cells that are healthy
  //t is number of tumorous cells

  vector<int> x_healthy(h);
  vector<int> y_healthy(h);
  vector<int> z_healthy(h);
  for(int i = 0; i < h; i++){
    cin>>x_healthy[i];
    cin>>y_healthy[i];
    cin>>z_healthy[i];
  }
  vector<int> x_tumor(t);
  vector<int> y_tumor(t);
  vector<int> z_tumor(t);
  for(int i = 0; i < t; i++){
    cin>>x_tumor[i];
    cin>>y_tumor[i];
    cin>>z_tumor[i];
  }
  int dim_iter = 1;
  bool exp_found = false;

  do{
    dim_iter = dim_iter*2;
    exp_found = true;
  }while(dim_iter <= 30 && !can_solve(dim_iter,x_healthy,y_healthy,z_healthy,x_tumor,y_tumor,z_tumor));

  int lmin = 1;
  int lmax = 30;
  if(exp_found){
    lmax = dim_iter > 30 ?30:dim_iter;
    lmin = dim_iter/2-1;
  }
  bool found_sol = false;
  while(lmin < lmax){
    int med = (lmin+lmax)/2;
    if(can_solve(med,x_healthy,y_healthy,z_healthy,x_tumor,y_tumor,z_tumor)){
      lmax = med;
      found_sol = true;
    }else{
      lmin = med+1;
      found_sol = false;
    }
  }
  if(lmin == 30 && !found_sol){
    cout<<"Impossible!"<<endl;
  }else{
    cout<<lmin<<endl;
  }
  
}

int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)do_calc();
  return 0;

}
