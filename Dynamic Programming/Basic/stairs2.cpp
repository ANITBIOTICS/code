#include <bits/stdc++.h>
using namespace std;

int stairs(int n){
    //num ways to get to n = get to n-1 (then take 1 step) + get to n-2 (then take 2 step)

    if(n == 1 || n == 0){
        return 1;
    }

    int curr;
    int prev1 = 1;
    int prev2 = 1;

    for(int i = 2; i < n+1; i++){ //check
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return curr;
}

int main(){
    int n;
    cin >> n;
    int num = stairs(n);
    cout << num;
    return 0;
}
