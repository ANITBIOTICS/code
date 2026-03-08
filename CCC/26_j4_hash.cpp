#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
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
    unordered_map<ll, unordered_set<ll>> visited;
    visited[0].insert(0);
    for(int i = 0; i < M; i++){
        char direction; cin >> direction;
        ll len; cin >> len;
        ll dx = 0,  dy = 0;

        if(direction == 'N') dy = 1;
        else if (direction == 'S') dy = -1;
        else if (direction == 'E') dx = 1;
        else if (direction == 'W') dx = -1;
        for(int j = 0; j < len; j++){
            y += dy; x += dx;
            if (visited.count(x) && visited[x].count(y)){
                T++;
            }

            visited[x].insert(y);
        }
    }
    cout << T << "\n";
}
