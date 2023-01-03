#include<iostream>
using namespace std;
int LCS(string x, string y, int m, int n){

    int t[m+1][n+1];
    for(int i=0;i<m+1;i++)  t[i][0] = 0;
    for(int j=0;j<n+1;j++)  t[0][j] = 0;

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = 0;
            }
        }
    }

    return t[m][n];

}
int main(){

    string x = "abcdgh";
    string y = "abedfhr";

    int m = x.length();
    int n = y.length();

    cout<<LCS(x,y,m,n);

}