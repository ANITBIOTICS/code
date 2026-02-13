#include <bits/stdc++.h>
using namespace std;

int factorials(int n, int k){
    vector<int> factorial(n);
    factorial[0] = 1;
    for(int i = 1; i <= n; i++){
        factorial[i] = factorial[i=1]*i;
    }   

    int n = factorial[n] / (factorial[k] * factorial[n-k]);

    cout << n;
    return n;
}

int binomial(int n, int k, vector<vector<int>> dp){


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, k;
    cin >> n >> k;
    factorials(n, k);
  	vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
    
    return 0;
}