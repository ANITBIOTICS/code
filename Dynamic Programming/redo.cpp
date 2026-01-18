#include <bits/stdc++.h>
using namespace std;

int fib1(int n){ //plain recursion
    if(n <= 1){
        return n;
    }
    return fib1(n-1) + fib1(n-2);
}




int fib2(int n, vector<int> & arr){ //memoization (top down)
    if(n <= 1){ //base case
        return n;
    }

    if(arr[n] != -1){ //see if the value is already stored
        return arr[n];
    }

    arr[n] =  arr[n-1] + arr[n-2];
    return arr[n];
    
}




int fib3(int n){ //tabulation (bottom up)
    vector<int> arr(n+1);
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i < n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, -1);
    cout << fib2(n, arr);
    return 0;
}