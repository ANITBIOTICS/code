#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> bfs(vector<vector<int>> &arr, vector<bool> &visited, vector<int> &res, int src){
    queue<int> q;
    visited[src] = true; 
    q.push(src);
    
    while(q.size()!=0){
        int temp = q.front();
        q.pop();
        for(int a:arr[temp]){ //every point connected to temp
            if(!visited[a]){ //if the point isn't visited, add it to the queue
                visited[a] = true;
                q.push(a);
            }
        }
        res.push_back(temp);
    } 
    return res;
}




int main() {
    vector<int> res;
    vector<vector<int>> arr = {{2, 3},{2}, {0, 1}, {0}, {5}, {4}};
    vector<bool> visited(arr.size(), false);

    vector<int> arr2 = bfs(arr, visited, res, 0);

    for(int i = 0; i < visited.size(); i++){
        if(!visited[i]){
            arr2 = bfs(arr, visited, res, i);
        }
    }
    for(int a: arr2){
        cout << a;
    }
}

/* 
see if i can go without putting 3 vectors in my parameters
*/