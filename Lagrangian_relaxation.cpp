#include <bits/stdc++.h>
#include "subproblem.cpp"
#include "MLTA.cpp"
#include "MDNA.cpp"
#include "variables.cpp"
#include "input.cpp"
#include "MLTA_input.cpp"
#include "multiplier_update.cpp"

using namespace std;

//intialize the variables
int in = inputs();

//Intailize the object variables
int in_o = input_objects();


// Initialize the environment
void InitializeEnvironment() {
  LB = -1000.0;
  UB = MDNA(aps[2]);
  scalar = 2.0;
  osc_ctr = 0;
  cvg_ctr = 0;
  iteration = 0;
}

// Calculate the LU subproblem
double LU() {
  double sum = subproblem1() + subproblem2() + subproblem3() + subproblem4()
                + subproblem5() + subproblem6() + subproblem7() 
                +subproblem8() +subproblem9() + subproblem10();
  return sum;
}

// The main function
int main() {
  InitializeEnvironment();

  // Start the LR algorithm
  while (cvg_ctr < LR_CVG_DEGREE && LB < UB && iteration < MAX_LR_ITERATION) {
    // Calculate the LU subproblem
    double LU_val = LU();

    // If LB is better than Tightest_LB, then update Tightest_LB and reset osc_ctr
    if (LB < LU_val) {
      LB = LU_val;
      osc_ctr = 0;
    } else {
      // Increase osc_ctr
      osc_ctr++;

      // If osc_ctr > LR_OSC_DEGREE, then divide scalar by 2 and reset osc_ctr and cvg_ctr
      if (osc_ctr > LR_OSC_DEGREE) {
        scalar /= 2.0;
        osc_ctr = 0;
        cvg_ctr++;
      }
    }

    // Get a primal feasible solution
    UB = MLTA(aps[2]);

    // Update the multiplier
    mult1();
    mult2();
    mult3();
    mult4();
    mult5();
    mult6();
    mult7();
    mult8();
    mult9();
    mult10();
    mult11();
    mult12();
    mult13();
    mult14();

    // Increase iteration
    iteration++;

    cout<<LB<<" "<<UB<<endl;
  }

  // Print the result
  cout << "The optimal solution is: " << LB << endl;

  return 0;
}
