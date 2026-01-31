#include <bits/stdc++.h>
using namespace std;

int trib1(int n){ //regular recursive
    // if(n <= 1){
    //     return 0;
    // }else if(n == 2){
    //     return 1;
    // }else{
    //     return trib1(n-1) + trib1(n-2) + trib1(n-3);
    // }


    if(n == 0 || n == 1 || n == 2){
        return 0;
    }

    if (n == 3){
        return 1;
    }else{
        return trib1(n-1) + trib1(n-2) + trib1(n-3);
    }
}

// int trib2(int n, vector<int>& arr){
//     if(n <= 2){
//         return 0;
//     }else if(n == 3){
//         return 1;
//     }

//     if(arr[n] != -1){
//         return arr[n];
//     }

//     arr[n] = trib2(n-1, arr) + trib2(n-2, arr) + trib2(n-3, arr);
//     return arr[n];
// }

int trib3(int n){
    vector<int> arr (n+1);
    //int arr[n];
 
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    //arr[3] = 1;

    for(int i = 3; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return arr[n];
}

void printTrib(int n){
    for(int i = 0; i < n; i++){
        cout << trib3(i) << " ";
    }
}


int main(){
    int n;
    cin >> n;
    //vector<int> arr (n+1, -1);
    trib3(n);
    return 0;
}