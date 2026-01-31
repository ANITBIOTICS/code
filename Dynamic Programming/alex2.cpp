#include <bits/stdc++.h>
using namespace std;

int lucas1(int n){
    vector<int> arr(n+1);
    arr[0] = 2;
    arr[1] = 1;

    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];
}

int lucas2(int n, vector<int>&arr){
    if(n == 0){
        return 2;
    }else if(n ==1){
        return 1;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    arr[n] = lucas2(n-1, arr) + lucas2(n-2, arr);
    return arr[n];
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1, -1);
    cout << lucas2(n, arr);
    return 0;
}