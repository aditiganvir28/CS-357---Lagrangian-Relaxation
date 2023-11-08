#include<bits/stdc++.h>

using namespace std;

double function_buv(double buv){
    return 0;
}

double subproblem6(vector<vector<double>> buv, double kth, double M1, vector<vector<double>> muv9, vector<vector<double>> muv10, vector<vector<double>> muv13, vector<vector<double>> muv19, vector<vector<double>> muv6){
    double val = INT_MAX;

    int no_of_aps = buv.size();
    int no_of_mds = buv[0].size();

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            double term1 = (muv9[i][j]/M1) - (muv19[i][j]/kth) +muv13[i][j];

            double fbuv = function_buv(buv[i][j]);

            val = min(val, term1*buv[i][j] - ((muv9[i][j]*kth)/M1) - (muv6[i][j]*fbuv));
        }
    }

    return val;
}