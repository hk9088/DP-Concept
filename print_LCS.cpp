#include<iostream>
#include<vector>
using namespace std;

string print_LCS(string x, string y, int m, int n){

    int t[m+1][n+1];
    for(int i=0;i<m+1;i++)  t[i][0] = 0;
    for(int j=0;j<n+1;j++)  t[0][j] = 0;

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){

            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }

        }
    }

    vector<char> s;
    string ans = "";

    int i = m , j = n ;

    while (i > 0 && j > 0)
    {
        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j] > t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    
    for(int i=s.size()-1;i>=0;i--)  ans += s[i];

    return ans;
}

int main(){

    string x = "abcdgh";
    string y = "abedfhr";

    int m = x.length();
    int n = y.length();

    cout<<print_LCS(x,y,m,n);

}