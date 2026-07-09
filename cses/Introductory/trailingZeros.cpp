#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
int main(){
    ll n; cin >> n;
    int numFive = 0;
    for(ll i = 5; i <= n; i *= 5){
        numFive += n / i;
    }
    cout << numFive << endl;
 
    return 0;
}
