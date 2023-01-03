#include<iostream>
using namespace std;

void LCS(string a, string b, int m, int n){

    int t[m+1][n+1];
    for(int i=0;i<m+1;i++)  t[i][0] = 0;
    for(int j=0;j<n+1;j++)  t[0][j] = 0;

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    cout<<"DELETION : "<< m - t[m][n]<<"\n"; 
    cout<<"INSERTION : "<< n - t[m][n]<<"\n"; 

}

int main(){
    string a = "heap";
    string b = "pea";

    int m = a.length();
    int n = b.length();

    LCS(a, b, m, n); 
}