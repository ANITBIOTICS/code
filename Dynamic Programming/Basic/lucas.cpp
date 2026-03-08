#include <bits/stdc++.h>
using namespace std;

int lucas1(int n){
    if(n == 0){
        return 2;
    }else if (n == 1){
        return 1;
    }
    return lucas1(n-1) + lucas1(n-1);
}

int lucas2(int n){
    if(n == 0) return 2;
    if(n == 1) return 1;

    int prev1 = 2;
    int prev2 = 1;
    int curr = 0;

    for(int i = 2; i < n+1; i ++){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
}

int main(){
    int n; 
    cin >> n;
    int num = lucas2(n);
    cout << num;
    return 0;
}