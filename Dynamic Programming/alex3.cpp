#include <bits/stdc++.h>
using namespace std;

int stairs1(int n){
    vector<int> arr (n+1);
    arr[1] = 1;
    arr[2] = 2;
    
    for(int i = 3; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int recur(int n ){
    //base case
    if (n == 0 || n == 1){
        return 1;
    }
    return stairs1(n - 1) + stairs1(n - 2); 
}

int stairs2(int n, vector<int> &arr){
    if (n == 0 || n == 1){
        return 1;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    return stairs2(n-1, arr) + stairs2(n-2, arr);
}

int main(){
    //cout << recur(4);
    vector<int> arr (5, -1);
    cout << stairs2(4, arr);
    return 0;
}