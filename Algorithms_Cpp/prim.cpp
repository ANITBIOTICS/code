#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

vector<int> prims(vector<vector<int>> arr, vector<bool> visited, int src){
    queue<int> q;
    vector<int> res(arr.size());
    visited[src] = true;
    q.push(src);

    while(q.size()!= 0){
        int temp = q.front();
        q.pop();

        int min_index = 0;
        for(int a: arr[temp]){
            if(arr[temp][a]<arr[temp][min_index] && !visited[a]){ //finding smallest weight unvisited vertex
                min_index = a;
            }
        }
        if(min_index != 0){
                    q.push(min_index);

        }        
    }


}

void printArr(vector<int> arr){
    for(int a: arr){
        cout << a;
    }
}

int main(){
    vector<vector<int>> arr =  { { 0, 2, 0, 6, 0 }, //0 to 1 has weight 2, 0 to 3 has weight 6
                        		{ 2, 0, 3, 8, 5 },
                        		{ 0, 3, 0, 0, 7 },
                        		{ 6, 8, 0, 0, 9 },
                        		{ 0, 5, 7, 9, 0 } };
    vector<bool> visited(arr.size(), false);
    for(int i = 0; i < arr.size(); i++){
        if(!visited[i]){
            vector<int> res = prims(arr, visited, i);
            printArr(res);
        }
    }
    return 0;
}