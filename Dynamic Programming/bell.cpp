#include <bits/stdc++.h>
using namespace std;

int s(int n, int k){
    if(n == 0 || k == 0) return 0;
    if( n == 0 && k ==0) return 1;
    if(n == 1) return 1;

    return k*s(n-1, k) + s(n-1, k-1);
}


int s1(int n, int k){
    vector<vector<int>> dp (n + 1, vector<int>(n + 1));

     for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j > i)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = 1;
            else if (i == 0 || j == 0)
                dp[i][j] = 0;
            else {
                dp[i][j] = j*dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }


    int res = 0;
    for(int i = 0; i <= n; i++){
        res += dp[n][i];
    }
    return res;
}

int main(){
    int bell = 0;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        bell += s(n, k);
    }
    cout << bell << endl;
    cout << s1(n, k);

    return 0;
}