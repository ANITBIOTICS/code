#include <bits/stdc++.h>
using namespace std;

int stairs(vector<int> weight){
    int n = weight.size();
    vector<int> dp(n+1); //smallest cost to go to each step

    dp[0] = weight[0];
    dp[1] = weight[1];

    for(int i = 2; i < weight.size(); i++){
        if(dp[i-1] < dp[i-2]){
            dp[i] = dp[i-1] + weight[i];
        }else if(dp[i-1] >= dp[i-2]){
            dp[i] = dp[i-2] + weight[i];
        }
    }

    return min(dp[n-1], dp[n-2]);
}


int main(){
    //vector<int> weight (n);
    //cin >> weight;
    vector<int> weight = { 16, 19, 10, 12, 18 };

    cout << stairs(weight);
    return 0;
}