#include <bits/stdc++.h>

using namespace std;

// Define the constants
const int LR_CVG_DEGREE = 5;
const int LR_OSC_DEGREE = 3;
const int MAX_LR_ITERATION = 10;
const int no_of_mobile_devices = 50;
const int no_of_aps = 5;

// Define the variables
double LB, UB, scalar;
int osc_ctr, cvg_ctr, iteration;

//Lagrange Multipliers
vector<double> muv1(no_of_mobile_devices, 0);
vector<double> muv2(no_of_aps, 0);
vector<double> muv3(no_of_aps, 0);
vector<double> muv4(no_of_aps, 0);
vector<vector<double>> muv5(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> muv6(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> muv7(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> muv8(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> muv9(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> muv10(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> muv11(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<double> muv12(no_of_aps, 0);
vector<vector<double>> muv13(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<double> muv14(no_of_aps, 0);

//subgradient vectors
vector<double> k1(no_of_mobile_devices, 0);
vector<double> k2(no_of_aps, 0);
vector<double> k3(no_of_aps, 0);
vector<double> k4(no_of_aps, 0);
vector<vector<double>> k5(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> k6(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> k7(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> k8(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> k9(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> k10(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<vector<double>> k11(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<double> k12(no_of_aps, 0);
vector<vector<double>> k13(no_of_aps, vector<double>(no_of_mobile_devices, 0));
vector<double> k14(no_of_aps, 0);

vector<double> Tv;
vector<double> dv;
vector<double> alpha_u;
vector<vector<double>> d_uv;


// Initialize the environment
void InitializeEnvironment() {
  LB = -1000.0;
  UB = 2000.0;  //MDNA()
  scalar = 2.0;
  osc_ctr = 0;
  cvg_ctr = 0;
  iteration = 0;
}

// Calculate the LU subproblem
double LU(double x) {
  //Summation of all solved subproblems
  // TODO: Implement the LU subproblem here
  return x;
}



// Update the multiplier
void update_multiplier(double scalar, int iteration) {
  // TODO: Implement the update_multiplier function here


    
}

// Get a primal feasible solution
double MLTA() {
  // TODO: Implement the MLTA function here
  return 0.0;
}

// The main function
int main() {
  InitializeEnvironment();

  // Start the LR algorithm
  while (cvg_ctr < LR_CVG_DEGREE && LB < UB && iteration < MAX_LR_ITERATION) {
    // Calculate the LU subproblem
    double LU_val = LU(UB);

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
    UB = MLTA();

    // Update the multiplier
    update_multiplier(scalar, iteration);

    // Increase iteration
    iteration++;
  }

  // Print the result
  cout << "The optimal solution is: " << LB << endl;

  return 0;
}
