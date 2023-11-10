#include <bits/stdc++.h>
#include "variables.cpp"

using namespace std;

int getDelayGap(){
    int largest_delay_gap = INT_MIN;

    for(int i=0; i<100; i++){
        for(int j=0; j<1000; j++){
            if(transimission_delay[i][j]==-1)
            continue;

            int delay_gap = transimission_delay[i][j] - tolerable_delay;

            if(delay_gap > largest_delay_gap)
            largest_delay_gap = delay_gap;
        }
    }

    return largest_delay_gap;
}

// MLTA algorithm
void MLTA(MD broken_md, AP broken_AP) {

  MD adjustDV = broken_md;  
  AP *adjustAP = new AP(); //(for now)

  while(broken_md.current_ap.isBroken){

    for(AP candidate_ap : broken_md.candidate_aps){

        if(decision_variable[candidate_ap.id][broken_md.id] == 0 && candidate_ap.switched_on==true){

            adjustAP = &candidate_ap;
            broken_md.current_ap = candidate_ap;
            // adjust power range
        }
    }
  }

  bool flag = true;
  double R = INT16_MAX;
  int smallest_delay_gap = transimission_delay[(*adjustAP).id][adjustDV.id] - tolerable_delay;

  while (flag) {
    bool flag2 = false;
    
    int results = getDelayGap();

    if(results > R){
        flag = false;
    }
    else{
        for(AP candidate_ap: adjustDV.candidate_aps){
            if(candidate_ap.isBroken==true || candidate_ap.id == (*adjustAP).id){
                continue;
            }
            else{
                int delay_gap = transimission_delay[candidate_ap.id][adjustDV.id] - tolerable_delay;
                if(delay_gap < smallest_delay_gap && candidate_ap.switched_on==true){
                    adjustAP = &candidate_ap;
                    (*adjustAP).connected_MDs.push_back(adjustDV);
                    //adjust the power range of AP;
                }
                else{
                    flag2 = true;
                    //for all MD v
                        //do remark v as unmarked;
                }
            }

        }
    }

    MD *thrownawayDV = new MD();

    while(flag2){
        int largest_delay_gap = INT_MIN;
        for(MD v: (*adjustAP).connected_MDs){
            int delay_gap = transimission_delay[(*adjustAP).id][v.id] - tolerable_delay;

            if(delay_gap > largest_delay_gap){
                thrownawayDV = &v;
            }

            //unmark throwawayDV, which is not adjustDv and thrownawayDv
        }

        if((*thrownawayDV).id !=-1){
            //mark thrownawayDV's original AP as M3
            int smallest_delay_gap = INT_MAX;

            AP *k = new AP();

            for(AP v: ((*thrownawayDV).candidate_aps)){
                if(v.id == broken_AP.id || v.id == (*adjustAP).id)
                continue;

            int delay_gap = transimission_delay[v.id][(*thrownawayDV).id] - tolerable_delay;

            if(delay_gap < smallest_delay_gap){
                k = &v;
            }

            if((*k).id!=-1){
                    //reassocaiate MD thrownawayDV to AP k;
                    //adjust the power range of AP k;
                    (*k).addConnectedMD(*(thrownawayDV));
                    flag2 = false;
            }
            else{
                //MD thrownaway still associate to AP M3;
                //Mark thrownawayDV as remarked
            }

            }
        }else{
            flag2 = false;
        }
    }

  }

}