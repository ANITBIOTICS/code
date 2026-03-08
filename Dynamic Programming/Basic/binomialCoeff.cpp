#include <bits/stdc++.h>
using namespace std;


int recursion(int n, int k){
    if(k > n){
        return 0;
    }
    if(k == 0 || n == 0){
        return 1;
    }

    return recursion(n-1, k-1) + recursion(n-1, k);
}

int bottomUp(int n, int k){
  	vector<vector<int>> dp(n + 1, vector<int> (k + 1));

    //fill out the array
    for(int &a : dp[0]){
        a = 0;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= min(k, i); j++){
            if(j == i || j == 0){
                dp[i][j] = 1;
            }else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }

    return dp[n][k];
}


int topDown(int n, int k, vector<vector<int>> &dp){
    //base case
    if(k == 0 || k == n){
        return 1;
    }else if(k > n){
        return 0;
    }
  
    if(dp[n][k] != -1) return dp[n][k];
    
    dp[n][k] = topDown(n-1, k-1, dp) + topDown(n-1, k, dp);
    return dp[n][k];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, k;
    cin >> n >> k;
  	vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
    cout << topDown(n, k, dp);
    return 0;
}