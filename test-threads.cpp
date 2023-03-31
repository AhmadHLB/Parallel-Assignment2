#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int n = 1000;
int thread_num = 5;
int curr_index = 0;
int division = n/thread_num;

vector<vector<int>> matrix1(n, vector<int> (n));
vector<vector<int>> matrix2(n, vector<int> (n));
vector<vector<int>> res(n, vector<int> (n));

void displayMatrix(vector<vector<int>>& matrix);

void* mult(void* p){
    for(int s=0; s<division; s++){
        int i = curr_index++;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                res[i][j] += matrix1[i][k] * matrix2[k][j];

    }

    return p;
}

int main(){
    time_t t;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix1[i][j] = rand()%10;
            matrix2[i][j] = rand()%10;
        }
    }

    pthread_t threads[thread_num];

    for(int i=0; i<thread_num; i++){

    }


    t = clock();

    for(int i=0; i<thread_num; i++){
        pthread_create(&threads[i], NULL, mult, (void*)NULL);
    }
    
    for(int i=0; i<thread_num; i++){
        pthread_join(threads[i], NULL);
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