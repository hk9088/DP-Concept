#include<iostream>
using namespace std;

int static t[1001][1001]; 
void set_t(int m, int n){
    for (int i = 0; i < m+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            t[i][j] = -1;
        }
    }
}

int LCS(string x, string y, int m, int n){

    if(m == 0 || n == 0){
        return 0;
    }

    if(t[m][n]!= -1){
        return t[m][n];
    }

    if(x[m-1] == y[n-1]){
        return t[m][n] = 1 + LCS(x,y,m-1,n-1);
    }
    else{
        return t[m][n] = max(0+LCS(x,y,m-1,n), 0+LCS(x,y,m,n-1));
    }

    
}
int main(){
    string x = "abcdgh";
    string y = "abedfhr";

    int m = x.length();
    int n = y.length();

    set_t(m, n);

    cout<<LCS(x,y,m,n);

}