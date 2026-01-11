#include <bits/stdc++.h>
using namespace std;

int lucas(int n){
    if(n == 0){
        return 2;
    }else if (n == 1){
        return 1;
    }
    return lucas(n-1) + lucas(n-1);
}

int main(){
    int n; 
    cin >> n;
    int num = lucas(n);
    cout << num;
    return 0;
}