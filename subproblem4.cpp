#include<bits/stdc++.h>

using namespace std;

double subproblem4(vector<double> muv2, vector<double> muv14, vector<double> muv3, vector<double> muv4, vector<vector<double>> muv11, vector<double> muv12, vector<double> &alpha, double pmin, double pmax){

    int size1 = muv2.size(); //no of aps
    int size2 = muv11[0].size(); //no of mds

    double val = INT_MAX;

    for(int i=0; i<size1; i++){
        
        int sum = 0;

        for(int j=0; j<size2; j++){
            sum += muv11[i][j];
        }

        double sol = muv2[i] - muv14[i] + (muv3[i]*pmin - (muv4[i]*pmax) + muv12[i] - sum);


        if(sol<0){
            alpha[i] = 1;
        }else{
            alpha[i] = 0;
        }

        val = min(val, sol*alpha[i]);
    }

    return val;
}