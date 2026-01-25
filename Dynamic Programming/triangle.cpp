#include <bits/stdc++.h>
using namespace std;
int recur(vector<vector<int>>& arr, int i, int j){
    if(i == arr.size()) return 0;

    return min(recur(arr, i+1, j+1), recur(arr, i+1, j)) + arr[i][j];
}


int memo(vector<vector<int>> & arr){
    int n = arr.size();
    vector<vector<int>> dp ((n), vector<int>(n, -1));

    for (int i = 0; i < n; i++) 
        dp[n-1][i] = arr[n - 1][i]; 

     for (int i = n - 2; i >= 0; i--){
        for (int j = 0; j < arr[i].size(); j++){
            dp[i][j] = arr[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}




int main(){
    vector<vector<int>> triangle = {{2},
                                    {3, 7},
                                    {8, 5, 6},
                                    {6, 1, 9, 3}};
    cout << recur(triangle, 0, 0);

    return 0;
}