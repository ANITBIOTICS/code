#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        ll k; cin >> k;
        ll d = 1; ll countOfdDigits =  9; ll firstdDigitNum = 1;
        while(k > d * countOfdDigits){
            k-= d* countOfdDigits;
            d++;
            countOfdDigits *= 10;
            firstdDigitNum *=10;
        }

        ll num = firstdDigitNum + (k-1) / d;
        ll pos = (k-1) % d;
        
        ll a = d - 1 - pos;
        ll p = 1;
        for(ll t = 0; t < a; t++) p *= 10;
        cout << num / p % 10 << "\n";
    }
    
        return 0; 
    }
