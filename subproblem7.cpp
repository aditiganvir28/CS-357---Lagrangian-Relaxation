#include<bits/stdc++.h>

using namespace std;

double subproblem7(vector<vector<double>> &nuv, vector<vector<double>> muv9, vector<vector<double>> muv10, vector<vector<double>> muv5){
    double val = INT_MAX;

    int no_of_aps = nuv.size();
    int no_of_mds = nuv[0].size();

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            double ans = (-1*muv9[i][j]) + muv10[i][j] + (-1*muv5[i][j]);

            if(ans<0){
                nuv[i][j] = 1; 
            }
            else{
                nuv[i][j] = 0;
            }

            val = min(val, ans*nuv[i][j]);
        }

        return val;
    }
}