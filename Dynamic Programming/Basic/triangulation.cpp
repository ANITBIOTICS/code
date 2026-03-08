#include <bits/stdc++.h>
using namespace std;

int trig(int n){
    vector<int> dp(n+1);
    if (n == 0 || n == 1){
        return 1;
    }

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i < n+1; i++){
        dp[i] = 0;
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << trig(n-2);
    return 0;
}