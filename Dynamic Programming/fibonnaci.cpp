#include <bits/stdc++.h>
using namespace std;

int fib1(int n){
    if(n == 1){
        return 1;
    }else if (n == 0){
        return 0;
    }

    return fib1(n-1) + fib1(n-2);
}

int fib2(int n){
    vector<int> dp (n);
    
}

int main(){
    int n;
    cin >> n;
    int num = fib1(n);
    cout << num;
    return 0;
}