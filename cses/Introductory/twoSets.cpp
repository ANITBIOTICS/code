#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll n; cin >> n;
    ll total = n * (n+1) /2;
    if(total%2 != 0){
        cout << "NO";
        return 0;
    }
 
    ll half = total / 2;
    // ll difference = half;
    vector<ll> used;
    vector<ll> unused;
    ll numUsed = 0;
    for(int i = n; i >= 1; i--){
        if(half >= i){
            used.push_back(i);
            half -= i;
        }else{
            unused.push_back(i);
        }
    }
 
    cout << "YES\n";
 
    cout << used.size() << endl;
    for(ll a: used) cout << a << " ";
    cout << endl << unused.size() << endl;
    for(ll a: unused) cout << a << " ";
    
    return 0;
}
