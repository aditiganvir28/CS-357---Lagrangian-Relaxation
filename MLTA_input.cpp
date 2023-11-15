#include<bits/stdc++.h>
#include "variables.cpp"

using namespace std;

int input_objects(){

    //creating MD objects
    for(int i=0; i<no_of_mds; i++){
        MD md(i, gamma_v[i]);
        mds.push_back(md);
    }

    //creating AP objects
    for(int i=0; i<no_of_aps; i++){
        AP ap(i, pu[i]);
        aps.push_back(ap);
    }

    for(int i=0; i<no_of_mds; i++){
        //current ap
        for(int j=0; j<no_of_aps; j++){
            if(delta_uv[j][i]==1){
                mds[i].current_ap = aps[j];
                break;
            }
        }

        //candidate APs
        for(int j=0; j<no_of_aps; j++){
            if(delta_uv[j][i]==0){
                mds[i].addCandidateAP(aps[j]);
            }
        }
    }

    for(int j=0; j<no_of_aps; j++){
        //connected MDs
        for(int i=0; i<no_of_mds; i++){
            if(delta_uv[j][i]==1){
                aps[j].addConnectedMD(mds[i]);
            }
        }

        //switched on
        if(alpha_u[j]==1){
            aps[j].switched_on = true;
        }else{
            aps[j].switched_on = false;
        }
    }

    aps[3].isBroken = true;
}