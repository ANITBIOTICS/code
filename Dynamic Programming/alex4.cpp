#include <bits/stdc++.h>
using namespace std;

int recur(int n){
    //base case
    if(n <= 1){
        return 1;
    }else if( n == 2){
        return 2;
    }

    return recur(n-1) + recur(n-2) + recur (n-3);
}

int stairs1(int n, vector<int> &arr){
    if(n <= 1){
        return 1;
    }else if( n == 2){
        return 2;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    arr[n] = recur(n-1) + recur(n-2) + recur (n-3);
    return arr[n];
}

int stairs2(int n){
    vector <int> arr (n+1);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for(int i = 3 ; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    return arr[n];
}

int main(){
    vector<int> arr(5, -1);
    cout << stairs2(4);
    return 0;
}