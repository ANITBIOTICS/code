#include <bits/stdc++.h>
#include <unordered_set>
 
using namespace std;
 
#define ll long long
 
int main(){
 
    int n;
    cin >> n;
 
    // XOR
 
    // for(int r = 0; r < n; r++){
    //     for (int c = 0; c < n; c++){
    //         cout << (r ^ c) ;
    //         if (c != n -1) cout << " ";
    //     }
    //     cout << "\n";
    // }
 
    vector<vector<int>> arr (n, vector<int> (n));
 
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            unordered_set<int> used;
 
            for(int i = 0; i < c; i++){
                used.insert(arr[r][i]);
            }
 
            for(int i = 0; i < r; i++){
                used.insert(arr[i][c]);
            }
 
            int mex = 0;
            while(used.count(mex)){
                mex++;
            }
 
            arr[r][c] = mex;
        }
    }
 
    for(int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){
            cout << arr[r][c];
            if (c != n -1) cout << " ";
        }
        cout << "\n";
    }
 
    
    return 0;
}
