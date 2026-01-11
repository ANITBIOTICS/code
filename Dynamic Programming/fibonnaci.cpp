#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n == 1){
        return 1;
    }else if (n == 0){
        return 0;
    }

    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cin >> n;
    int num = fib(n);
    cout << num;
    return 0;
}