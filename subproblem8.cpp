#include<bits/stdc++.h>

using namespace std;

double subproblem8(vector<double> mu3, vector<double> mu4, vector<vector<double>> muv13, vector<vector<double>> distance_uv, vector<double> pu){
    int no_of_aps = mu3.size();
    int no_of_mds = muv13[0].size();

    double val = INT_MAX;

    for(int i=0; i<no_of_aps; i++){

        double y = 0;

        for(int k=0; k<no_of_mds; k++){
            double x = 0;

            for(int j=0; j<no_of_aps; j++){
                if(i!=j){
                x += (pu[j] / (distance_uv[i][k]*distance_uv[i][k]));
                }
            }

            y += muv13[i][k] * ((1/((distance_uv[i][k]*distance_uv[i][k])*x)));
        }

        val = min(val,((-1*mu3[i]) + mu4[i] - y)*pu[i]);
        
    }

    return val;
}