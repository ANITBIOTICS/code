#include <bits/stdc++.h>
using namespace std;

int stairs(vector<int> cost){
    int n = cost.size();
    vector<int> arr (n+1);
 
    arr[0] = cost[0];
    arr[1] = cost[1];
    
    for(int i = 2; i < n; i++){
        arr[i] = cost[i] + min(arr[i-1], arr[i-2]);
    }

    return min(arr[n-1], arr[n-2]);
    
}


int main(){
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << stairs(cost);
    return 0;
}