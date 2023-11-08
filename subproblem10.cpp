#include <bits/stdc++.h>

using namespace std;

double subproblem10(vector<vector<double>> muv7, vector<vector<double>> &duv, vector<vector<double>> muk8, vector<double> tolerable_delay){

    int md_size = muv7[0].size();
    int ap_size = muv7.size();

    

    double val = INT_MAX;
    
    for(int i = 0; i < ap_size; i++){

        double sum_uk = 0;
        for(int j = 0; j < md_size; j++){

            for(int k = 0; k < md_size; k++){

                sum_uk += muk8[i][k];
            }
            
            sum_uk -= muv7[i][j];

           if(sum_uk < 0){
                duv[i][j] = tolerable_delay[j];
            }
            else{

                duv[i][j] = 0;
            }


            sum_uk *= duv[i][j];

        }        
        
        val = min(val, sum_uk); 
    }
    
    return val;
}