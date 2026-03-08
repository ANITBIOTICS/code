#include <bits/stdc++.h>
using namespace std;

int recur(vector<vector<int>> arr, int x1, int y1, int x2, int y2){ //array, previous location (x1, y1), testing location (x2, y2)
    if(!(x2>8 || x2 < 1)){
        arr[x2][y2] = min(arr[x1][y1] + 1, arr[x2][y2]);
        return arr[x2][y2];
    }


    recur(arr, x2, y2, x2+2, y2+1);
    recur(arr, x2, y2, x2+2, y2-1);
    recur(arr, x2, y2, x2+1, y2+2);
    recur(arr, x2, y2, x2+1, y2-2);

    recur(arr, x2, y2, x2-1, y2+2);
    recur(arr, x2, y2, x2-1, y2-2);
    recur(arr, x2, y2, x2-2, y2+1);
    recur(arr, x2, y2, x2-2, y2-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int count = 0;
    vector<vector<int>> arr (8, vector<int>(8, INT_MAX));
    arr[x1][y1] = 0;


    return 0;
}