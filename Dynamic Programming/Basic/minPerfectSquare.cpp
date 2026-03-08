#include <bits/stdc++.h>
using namespace std;

int recur(int n){
    int root = (int) sqrt(n);
    if(root * root == n){
        return 1;
    }

    return 1+ recur(n-root*root);
}

int bottomUp(int n){
    vector<int> dp (n+1, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i < n+1; i++){
        dp[i] = i;
        for(int j = 1; j*j <= i; j++){
            dp[i] = min(dp[j], 1+dp[i-j*j]);
        }
    }

    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n;
    cin >> n;
    cout << bottomUp(n);
    return 0;
}
