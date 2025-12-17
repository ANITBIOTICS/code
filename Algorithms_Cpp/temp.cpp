#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra( vector<vector<pair<int, int>>>& adj, int src){
    int V = adj.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.emplace(0, src);
    
    while(pq.size() != 0){
        auto top = pq.top();
        int vertice = top.first;
        int distance = top.second;

        pq.pop();

        if(distance > dist[vertice]){
            continue;
        }

        for(auto& node : adj[vertice]){ 
           if(dist[node.first] > (dist[vertice] + node.second)){
                dist[node.first]  = dist[vertice] + node.second;
                pq.emplace(dist[node.first] , dist[vertice] + node.second);
           }
        }
    }

    return dist;
}


int main() {
    int src = 0;

    vector<vector<pair<int,int>>> adj(5);
    adj[0] = {{1,4}, {2,8}};
    adj[1] = {{0,4}, {4,6}, {2,3}};
    adj[2] = {{0,8}, {3,2}, {1,3}};
    adj[3] = {{2,2}, {4,10}};
    adj[4] = {{1,6}, {3,10}};

    vector<int> result = dijkstra(adj, src);

    for (int d : result)
        cout << d << " ";
    cout << " ";

    return 0;
}