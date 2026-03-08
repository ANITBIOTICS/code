#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long

// start point (0,0);
//T = 0;
// N : y += 1;
// S : y -= 1;
// E : X += 1;
// W:  X -= 1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int M; cin >> M;
    ll y = 0;
    ll x = 0;
    ll T = 0;
    unordered_set<string> visited;
    visited.insert("0,0");
    // vecto    r<pair<ll,ll>> v;
    // pair<ll,ll> temp = {0, 0};
    // v.push_back(temp);
    for(int i = 0; i < M; i++){
        char direction; cin >> direction;
        ll len; cin >> len;

        ll dx = 0,  dy = 0;

        if(direction == 'N') dy = 1;
        else if (direction == 'S') dy = -1;
        else if (direction == 'E') dx = 1;
        else if (direction == 'W') dx = -1;
        
        for(int i = 0; i < len; i++){
            y += dy;
            x += dx;
             
            string pos = to_string(x) + "," + to_string(y);

            if (visited.count(pos)){
                T++;
            }

            visited.insert(pos);

        }
    }
    cout << T << "\n";
}
