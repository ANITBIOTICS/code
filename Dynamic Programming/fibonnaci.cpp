#include <bits/stdc++.h>
using namespace std;

int fib1(int n){
    if(n == 1){
        return 1;
    }else if (n == 0){
        return 0;
    }

    return fib1(n-1) + fib1(n-2);
}

int fib2(int n){
    vector<int> dp (n);

    if(n <= 1){
        return n;
    }

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i < n + 1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fib3(int n){
    if(n <= 1){
        return n;
    }

    int prev1 = 0;
    int prev2 = 1;
    int cur = 1;

    for(int i = 2; i < n + 1; i++){
        int temp = cur;
        cur = prev1 + prev2;
        prev1 = prev2;
        prev2 = temp;
    }

    return cur;
}

int main(){
    int n;
    cin >> n;
    int num = fib3(n);
    cout << num;
    return 0;
}