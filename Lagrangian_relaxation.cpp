#include <bits/stdc++.h>
#include "subproblem.cpp"
#include "MLTA.cpp"
#include "MDNA.cpp"
#include "variables.cpp"

using namespace std;



// Initialize the environment
void InitializeEnvironment() {
  LB = -1000.0;
  // UB = MDNA();
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
    // UB = MLTA();

    // Update the multiplier
    // update_multiplier(scalar, iteration);

    // Increase iteration
    iteration++;
  }

  // Print the result
  cout << "The optimal solution is: " << LB << endl;

  return 0;
}
