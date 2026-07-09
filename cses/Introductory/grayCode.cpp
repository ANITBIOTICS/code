#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
int main(){
    ll n; cin >> n;
    int total = 1 << n;
    for(int i = 0; i < total; i++){
        int g = i ^ (i >> 1);
        for(int b = n - 1; b >= 0; b--)
            cout << ((g >> b) & 1);
        cout << '\n';
    }
    return 0;
}