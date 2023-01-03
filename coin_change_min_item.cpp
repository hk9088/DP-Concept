#include<iostream>
using namespace std;

int minItem(int arr[],int sum,int n){

    int t[n+1][sum+1];

    for(int i=1;i<n+1;i++)  t[i][0] = 0;
    for(int j=0;j<sum+1;j++)  t[0][j] = INT_MAX - 1;

    // Second Initialization only for this particular problem

    for(int j=1;j<sum+1;j++){
        if(j%arr[0]==0){
            t[1][j] = j/arr[0];
        }
        else{
            t[1][j] = INT_MAX - 1;
        }
    }

    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1] <= j){
                t[i][j] = min(1 + t[i][j-arr[i-1]], 0 + t[i-1][j]);
            }
            else{
                t[i][j] = 0 + t[i-1][j];
            }
        }
    }

    return t[n][sum];
    
}

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 5;

    cout<<minItem(arr,m,n);
}