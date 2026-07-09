#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; cin >> n;
    vector<vector<int>> dist (n, vector<int>(n, INT_MAX));
    queue<pair<int,int>> q;
    int dr[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dc[8] = {1, -1, 1, -1, 2, -2, 2, -2};
    dist[0][0] = 0;
    q.push({0, 0});
    while(!q.empty()){
        pair cur = q.front();
        q.pop();
        int r = cur.first;
        int c = cur.second;
        for(int i = 0; i < 8; i++){
            int newRow = r + dr[i];
            int newCol = c + dc[i];
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && dist[newRow][newCol] > dist[r][c]+1){
                dist[newRow][newCol] = dist[r][c]+1;
                q.push({newRow, newCol});
            }
        }
    }    

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cout << dist[r][c] << (c+1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
