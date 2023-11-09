#include <bits/stdc++.h>
#include "subgradient_vectors.cpp"
#include "Lagrangian_relaxation.cpp"

using namespace std;

void mult1(vector<double> mu1, double Zip, double Zd){

    int size = mu1.size();
    double lamda = 2;
    double norm1 = v1(dv, Tv, d, k1);
    double old_ub;
    mu1[0] = 0;

    vector<double> t1(14, 0);

    for(int i = 0; i < 14; i++){

        t1[i] = (lamda*(Zip - Zd))/norm1;
    }

    for(int i = 0; i < 13; i++){
6
        mu1[i+1] =  mu1[i] + t1[i]*k1[i];
    }
}