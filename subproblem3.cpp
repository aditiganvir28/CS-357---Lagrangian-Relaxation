#include <bits/stdc++.h>

using namespace std;

double subproblem3(vector<double> muv2, vector<double> muv14, vector<vector<double>> nhu ){

    int md_size = muv2.size();
    int h_size = nhu.size();
    int ap_size = nhu[0].size();

    vector<double> sum(ap_size);
    
    double val = INT_MAX;

    for(int i = 0; i < ap_size; i++){

        sum[i] += (muv2[i] + muv14[i]);

        double sum_nhu = 0;
        for(int j = 0; j < nhu.size(); j++){

            sum_nhu += nhu[j][i];
        }
        sum[i] *= sum_nhu;

        val = min(val, sum[i]);
    }

    return val;
}