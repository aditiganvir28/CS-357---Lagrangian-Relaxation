#include <bits/stdc++.h>

using namespace std;

double v1(vector<double> dv, vector<double> Tv, double d, vector<double> &k1)
{

    int no_of_mds = dv.size();

    for (int i = 0; i <no_of_mds; i++){
        k1[i] = dv[i] - Tv[i] - d;
    }

    double ans = 0;

    for(int i=0; i<no_of_mds; i++){
        ans += (k1[i]*k1[i]);
    }
    
    return ans;
}

double v2(vector<double> alpha_u, vector<vector<double>> n_hu, vector<double>& k2){
    int no_of_aps = alpha_u.size();

    for(int i=0; i<no_of_aps; i++){
        
        double sum =0;
        
        for(int j=0; j<n_hu.size(); j++){
            sum += (n_hu[j][i]);
        }

        k2[i] = alpha_u[i] - sum;
    }

    double val = 0;
    
    for(int i=0; i<alpha_u.size(); i++){
        val += (k2[i]*k2[i]);
    }

    return val;
}

double v3(vector<double> alpha_u, vector<double> pu, double pmin, vector<double> &k3){
    int no_of_alphas = alpha_u.size();

    for(int i=0; i<no_of_alphas; i++){
        
        k3[i] = (alpha_u[i]*pmin) - pu[i];
    }

    double val = 0;
    
    for(int i=0; i<alpha_u.size(); i++){
        val += (k3[i]*k3[i]);
    }

    return val;

}

double v4(vector<double> alpha_u, vector<double> pu, double pmax, vector<double> &k4){
    int no_of_alphas = alpha_u.size();

    for(int i=0; i<no_of_alphas; i++){
        
        k4[i] = pu[i] - (alpha_u[i]*pmax);
    }

    double val = 0;
    
    for(int i=0; i<alpha_u.size(); i++){
        val += (k4[i]*k4[i]);
    }

    return val;

}

double v5(vector<vector<double>> duv, vector<vector<double>> nuv, vector<vector<double>> &k5)
{

    int ap_size = duv.size();    
    int md_size = duv[0].size(); 

    for(int i = 0; i < ap_size; i++){

        for(int j = 0; j < md_size; j++){

            k5[i][j] = duv[i][j] - nuv[i][j];

        }
    }

    double norm = 0;

    for(int i=0; i<ap_size; i++){
        for(int j=0; j<md_size; j++){
            norm += (k5[i][j]*k5[i][j]);
        }
    }

    return norm;
}

double v6(vector<double> cv, vector<vector<double>> f_buv, vector<vector<double>> &k6){
    int no_of_aps = f_buv.size();
    int no_of_mds = cv.size();

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            k6[i][j] = cv[j] - f_buv[i][j];
        }
    }

    double val = 0;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            val += (k6[i][j]*k6[i][j]);
        }
    }
}

double v7(vector<double> gamma_v, vector<double> cv, double omega, vector<vector<double>> duv, double N2, vector<double> dv, vector<vector<double>> &k7){
    int no_of_aps = duv.size();
    int no_of_mds = gamma_v.size();

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            k7[i][j] = ((gamma_v[j]/cv[j]) + omega) - (1-duv[i][j])*N2 - dv[j];
        }
    }

    double val = 0;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            val += (k7[i][j] * k7[i][j]);
        }
    }

    return val;
}

double v8(vector<vector<double>> delta_uv, vector<vector<double>> duv, double N2, vector<double> dv, vector<vector<double>> &k8){
    int no_of_aps = delta_uv.size();
    int no_of_mds = dv.size();

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            double sum = 0;
        }
    }
}

double v9(vector<vector<double>> b_uv, double kth, double M1, vector<vector<double>> nuv, vector<vector<double>> &k9){

        int no_of_aps = b_uv.size();
        int no_of_mds = b_uv[0].size();

        for(int i=0; i<no_of_aps; i++){
            for(int j=0; j<no_of_mds; j++){
                k9[i][j] = ((b_uv[i][j] - kth)/M1) - nuv[i][j];
            }
        }

        double val = 0;

        for(int i=0; i<no_of_aps; i++){
            for(int j=0; j<no_of_mds; j++){
                val += (k9[i][j]*k9[i][j]);
            }
        }

        return val;
}

double v10(vector<vector<double>> nuv, vector<vector<double>> b_uv, double kth, vector<vector<double>> &k10){

    int no_of_aps = nuv.size();
    int no_of_mds = nuv[0].size();

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            k10[i][j] = nuv[i][j] - (b_uv[i][j]/kth);
        }
    }

    double val = 0;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            val += (k10[i][j] * k10[i][j]);
        }
    }

    return val;

}

double v11(vector<vector<double>> duv, vector<double> au, vector<vector<double>> &k11){

    int ap_size = au.size();
    int md_size = duv[0].size();
    double norm = 0;

    for(int i = 0; i < ap_size; i++){

        for(int j = 0; j < md_size; j++){

            k11[i][j] = duv[i][j] - au[i];
        }
    }

    for(int i=0; i<ap_size; i++){
        for(int j=0; j<md_size; j++){
            norm += (k11[i][j]*k11[i][j]);
        }
    }

    return norm;
}

double v12(vector<double> au, vector<vector<double>> duv, vector<double> &k12){

    int ap_size = au.size();
    int md_size = duv[0].size();
    double norm = 0;

    for(int i = 0; i < ap_size; i++){

        double diff = au[i];

        for(int j = 0; j < md_size; j++){

            diff -= duv[i][j];
        }

        k12[i] = diff;

        norm += (k12[i]*k12[i]);
    }

    return norm;
}

double v13(vector<vector<double>> b_uv, vector<vector<double>> sinr_uv, vector<vector<double>> &k13){
    int no_of_aps = b_uv.size();
    int no_of_mds = b_uv[0].size();

    double val = 0;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            k13[i][j] = b_uv[i][j] - sinr_uv[i][j];

            val += (k13[i][j]*k13[i][j]);
        }
    }

    return val;
}

double v14(vector<vector<double>> n_hu, vector<double> alpha_u, vector<double> &k14){
    double val = 0;

    for(int i=0; i<alpha_u.size(); i++){
        int sum = 0;

        for(int j=0; j<n_hu[0].size(); j++){
            sum += n_hu[j][i];
        }

        k14[i] = sum - alpha_u[i];

        val += (k14[i]*k14[i]);
    }

    return val;
}

