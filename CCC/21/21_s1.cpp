#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N;
    cin >> N;
    vector<int> sides (N+1), width (N);

    for(int i = 0; i <= N; i++) cin >> sides[i];
    for(int i = 0; i < N; i++) cin >> width[i];

    long double paint = 0.0;
    for(int i = 0; i < N; i++){
        paint += ((sides[i] + sides[i+1]) * width[i])/2.0;
    }

    cout << paint;

    return 0;
}