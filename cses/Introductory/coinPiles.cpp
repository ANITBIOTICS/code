#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
int main(){
    ll n; cin >> n;
 
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b; // a and b are the values in stacks a and b
        if(b>=a) swap(a, b); // larger one is always first
        if((a + b) % 3 != 0 || a > 2 * b){ cout << "NO\n"; continue;}
        cout << "YES\n";
    }
    return 0;
}
