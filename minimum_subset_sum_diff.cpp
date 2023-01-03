#include<iostream>
#include<algorithm>

using namespace std;

int minSubsetSumDiff(int arr[], int sum, int n){

    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)  t[i][0] = 1;
    for(int j=1;j<sum+1;j++)  t[0][j] = 0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j] || t[i-1][j - arr[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    vector<int> s1;
    for(int i=1;i<(sum+1)/2;i++){
        if(t[n][i]){
            s1.push_back(i);
        }
    }
    int min = INT_MAX, z;
    for(int i=0; i<s1.size();i++){
        z = sum - (2 * s1[i]);
        if(z < min){
            min = z;
        }
    }
    return z;
}
int main(){
    int arr[] = {1, 2, 7};
    int sum = 0;
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++)    sum += arr[i];

    cout<<minSubsetSumDiff(arr,sum,n);
}