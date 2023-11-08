#include <bits/stdc++.h>

using namespace std;

double subproblem9(vector<vector<double>> muv6, vector<double> cv, vector< vector<double>> muv7, vector<double> gamma, double w){

    int ap_size = muv6.size();
    int md_size = cv.size();

    double val = INT_MAX;

    for(int i = 0; i < ap_size; i++){

        double sum = 0;
        for(int j = 0; j < md_size; j++){

            sum = muv6[i][j]*cv[j] + (muv7[i][j]*gamma[j])/cv[j] + muv7[i][j]*w;
        }

        val = min(val, sum);
    }

    return val;
}