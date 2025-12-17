#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int nextUnvisited(vector<bool> &arr){
    for(int i = 0; i < arr.size(); i++){
        if(!arr[i]){
            return i;
        }
    }
    return 0;
}

vector<int> bfs(vector<vector<int>> &arr){
    vector<int> res;
    vector<bool> visited(arr.size(), false);
    queue<int> q;

    int src = 0;
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
    vector<vector<int>> arr = {{2, 3},{2}, {0, 1}, {0}};
    vector<int> res = bfs(arr);
    for(int a: res){
        cout << a;
    }
}