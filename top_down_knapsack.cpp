#include<iostream>
#include<algorithm>
using namespace std;

int static t[5][8];  // t[n+1][w+1]

void initialize_t(){
    for(int i=0; i<5; i++) t[0][i] = 0;
    for(int j=0; j<8; j++) t[j][0] = 0;
    
}

int knapsack(int wt[], int val[], int w, int n){

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<= j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], 0 + t[i-1][j]);
            }
            else if(wt[i-1]> w){
                t[i][j] = 0 + t[i-1][j];
            }

        }
    }
    
    return t[n][w];

}
int main(){
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;
    initialize_t();

    cout<<"Maximum Profit [KnapSack by Top down]: "<<knapsack(wt, val, w, 4);

}