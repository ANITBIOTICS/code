#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void recur(int n, int start, int end, int temp){ // number of blocks, start end and peg that you put on temporarily
    if(n == 1){
        cout << start << " " << end << "\n";
        return;
    }else{
        recur(n - 1, start, temp, end);
        cout << start << " " << end << "\n";
        recur(n - 1, temp, end, start);
    }
}
 
 
int main(){
    int n; cin >> n;
    cout << pow(2, n) - 1 << endl;
    recur(n, 1, 3, 2);
    return 0;
}