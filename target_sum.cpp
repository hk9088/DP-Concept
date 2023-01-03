#include<iostream>
using namespace std;

int tagetSum(int arr[], int sum, int n){

    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)  t[i][0] = 1;
    for(int j=1;j<sum+1;j++)  t[0][j] = 0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<= j){
                t[i][j] = t[i-1][j] + t[i-1][j - arr[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }

    return t[n][sum];
}

int main(){
    int arr[] = {1, 1, 2, 3};
    int m = 1;
    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = 0;
    for(int i=0;i<n;i++)    sum+=arr[i];

    sum = (m + sum)/2;

    if(tagetSum(arr, sum, n)){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
}