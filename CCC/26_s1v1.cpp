#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

*/

int hop1(int end, int bigHop, vector<int> dp){
    if(dp[end] != -1){
        return dp[end];
    }else{
        vector<int> temp (4);
        int a = hop1(end-1, bigHop, dp);
        int b = hop1(end+1, bigHop, dp);
        int c = hop1(end-bigHop, bigHop, dp);
        int d = hop1(end+bigHop,bigHop,dp);
        // temp.push_back(a);
        // temp.push_back(b);
        // temp.push_back(c);
        // temp.push_back(d);
        // sort(temp.begin(), temp.end());

        // dp[end] = 1+ 
        return dp[end];
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int A; cin >> A; //start here
    A += 1e18;
    int B; cin >> B; //go to here
    B += 1e18;
    int K; cin >> K; //size of big hop
    int T; cin >> T;
    int counter = 0;

    vector<int> dp (INT_MAX, -1); //let the center of this array be 0
    dp[A] = 0;


    return 0;
}