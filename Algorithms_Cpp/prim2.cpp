#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

vector<int> prims(vector<vector<int>> & arr, int src){
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int,int>>> pq;
    vector<bool> visited (arr.size(), false);
    visited[src] = true;
    vector<int> res;

    pq.emplace(0, src);

    while(pq.size() != 0){
        
    }

}



int main(){
    vector<vector<int>> arr =  { { 0, 2, 0, 6, 0 },
                                    { 2, 0, 3, 8, 5 },
                                    { 0, 3, 0, 0, 7 },
                                    { 6, 8, 0, 0, 9 },
                                    { 0, 5, 7, 9, 0 } };

    return 0;

}