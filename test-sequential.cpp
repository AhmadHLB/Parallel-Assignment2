#include <bits/stdc++.h>
#include <time.h>

using namespace std;

#define n 1000

vector<vector<int>> matrix1(n, vector<int>(n));
vector<vector<int>> matrix2(n, vector<int>(n));
vector<vector<int>> res(n, vector<int>(n));

void displayMatrix(vector<vector<int>>& matrix);

int main(){

    time_t t;


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix1[i][j] = rand()%10;
            matrix2[i][j] = rand()%10;
        }
    }



    t = clock();
    int i;
    int j;
    int k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                res[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    t = clock() - t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%d\n", time_taken);
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