#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N, L, Q; cin >> N >> L >> Q;

    vector<int> lights(N+3, 0);
    for(int i = 0; i < L; i++){
        int P, S; cin >> P >> S;

        int l = max(1,P-S);
        int r = min(P+S,N); 

        lights[l] +=1;
        lights[r+1] -=1;
    }

    int cur = 0;
    vector<int> cover(N+2,0);
    for(int i = 1; i <= N; i++){
        cur += lights[i];
        cover[i] = cur;
    }

    while(Q--){
        int x; cin >> x;
        cout << (cover[x] > 0 ? 'Y' : 'N') << endl;
    }

    return 0;
}

