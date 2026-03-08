#include <bits/stdc++.h>
using namespace std;

int trib1(int n){
    if(n == 0 || n == 1){
        return 0;
    }else if (n==2){
        return 1;
    }

    return trib1(n-1) + trib1(n-2) + trib1(n-3);
}

void trib2(int n){

    vector<int> dp (n+1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    cout << "0 0 1 ";
    for(int i = 3; i < n+1; i++){
        dp[i] = dp[i-1] + dp [i-2] + dp [i-3];
        cout << dp[i] << " ";
    }
    
}




int main(){
    int n;
    trib2(5);
    return 0;
}