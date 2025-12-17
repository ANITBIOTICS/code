#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &arr, int src){
    vector<int> dist (7, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.emplace(0, src);

    while(pq.size() != 0){
        auto temp = pq.top();
        int distance = temp.first;
        int vertex = temp.second;
        pq.pop();

        if(dist[vertex] < distance){
            continue;
        }
        
        for(vector<int> part: arr){
            if(part[0] == vertex){
                int point2 = part[1];
                int dist2 = part[2];
                if(distance + dist2 < dist[point2]){    
                    dist[point2] = distance + dist2;
                    pq.emplace(dist[point2], point2);
                }
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> arr = {
        {0, 1, 4}, 
        {0, 2, 2}, 
        {1, 3, 3}, 
        {1, 2, 4}, 
        {2, 3, 4}, 
        {2, 4, 5},
        {3, 5, 2},
        {3, 4, 5},
        {3, 6, 5},
        {5, 6, 2},
        {4, 6, 5},
    };
    vector<int> result = dijkstra(arr, 0);

    return 0;
}