#include "variables.cpp"
#include<bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include<vector>

using namespace std;

int inputs(){
    //calculating tolerable delay
    for (int i = 0; i < no_of_mds; i++){
        Tv[i] = (double)(rand() % (19)) + 71.82;
        
    }

    //Calculating power range
    for(int i=0; i<no_of_aps; i++){
        pu[i] = (double)(rand()%2) + 2.4;
    }

    //assigning channels to APs;
    n_hu = {{1,0,1,0,0}, {0,1,0,0,1}, {0,0,0,1,0}};

    //Calculating traffic requirements of mobile devices
    for(int i=0; i<no_of_mds; i++){
        gamma_v[i] = (double)(rand()%5) + 0.7;
    }

    //exporting distance between AP u and mobile device v from csv 
    ifstream inputFile("./distance.csv");

    if (!inputFile.is_open()) {
        cerr << "Error opening the distance file." << endl;
        return ;
    }

    string line;
        while (getline(inputFile, line)) {

            stringstream ss(line);

            vector<double> row;

            double value;
            while (ss >> value) {
                row.push_back(value*70/873.23);

                if (ss.peek() == ',')
                    ss.ignore();
            }

            distance_uv.push_back(row);
        }
    inputFile.close();

    //Calculating SINR values

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){

            double sum = 0;

            int var = j==(no_of_mds-1)?j-1:j+1;
            
            for(int k=0; k<no_of_aps; k++){
                if(i!=k){
                    sum += (pu[k]/(distance_uv[var][k]*distance_uv[var][k]));
                }
            }


            b_uv[i][j] = (pu[i]/(distance_uv[j][i]*distance_uv[j][i]*sum));
        }
    }

    //Calculating cv

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            cv[j] = channel[h[i]]*(log2(1+b_uv[i][j]));
        }
    }

    //Calculating Kth
    double sum = 0;

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            sum+=b_uv[i][j];
        }
    }

    kth = sum/(no_of_aps*no_of_mds);

    //exporting delta_uv between mobile device and AP
    ifstream inputFile2("./delta_uv.csv");

    if (!inputFile2.is_open()) {
        cerr << "Error opening the delta_uv file." << endl;
        return ;
    }
        string line2;
        while (getline(inputFile2, line2)) {

            stringstream ss(line2);

            vector<double> row;

            double value;
            while (ss >> value) {
                row.push_back(value);

                if (ss.peek() == ',')
                    ss.ignore();
            }

            delta_uv.push_back(row);
        }

    inputFile2.close();

    return ;
}

