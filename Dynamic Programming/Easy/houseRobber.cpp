#include <bits/stdc++.h>
using namespace std;
#define ll long long

int tabulation(vector<int>&arr){
    int n = arr.size();
    vector<int> dp(n+1, 0);

    dp[0] = 0;
    dp[1] = arr[0];

    for (int i = 2; i <= n; i++) 
        dp[i] = max(arr[i - 1] + dp[i - 2], dp[i - 1]);

    return dp[n];
}

int main(){
    vector<int> arr = {6, 7, 1, 3, 8, 2, 4};
    cout << tabulation(arr);
    return 0;
}
