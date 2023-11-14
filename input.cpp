#include "variables.cpp"
#include<bits/stdc++.h>

using namespace std;

int main() {
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

    //Calculating delta_uv

    //Calculating traffic requirements of mobile devices
    for(int i=0; i<no_of_mds; i++){
        gamma_v[i] = (double)(rand()%1) + 0.7;
    }

    

    //exporting distance between AP u and mobile device v from csv 
    ifstream inputFile("./distance.csv");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
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

    // // Print the data (optional)
    // for (const auto& row : distance_uv) {
    //     for (const auto& value : row) {
    //         cout << value << " ";
    //     }
    //     cout << endl;
    // }

    //Calculating SINR values

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){

            double sum = 0;

            int var = j==no_of_mds?j-1:j+1;

            for(int k=0; k<no_of_aps; k++){
                if(i!=k){
                    sum += (pu[k]/(distance_uv[k][var]*distance_uv[k][var]));
                }
            }

            b_uv[i][j] = (pu[i]/(distance_uv[i][j]*distance_uv[i][j]))/(sum);
        }
    }

    //Calculating cv

    for(int i=0; i<no_of_aps; i++){
        for(int j=0; j<no_of_mds; j++){
            cv[j] = channel[h[i]]*(log2(1+b_uv[i][j]));
        }
    }

    return 0;
}

