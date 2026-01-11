#include <bits/stdc++.h>
using namespace std;

int trib(int n){
    if(n == 0 || n == 1){
        return 0;
    }else if (n==2){
        return 1;
    }

    return trib(n-1) + trib(n-2) + trib(n-3);
}

int main(){
    int n;
    cin >> n;
    int num = trib(n);
    cout << num;

    return 0;
}