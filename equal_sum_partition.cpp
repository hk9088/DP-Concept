#include<iostream>
using namespace std;

int equalSumPartition(int arr[], int sum, int n){
    // Initalizing the matrix
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)  t[i][0] = 1;
    for(int j=1;j<sum+1;j++)  t[0][j] = 0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1] <= j){
                t[i][j] = (t[i-1][j - arr[i-1]]) || (t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;

    for(int i=0;i<n;i++)    sum += arr[i];

    if(sum%2 == 0){
        int r = equalSumPartition(arr,sum/2,n);

        if(r){
            cout<<"Yes"<<"\n";
        }
        else{
            cout<<"No"<<"\n";
        }
    }
    else{
        cout<<"No"<<"\n";
    }
}
