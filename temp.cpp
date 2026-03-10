#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int M; cin >> M;
    int y = 0;
    int x = 0;
    int count = 0;
    unordered_map<ll, unordered_set<ll>> visited;
    visited[0].insert(0);

    for(int i = 0; i < M; i++){
        char direction; cin >> direction;
        int len; cin >> len;
        
        ll dx = 0; ll dy = 0;
        if(direction = 'N')dy = 1;
        else if(direction = 'S') dy = -1;
        else if (direction = 'W')dx = -1;
        else dx = 1;

        for(int j = 0; j < len; j++){
            x+=dx; y+=dy;
            if(visited[x].count(y) == y && visited.count(x)){
                count++;
            }
        }
    }

    cout << count;




    return 0;
}
