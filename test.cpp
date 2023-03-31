#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
#include <omp.h>

using namespace std;

int n = 500;

void displayMatrix(vector<vector<int>>& matrix);

int main(){

    time_t t;
    
    vector<vector<int>> matrix1(n, vector<int> (n));
    vector<vector<int>> matrix2(n, vector<int> (n));

    omp_set_num_threads(5);


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix1[i][j] = rand()%10;
            matrix2[i][j] = rand()%10;
        }
    }

    vector<vector<int>> res(n, vector<int> (n));

    t = clock();

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;

            for (int k = 0; k < n; k++) {
                res[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    t = clock() - t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    cout << "TIME TAKEN: " << time_taken << " SECONDS";
}


void displayMatrix(vector<vector<int>>& matrix){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}