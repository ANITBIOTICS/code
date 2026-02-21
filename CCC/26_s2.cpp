#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int N; cin >> N;
    vector<int> spots (N, 0);

    int L; cin >> L;
    int Q; cin >> Q;

    for(int i = 0; i < L; i++){
        int location; cin >> location; location --;
        int spread; cin >> spread;

        int leftLight, rightLight;
        leftLight = max(0, location-spread);
        rightLight = min(location+spread, (int)spots.size());
        for(int i = leftLight; i <= rightLight; i++) spots[i] ++;
    }

    for(int i = 0; i < Q; i++){
        int light; cin >> light;
        string res = (spots[light-1] > 0 ? "Y" : "N");
        cout << res << endl;
    } 
    return 0;
}

