#include<bits/stdc++.h>
#include "variables.cpp"

using namespace std;

int subproblem1(){

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
        
        val = min(val, -1*(Tv[i]));
    }

    d = (1-sum)*val;

    return d;
}

// dv = transmission delay
// tv = tolerable delay
// cv = need to be calculated from equation 13 14 and 15

double subproblem2()
{
    int size1 = muv1.size(); //no_of_mobile_devices
    int size2 = muv8.size(); //no_of_aps
    vector<double> sum(size1, 0);
    

    for(int i=0; i< size1; i++){


        for(int j=0; j<size2; j++){
            sum[i] +=muv8[j][i];
        }

        if(muv1[i] - sum[i] >= 0){
            dv[i] = cv[i];
        }else{
            dv[i] = Tv[i];
        }

        sum[i] *= dv[i];
    }

    double val = INT_MAX;

    for(int i=0; i<size1; i++){

        val = min(val, sum[i] - muv1[i]*Tv[i]);
    }

    return val;
}

double subproblem3(){

    int md_size = muv2.size();
    int h_size = n_hu.size();
    int ap_size = n_hu[0].size();

    vector<double> sum(ap_size);
    
    double val = INT_MAX;

    for(int i = 0; i < ap_size; i++){

        sum[i] += (muv2[i] + muv14[i]);

        double sum_nhu = 0;
        for(int j = 0; j < n_hu.size(); j++){

            sum_nhu += n_hu[j][i];
        }
        sum[i] *= sum_nhu;

        val = min(val, sum[i]);
    }

    return val;
}

double subproblem4(){

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
            alpha_u[i] = 1;
        }else{
            alpha_u[i] = 0;
        }

        val = min(val, sol*alpha_u[i]);
    }

    return val;
}

double subproblem5(){

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

double function_buv(double buv){
    return 0;
}

double subproblem6(){
    double val = INT_MAX;

    int no_of_aps = b_uv.size();
    int no_of_mds = b_uv[0].size();

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            double term1 = (muv9[i][j]/M1) - (muv10[i][j]/kth) +muv13[i][j];

            double fbuv = function_buv(b_uv[i][j]);

            val = min(val, term1*b_uv[i][j] - ((muv9[i][j]*kth)/M1) - (muv6[i][j]*fbuv));
        }
    }

    return val;
}

double subproblem7(){
    double val = INT_MAX;

    int no_of_aps = n_uv.size();
    int no_of_mds = n_uv[0].size();

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            double ans = (-1*muv9[i][j]) + muv10[i][j] + (-1*muv5[i][j]);

            if(ans<0){
                n_uv[i][j] = 1; 
            }
            else{
                n_uv[i][j] = 0;
            }

            val = min(val, ans*n_uv[i][j]);
        }

        return val;
    }
}

double subproblem8(){
    int no_of_aps = muv3.size();
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

        val = min(val,((-1*muv3[i]) + muv4[i] - y)*pu[i]);
        
    }

    return val;
}

double subproblem9(){

    int ap_size = muv6.size();
    int md_size = cv.size();

    double val = INT_MAX;

    for(int i = 0; i < ap_size; i++){

        double sum = 0;
        for(int j = 0; j < md_size; j++){

            sum = muv6[i][j]*cv[j] + (muv7[i][j]*gamma_v[j])/cv[j] + muv7[i][j]*omega;
        }

        val = min(val, sum);
    }

    return val;
}

double subproblem10(){

    int md_size = muv7[0].size();
    int ap_size = muv7.size();

    

    double val = INT_MAX;
    
    for(int i = 0; i < ap_size; i++){

        double sum_uk = 0;
        for(int j = 0; j < md_size; j++){

            for(int k = 0; k < md_size; k++){
                if(delta_uv[i][j] == 1)
                    sum_uk += muv8[i][k];
            }
            
            sum_uk -= muv7[i][j];

           if(sum_uk < 0){
                d_uv[i][j] = Tv[j];
            }
            else{

                d_uv[i][j] = 0;
            }


            sum_uk *= d_uv[i][j];

        }        
        
        val = min(val, sum_uk); 
    }
    
    return val;
}