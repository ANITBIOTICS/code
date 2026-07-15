#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> children(n);
    for(int i = 0; i < n; i++) cin >> children[i];
    sort(children.begin(), children.end());
    ll i = 0, j = n-1, counter = 0;
    while(j >= i){
        if(children[i] + children[j] <=x){
            i++; j--;
        }else{
            j--; 
        }
        counter ++;
    }
    cout << counter;
    return 0;
}
