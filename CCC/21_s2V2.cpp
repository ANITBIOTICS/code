#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int M, N; cin >> M >> N;
    int K; cin >> K;
    
    //vector<char> r(M, 0), c(N, 0); 
    //count for r, and c
    
    vector<vector<bool>> arr (M, vector<bool> (N, false));
    for(int i = 0; i < K; i++){
        char c; cin >> c;
        int num; cin >> num;
        num --; //ok this formatting fucking pissed me off
        if(c == 'R'){
            //r[x]^=1;
            for(int j = 0; j < N; j++){
                arr[num][j] = !arr[num][j];
            }
        }else if(c == 'C'){
            //c[x] ^= 1
            for(int j = 0; j < M; j++){
                arr[j][num] = !arr[j][num];
            }
        }
    }
    //long long R = 0, C = 0;
    //for(int i = 0; i < M; i++) R += r[i];
    //for(int j = 0; j < N; j++) C += c[j]
    //long long ans = R * (N - C) + (M - R) * C;
    //cout << ans << '\n'; return 0;
    long count = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j]) count++;
        }
    }
    cout << count;
    return 0;
}