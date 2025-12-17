#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> kahn(vector<vector<int>> &arr){
    vector<int> res;
    queue<int> q;
    vector<int> inDeg (arr.size(), 0);

    for(vector<int> arr1: arr){
        for(int a: arr1){
            inDeg[a] ++;
        }   
    }

    for(int i = 0; i < inDeg.size(); i++){
        if(inDeg[i] == 0){
            q.push(i);
        }
    }

    while(q.size() != 0){
        int temp = q.front();
        res.push_back(temp);
        q.pop();
        
        for(int a: arr[temp]){
            inDeg[a] -= 1;
            if(inDeg[a] == 0){
                q.push(a);
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>> arr = {{1},{2}, {3}, {}, {5}, {1, 2}};
    vector<int> res = kahn(arr);
    for(int a: res){
        cout << a << " ";
    }
}

/* dont forget to add to queue >:C */