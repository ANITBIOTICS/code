#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> row (8, 0), col(8, 0), diag1(15, 0), diag2(15, 0);
int ans = 0;
 
vector<string>arr(8);
 
void solve(int r){
    if(r == 8){ ans++; return; }
    for(int c = 0; c < 8; c++){
        if(arr[r][c] == '*') continue;
        if(col[c] || diag1[r - c + 7] || diag2[r + c]) continue;
 
        col[c] = 1;
        diag1[r - c + 7] = 1;
        diag2[r + c] = 1;
 
        solve(r + 1);
 
        col[c] = 0;
        diag1[r - c + 7] = 0;
        diag2[r + c] = 0;
    }
 
}
 
int main(){
    for(int i = 0; i < 8; i++) cin >> arr[i];
    solve(0);
    cout << ans << "\n";
    return 0;
}