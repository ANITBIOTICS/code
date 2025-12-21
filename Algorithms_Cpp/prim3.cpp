#include <bits/stdc++.h>
using namespace std;

int minKey(vector<vector<int>> &arr, vector<int>& res, vector<bool> & visited){
    int min = INT_MAX;
    int min_index;

    for(int a: res){ //for every already visited vertex
        for(int b: arr[a]){ //for every connection going from that vertex
            if(b != 0 && visited[b] == false && arr[a][b] < min){ 
                min = arr[a][b];
                min_index = b;
            }
        }
    }
}

vector<int> prims(vector<vector<int>> &arr){
    vector<bool> visited (arr.size(), false);
    vector<int> res(arr.size());
    vector<int> dist(arr.size(), INT_MAX);

    res.push_back(0);
    visited[0] = true;
    dist[0] = 0;

    for(int i = 0; i < arr.size()-1; i++){ //why is it -1?????
        int index = minKey(arr, res, visited);
        visited[index] = true;
        res.push_back(index);
        
    }
}

int main(){
    vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
                            { 2, 0, 3, 8, 5 },
                            { 0, 3, 0, 0, 7 },
                            { 6, 8, 0, 0, 9 },
                            { 0, 5, 7, 9, 0 } };
    return 0;
}