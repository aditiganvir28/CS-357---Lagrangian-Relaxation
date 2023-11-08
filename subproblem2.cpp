#include <bits/stdc++.h>

using namespace std;

// dv = transmission delay
// tv = tolerable delay
// cv = need to be calculated from equation 13 14 and 15

double subproblem2(vector<double> muv1, vector<vector<double>> muv8, vector<double> tolerable_delay, vector<double> cv, vector<double> &transmission_delay)
{
    int size1 = muv1.size(); //no_of_mobile_devices
    int size2 = muv8.size(); //no_of_aps
    vector<double> sum(size1, 0);
    

    for(int i=0; i< size1; i++){


        for(int j=0; j<size2; j++){
            sum[i] +=muv8[j][i];
        }

        if(muv1[i] - sum[i] >= 0){
            transmission_delay[i] = cv[i];
        }else{
            transmission_delay[i] = tolerable_delay[i];
        }

        sum[i] *= transmission_delay[i];
    }

    double val = INT_MAX;

    for(int i=0; i<size1; i++){

        val = min(val, sum[i] - muv1[i]*tolerable_delay[i]);
    }

    return val;
}