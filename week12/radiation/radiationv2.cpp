#include <iostream>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>

#include <vector>

using namespace std;
// choose exact integral type
typedef CGAL::Gmpzf ET;

// program and solution types
typedef CGAL::Quadratic_program<ET> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

bool can_separate(int dim, vector<int> & healthy_x,vector<int>& healthy_y, vector<int> & healthy_z, vector<int> & tumor_x, vector<int> & tumor_y, vector<int> & tumor_z){
   Program lp (CGAL::SMALLER, false, 0, false, 0);
  
 for(int h_c = 0; h_c < healthy_y.size(); h_c++){
  int var_index = 0;
  for(int dim_x = 0; dim_x <= dim; dim_x++){
    for(int dim_y = 0; dim_y <= dim; dim_y++){
      for(int dim_z = 0; dim_z<= dim; dim_z++){
        if(dim_x + dim_y + dim_z > dim) break;
        double val = std::pow(healthy_x[h_c],dim_x)*std::pow(healthy_y[h_c],dim_y)*std::pow(healthy_z[h_c],dim_z);
        lp.set_a(var_index,h_c,val);
        var_index++;
      }
    }
  }
  lp.set_b(h_c,1);
  lp.set_r(h_c,CGAL::LARGER);
 }

 for(int t_c = 0; t_c < tumor_x.size(); t_c++){
  int var_index = 0;
  for(int dim_x = 0; dim_x <= dim; dim_x++){
    for(int dim_y = 0; dim_y <= dim; dim_y++){
      for(int dim_z = 0; dim_z<= dim; dim_z++){
         if(dim_x + dim_y + dim_z > dim) break;
        double val = std::pow(tumor_x[t_c],dim_x)*std::pow(tumor_y[t_c],dim_y)*std::pow(tumor_z[t_c],dim_z);
        lp.set_a(var_index,t_c+healthy_x.size(),val);
        var_index++;
      }
    }
  }
  lp.set_b(t_c+healthy_x.size(),-1);
 }
 CGAL::Quadratic_program_options options;
 options.set_pricing_strategy(CGAL::QP_BLAND);
  // solve the program, using ET as the exact type
  Solution sol = CGAL::solve_quadratic_program(lp, ET(),options);
 if(sol.is_infeasible()){
  return false;
 }else{
  return true;
 }

}

void do_calc(){

  int H,T;
  cin>>H>>T;

  vector<int> healthy_x(H);
  vector<int> healthy_y(H);
  vector<int> healthy_z(H);
  for(int i = 0; i < H; i++){
    cin>>healthy_x[i]>>healthy_y[i]>>healthy_z[i];
  }

  vector<int> tumor_x(T);
  vector<int> tumor_y(T);
  vector<int> tumor_z(T);
  for(int i = 0; i < T; i++){
    cin>>tumor_x[i]>>tumor_y[i]>>tumor_z[i];
  }

  int dim = 1;

  //find upper bound first by squaring
  bool exp_found = false;
  do{
    dim *= 2;
    exp_found = true;
    //cout<<"stuck1"<<endl;
  }while(dim <= 30 && !can_separate(dim,healthy_x,healthy_y,healthy_z,tumor_x,tumor_y,tumor_z));
  // by default, we have a nonnegative LP with Ax <= b
    int lmin = dim/2-1;
  int lmax = dim;
  if(exp_found){
    lmin = dim/2-1;
    lmax = dim > 30 ? 30: dim;
  }else{
    lmin = 1;
    lmax = 30;
  }
  //now bin search on dim/2 dim
 
  bool sol_found = false;
  while(lmin < lmax){
   // cout<<"stuck"<<endl;
    int mid = (lmin+lmax)/2;
    if(can_separate(mid,healthy_x,healthy_y,healthy_z,tumor_x,tumor_y,tumor_z)){
      lmax = mid;
      sol_found = true;
    }else{
      lmin = mid+1;
      sol_found = false;
    }
  }
 if(lmin == 30 && !sol_found){
  cout<<"Impossible!"<<endl;
 }else{
  cout<<lmin<<endl;
 }
}

int main(){
  int t;
  cin>>t;
  while(t--)do_calc();
  return 0;
}