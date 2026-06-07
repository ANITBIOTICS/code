#include <bits/stdc++.h>
using namespace std;
#define ll long long

int minSumPathRec(vector<vector<int>> triangle, int i, int j, vector<vector<int>>&dp){

    // base case: no value below the last row
    if(i == triangle.size()){ // bottom row of triangle
        return 0;
    }

    //if the result for this subproblem is already computed then return it
    if (dp[i][j] != -1){
        return dp[i][j];
    }

    return triangle[i][j] + min(minSumPathRec(triangle, i+1, j, dp), minSumPathRec(triangle, i+1, j+1, dp));
}

int minSumPath(vector<vector<int>> &triangle){
    int n = triangle.size();
    // dp arrary: store the result
    vector<vector<int>> dp (n, vector<int>(n, -1));

    return minSumPathRec(triangle, 0, 0, dp);
}

int minSumPathTab(vector<vector<int>> &triangle){
    vector<vector<int>> dp (triangle.size(), vector<int> (triangle.size()));
    //dp's last row = triangle last row
    for(int i = 0; i < triangle.size(); i++){
        dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
    }
    //for loop thing idk-+
    for(int i = triangle.size()-2; i >= 0; i--){
        for(int j = 0; j < triangle[i].size(); j++){
            dp[i][j] = triangle[i][j] + min(dp[i+1][j+1], dp[i+1][j]);
        }
    }
    //return the desired point from the dp vector
    return dp[0][0]; 
}
int main(){
    vector<vector<int>> triangle = {
    {2},
    {3, 9},
    {1, 6, 7}};

    
    cout << minSumPathTab(triangle);
    return 0;

    // int temporary for minsum path tab

}
