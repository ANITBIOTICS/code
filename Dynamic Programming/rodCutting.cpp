#include <bits/stdc++.h>
using namespace std;

int rod(int n, int x, int y, int z, vector<int> & dp){ //n is the lenght of the rod
    if (n < 0) return -1;
    if (n == 0) return 0;
    
    int cut1 = rod(n-x, x, y, z, dp);
    int cut2 = rod(n-y, x, y, z, dp);
    int cut3 = rod(n-z, x, y, z, dp);

    int maxCut = max(cut1, max(cut2, cut3));

    if(maxCut < 0){
        return -1;
    }

    
    dp[n] = maxCut + 1;
    return dp[n];
}

int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> dp (n+1);
    cout << rod(n, x, y, z, dp);
    return 0;
}