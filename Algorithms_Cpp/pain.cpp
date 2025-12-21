#include <bits/stdc++.h>
using namespace std;

void printMST(vector<int> & parent, vector<vector<int>> & graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[parent[i]][i] << " \n";
}

int minKey(vector<int> & key, vector<bool> & visited){
    int min = INT_MAX;
    int min_index;

    for(int i = 0; i< visited.size(); i ++){
        if(visited[i] == false && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void primMST(vector<vector<int>> & arr){
    vector<bool> visited(arr.size(), false);
    vector<int> key(arr.size(), INT_MAX);
    vector<int> parent(arr.size());

    key[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < arr.size()-1; i++){
        int index = minKey(key, visited);
        visited[index] = true;

        for(int j = 0; j < arr.size(); j++){
            if(arr[index][j] < key[j] && arr[index][j] != 0 && visited[j] == false){
                key[j] = arr[index][j];
                parent[j] = index;
            }
        }
    }

    printMST(parent, arr);
}


int main() {
  	vector<vector<int>> arr = { { 0, 2, 0, 6, 0 },
                        		{ 2, 0, 3, 8, 5 },
                        		{ 0, 3, 0, 0, 7 },
                        		{ 6, 8, 0, 0, 9 },
                        		{ 0, 5, 7, 9, 0 } };

    // Print the solution
    primMST(arr);

    return 0;
}