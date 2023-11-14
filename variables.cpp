#include<bits/stdc++.h>

using namespace std;

// Define the constants
const int LR_CVG_DEGREE = 5;
const int LR_OSC_DEGREE = 3;
const int MAX_LR_ITERATION = 10;
const int no_of_mds = 43;
const int no_of_aps = 5;

// Define the variables
double LB, UB, scalar;
int osc_ctr, cvg_ctr, iteration;

//Lagrange Multipliers
vector<double> muv1(no_of_mds, 0);
vector<double> muv2(no_of_aps, 0);
vector<double> muv3(no_of_aps, 0);
vector<double> muv4(no_of_aps, 0);
vector<double> muv12(no_of_aps, 0);
vector<double> muv14(no_of_aps, 0);
vector<vector<double>> muv5(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> muv6(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> muv7(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> muv8(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> muv9(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> muv10(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> muv11(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> muv13(no_of_aps, vector<double>(no_of_mds, 0));

//subgradient vectors
vector<double> k1(no_of_mds, 0);
vector<double> k2(no_of_aps, 0);
vector<double> k3(no_of_aps, 0);
vector<double> k4(no_of_aps, 0);
vector<double> k12(no_of_aps, 0);
vector<double> k14(no_of_aps, 0);
vector<vector<double>> k5(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> k6(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> k7(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> k8(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> k9(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> k10(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> k11(no_of_aps, vector<double>(no_of_mds, 0));
vector<vector<double>> k13(no_of_aps, vector<double>(no_of_mds, 0));

//Constraints and variables
double d;
double Z_Ip=0;
double Z_D=0;
double N2;
double N1;
double pmin; //min power range
double kth;
double M1;
double pmax; //max power range
double omega;

//tolerable delay of mobile device v
vector<double> Tv;
//transmission delay of a mobile device v
vector<double> dv; 
//binary decision variable to determine AP u is switched on or not
vector<double> alpha_u; 
//power range of an AP u
vector<double> pu; 
//traffic requirements of mobile device v
vector<double> gamma_v; 
//capacity of mobile b
vector<double> cv; 
vector<vector<double>> f_buv; 
vector<vector<double>> sinr_uv; 
vector<vector<double>> b_uv; 
//binary variable determines if channel h is assciated with AP u
vector<vector<double>> n_hu; 
//binary variable determines if Mobile device v is assciated with AP u
vector<vector<double>> delta_uv;
//transmission delay between and AP u and mobile device v
vector<vector<double>> d_uv; 
//bainary variable determines if MD v is in service area of AP u
vector<vector<double>> n_uv;
//distance between AP u and mobile device v
vector<vector<double>> distance_uv;
vector<double> channel;
vector<double> h;

// class AP {
// public:
//   int id;
//   double power_range;
//   vector<MD> connected_MDs;
//   int switched_on;
//   bool isBroken;
  
// //   bool markedAp;
//   AP(){
//     id = -1;
//   }

//   AP(int id, double power_range) {
//     this->id = id;
//     this->power_range = power_range;
//   }

//   void addConnectedMD(MD md) {
//     connected_MDs.push_back(md);
//   }

//   void removeConnectedMD(MD md) {
//     connected_MDs.erase(remove(connected_MDs.begin(), connected_MDs.end(), md), connected_MDs.end());
//   }
// };


// // MD class
// class MD {
// public:
//   int id;
//   AP current_ap;
//   bool marked;
//   double traffic_requirement;
//   vector<AP> candidate_aps;

//   MD(){
//     id = -1;
//   }

//   MD(int id, AP current_ap) {
//     this->id = id;
//     this->current_ap = current_ap;
//   }

//   void addCandidateAP(AP ap) {
//     candidate_aps.push_back(ap);
//   }

//   void removeCandidateAP(AP ap) {
//     candidate_aps.erase(remove(candidate_aps.begin(), candidate_aps.end(), ap), candidate_aps.end());
//   }

//   double getDelayGap() {
//     // Get delay gap between current AP and candidate APs.
//     double min_delay_gap = -1;
//     for (AP candidate_ap : candidate_aps) {
//       double delay_gap = getDelayGap(candidate_ap);
//       if (min_delay_gap == -1 || delay_gap < min_delay_gap) {
//         min_delay_gap = delay_gap;
//       }
//     }
//     return min_delay_gap;
//   }

//   private:
//     double getDelayGap(AP ap) {
//       // Calculate delay gap between current AP and candidate AP.
//         return 0;
//     }
// };