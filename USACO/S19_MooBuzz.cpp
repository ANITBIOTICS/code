#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int N;
    cin >> N;

    /*
    let the theoretical number of things said be M.
    M = N + M/5 + M/3 - M%15
    
    1, 2, moo, 4, moo, moo, 7,8, moo, moo, 11, moo, 13, 14, moo, 
    1-15 = 7 moos, 8 numbers
    */

    vector<int> numMoo = {1, 2, 4, 7, 8, 11, 13, 14};
    int num = (N-1)/8 * 15 + numMoo[(N-1)%8];
    cout << num;
    return 0;
}