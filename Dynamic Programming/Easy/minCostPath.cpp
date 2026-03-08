#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dijkstra(vector<vector<int>>&cost) {

    int m = cost.size();
    int n = cost[0].size();
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {1, 1}};

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    dist[0][0] = cost[0][0];
    pq.push({cost[0][0], 0, 0});

    while (!pq.empty()) {
        vector<int> curr = pq.top();
        pq.pop();

        int x = curr[1];
        int y = curr[2];

        if (x == m-1 && y == n-1) {
            return dist[x][y];
        }

        for (auto &a : directions) {
            int x2 = x+a.first;
            int y2 = y+a.second;
            if (x2 < m && y2 < n) {
                if (dist[x2][y2] > dist[x][y] + cost[x2][y2]) {
                    dist[x2][y2] = dist[x][y] + cost[x2][y2];
                    pq.push({dist[x2][y2], x2, y2});
                }
            }
        }



    }

    return dist[m - 1][n - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    return 0;
}
