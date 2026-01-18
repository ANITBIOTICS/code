#include <bits/stdc++.h>
using namespace std;

int catalan(int n){
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

int findWays(int n){
    if(n%2 != 0){
        return 0;
    }

    return catalan(n/2);
}


int main(){
    /*
    numOpen > numClosed
    if n == 0dd, cout -1;
    */
    int n;
    cin >> n;
    cout << findWays(n);
    return 0;
}