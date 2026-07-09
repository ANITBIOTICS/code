#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll int MOD = 1e9+7;

long long dp(int n, vector<ll> &memo){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(memo[n] != -1) return memo[n];

    long long total = 0;
    for (int k = 1; k <= 6; k++) total = (total + dp(n - k, memo)) % MOD;
    return memo[n] = total;
}

int main(){
    int n;
    cin >> n;
    vector<ll> memo(n + 1, -1);
    cout << dp(n, memo);
}   
