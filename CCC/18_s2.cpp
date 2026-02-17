#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

going down left most column should increase
going right of every column should increase. 


check for which side has all rows/columns increasing. that would be the heights of the plants

*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N; cin >> N;
    vector<vector<int>> arr(N, vector<int> (N));
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> increasing (4, 1);
    for(int i = 1; i < N; i++){
         
       }

    return 0;

}