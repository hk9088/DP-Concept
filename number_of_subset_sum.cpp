#include<iostream>
using namespace std;

int numberOfSubsetSum(int arr[], int sum, int n){

    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)  t[i][0] = 1;
    for(int j=1;j<sum+1;j++)  t[0][j] = 0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){
    int arr[] = {2,3,5,5,10};
    int sum = 10;

    cout<<numberOfSubsetSum(arr, sum, sizeof(arr)/sizeof(arr[0]));
}