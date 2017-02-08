// example: decide whether there exists a disk that covers a given set
// of points R in the plane and is disjoint from another set of points B
#include <iostream>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <vector>
#include <CGAL/Gmpzf.h>

// choose exact integral type
typedef CGAL::Gmpz ET;

using namespace std;

// program and solution types
typedef CGAL::Quadratic_program<double> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

int floor_to_double(const CGAL::Quotient<ET>& x){
  double a = floor(CGAL::to_double(x));
  while(a > x) a-=1;
  while(a+1 <= x) a+=1;
  return a;
}

void do_calc(int n, int m){
  Program lp(CGAL::SMALLER,true,0,false,0);
  int constraints = 0; //index of constraints
  vector<int> min_q(n);
  vector<int> max_q(n);
  for(int i = 0; i < n; i++){
    int min_i,max_i;
    cin>>min_i>>max_i;
    min_q[i] = min_i;
    max_q[i] = max_i;
  }
  vector<int> price_arr(m);
  vector<vector<int> > quantities(m,vector<int>());
  for(int i = 0; i < m; i++){
    int price;
    cin>>price;
    price_arr[i] = price;
    vector<int> qa(n);
    for(int j = 0; j < n; j++){
      int nut_j;
      cin>>nut_j;
      qa[j] = nut_j;
    }
    quantities[i] = qa;
  }


  for(int i = 0; i < m; i++){
    lp.set_c(i,price_arr[i]);
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      lp.set_a(j,constraints,quantities[j][i]);
    }
    lp.set_b(constraints,max_q[i]);
    constraints++;
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      lp.set_a(j,constraints,-quantities[j][i]);
    }
    lp.set_b(constraints,-min_q[i]);
    constraints++;
  }
  Solution s = CGAL::solve_nonnegative_quadratic_program(lp, ET());
  if(s.is_optimal()){
    cout<<floor_to_double(s.objective_value())<<endl;
  }
  else{
    cout<<"No such diet."<<endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  while(true){
      int n,m;
      cin>>n>>m;
      if(n == 0 && m == 0){
        break;
      }

      do_calc(n,m);
    }

    return 0;
}
