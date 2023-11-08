#include <bits/stdc++.h>

using namespace std;

double subproblem5(vector<vector<double>> muv5, vector<vector<double>> muv11, vector<double> muv12, vector<vector<double>> muv7, vector<vector<double>> muv8, double N1, double N2, vector<vector<double>> &delta_uv){

    int md_size = muv12.size();
    int ap_size = muv5.size();

    double sum_u12 = 0;

    for(int i = 0; i < md_size; i++){

        sum_u12 += muv12[i];
    }

    double sum_uv = 0;

    for(int i = 0; i < ap_size; i++){

        for(int j = 0; j < md_size; j++){

            sum_uv += (muv5[i][j] + muv11[i][j] + muv7[i][j]*N1 + muv8[i][j]*N2);
        }
    }

    double tot_sum = sum_uv - sum_u12;

    vector<double> val(md_size);

    for(int i = 0; i < ap_size; i++){

        for(int j = 0; i < md_size; j++){

            val[j] += (tot_sum - muv7[i][j]*N1 - muv8[i][j]*N2);
        }
    }

    double res = INT_MAX;

    for(int i = 0; i < md_size; i++){

        res = min(res, val[i]);
    }

    return res;
}