#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N; cin >> N;

    vector<int> score1 (N), score2 (N);
    cin >> score1[0];
    for(int i = 1; i < N; i++){
        int x;
        cin >> x;
        score1[i] = score1[i-1] + x; 
    }

    cin >> score2[0];
    for(int i = 1; i < N; i++){
        int x;
        cin >> x;
        score2[i] = score2[i-1] + x; 
    }
    bool found = false;

    
    for(int i = N-1; i >= 0; i--){
        if(score1[i] == score2[i]){
            cout << i+1;
            found = true;
            break;
        }
    }
    
    if(!found){
        cout << 0;
    }



    return 0;
}