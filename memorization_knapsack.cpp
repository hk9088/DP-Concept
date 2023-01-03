#include<iostream>
#include<algorithm>
using namespace std;

int static t[5][8];  // t[n+1][w+1]
void set_t(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            t[i][j] = -1;
        }
        
    }
    
}

int knapsack(int wt[], int val[], int w, int n){

    if(n == 0 || w == 0){
        return 0;
    }
    if(t[n][w]!= -1){
        return t[n][w];
    }

    if(wt[n-1]<= w){
        return t[n][w] = max(val[n-1] + knapsack(wt, val, w-wt[n-1], n-1), 0 + knapsack(wt, val, w, n-1));
    }
    // else if(wt[n-1]> w){
    //     return t[n][w] = 0 + knapsack(wt, val, w, n-1);
    // }
    else{
        return t[n][w] = 0 + knapsack(wt, val, w, n-1);
    }
}
int main(){
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;
    set_t();

    cout<<"Maximum Profit [KnapSack by Memorization]: "<<knapsack(wt, val, w, 4);

}