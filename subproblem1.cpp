#include<bits/stdc++.h>

using namespace std;

int subproblem1(vector<double> tolerable_delay, vector<double> muv1){

    double d = 0;

    double sum = 0;

    int size = muv1.size();

    for(int i=0; i<size; i++){
        
        sum += muv1[i];
    }

    if(1-sum<0){

        return 0;
    }

    double val = INT_MAX;

    for(int i=0; i < muv1.size(); i++){
        
        val = min(val, -1*(tolerable_delay[i]));
    }

    d = (1-sum)*val;

    return d;
}


