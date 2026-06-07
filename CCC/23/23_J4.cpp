#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N; cin >> N;
    int count  = 0;

    vector<vector<int>> arr (2, vector<int>(N));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
        if(arr[i][j] == 1) count +=3;
        if(j + 1 < N && arr[i][j] == 1 && arr[i][j+1] == 1){
            count -=2;
        }
        if(i == 0 && j % 2 == 0 && arr[0][j] == 1 && arr[1][j] == 1){
            count -=2;
        }
    }
    }
    cout << count;
   return 0;
}