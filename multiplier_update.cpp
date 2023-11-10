#include <bits/stdc++.h>
#include "subgradient_vectors.cpp"
#include "Lagrangian_relaxation.cpp"

using namespace std;

double lambda = 2;

void mult1(){

    double norm = v1(dv, Tv, d, k1);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i = 0; i < no_of_mds; i++){

        muv1[i] = muv1[i] + step_size*k1[i];
    }
}

void mult2(){

    double norm = v2(alpha_u, n_hu, k2);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i = 0; i < no_of_mds; i++){

        muv2[i] = muv2[i] + step_size*k2[i];
    }
}

void mult3(){

    double norm = v3(alpha_u, pu, pmin, k3);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i = 0; i < no_of_mds; i++){

        muv3[i] = muv3[i] + step_size*k3[i];
    }
}

void mult4(){

    double norm = v4(alpha_u, pu, pmax, k4);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i = 0; i < no_of_mds; i++){

        muv4[i] = muv4[i] + step_size*k4[i];
    }
}

void mult5(){
    double norm = v5(d_uv, n_uv, k5);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            muv5[i][j] = muv5[i][j] + step_size*k5[i][j];
        }
    }
}

void mult6(){
    double norm = v6(cv, f_buv, k6);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            muv6[i][j] = muv6[i][j] + step_size*k6[i][j];
        }
    }
}

void mult7(){
    double norm = v7(gamma_v, cv, omega, d_uv, N2, dv, k7);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            muv7[i][j] = muv7[i][j] + step_size*k7[i][j];
        }
    }
}

void mult8(){
    double norm = v8(delta_uv, d_uv, N2, dv, k8);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            muv5[i][j] = muv5[i][j] + step_size*k8[i][j];
        }
    }
}

void mult9(){
    double norm = v9(b_uv, kth, M1, n_uv, k9);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            muv5[i][j] = muv5[i][j] + step_size*k9[i][j];
        }
    }
}

void mult10(){
    double norm = v10(n_uv, b_uv, kth, k10);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            muv5[i][j] = muv5[i][j] + step_size*k10[i][j];
        }
    }
}

void mult11(){
    double norm = v11(d_uv, a_u, k11);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            muv5[i][j] = muv5[i][j] + step_size*k11[i][j];
        }
    }
}

void mult12(){

    double norm = v12(a_u, d_uv, k12);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i = 0; i < no_of_mds; i++){

        muv1[i] = muv1[i] + step_size*k12[i];
    }
}

void mult13(){
    double norm = v13(b_uv, sinr_uv, k13);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            muv5[i][j] = muv5[i][j] + step_size*k13[i][j];
        }
    }
}

void mult14(){

    double norm = v14(n_hu, alpha_u, k14);

    double step_size = lambda*(Z_Ip - Z_D)/norm;

    for(int i = 0; i < no_of_mds; i++){

        muv1[i] = muv1[i] + step_size*k14[i];
    }
}


