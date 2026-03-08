#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int M, N; cin >> M >> N;
    int K; cin >> K;
    vector<vector<bool>> arr (M, vector<bool> (N, false));
    for(int i = 0; i < K; i++){
        char c; cin >> c;
        int num; cin >> num;
        num --;
        if(c == 'R'){
            for(int j = 0; j < N; j++){
                arr[num][j] = !arr[num][j];
            }
        }else if(c == 'C'){
            for(int j = 0; j < M; j++){
                arr[j][num] = !arr[j][num];
            }
        }
    }

    long count = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j]) count++;
        }
    }


    cout << count;
    return 0;
}