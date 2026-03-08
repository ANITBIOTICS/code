#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N; cin >> N;
    vector<vector<string>> arr(2, vector<string> (N));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    

    return 0;
}