#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, q; cin >> n >> q;
    vector<string> arr(n);
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + (arr[i-1][j-1] == '*');
        }
    }

    while(q > 0){
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1] << endl;
       q--; 
    }

    return 0;
}