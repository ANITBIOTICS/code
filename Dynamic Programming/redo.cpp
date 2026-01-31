#include <bits/stdc++.h>
using namespace std;

int fib1(int n){
    vector<int> arr(n);

    arr[0] = 0; 
    arr[1] = 1;

    for(int i = 2; i < n; i++){
        arr[i] = arr[i-1]  + arr[i-2];
    }
    return arr[n];
}

int fib2(int n, vector<int> &arr){
    if(n <= 1){
        return n;
    }
    

    // check if the result is already in the memo table
    if(arr[n] != -1){
        return arr[n];
    }

    // if(arr[n] == -1){
    //     arr[n] = arr[n-1] + arr[n-2];
    // }

    arr[n] = fib2(n-1, arr) + fib2(n-2, arr);
    
    
    return arr[n];
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1, -1);
    cout << fib2(n, arr);
    return 0;
}


/*
create an array arr of size n+1 to store values from th 0 to nth numbers of the fib sequence. Assign -1 to each element. 

Make a function that takes parameters n and arr and returns an int. 

You first check if you already have the number stored inside of arr. If it is, just use it. 
If not, calculate it by recursively calling the function and adding the n-1th and n-2th numbers.
*/