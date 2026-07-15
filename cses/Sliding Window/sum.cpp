#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> arr(k); // window
    ll x, a, b, c; cin >> x >> a >> b >> c;
    ll thing = 0;
    ll sum  = 0;
    for(int i = 0; i < k; i++){
        arr[i] = x;
        sum += x;

        if(i != k -1) x = (a * x + b) % c;    
    }
    thing = sum;

    for(int i = k; i < n; i++){
        ll indx = i % k;
        x = (a * x + b) % c;

        sum -= arr[indx];
        sum += x;
        arr[indx] = x;

        thing ^= sum;
    }
    cout << thing << "\n";


    // ll arrindx = 0; // tracking the index that you edit
    // ll numWindows = n - k + 1;

    // //first window
    // arr[0] = x;
    // for(ll i = 1; i < k; i++){
    //     arr[i] = (a * arr[i-1] + b) % c;
    //     thing += arr[i]; 
    // }

    // ll sum = thing;
    // while(numWindows > 0){
    //     sum -= arr[arrindx]; //subract removed number from the sum
    //     arr[arrindx] = (arr[(arrindx-1) %k] * a + b)%c; //replace number with new one
    //     sum += arr[arrindx]; //add new sum
    //     arrindx = (arrindx + 1) % k; //increment the number you are changing in the window
    //     thing ^= sum;
    //     numWindows --;
    // }
    // cout << thing << "\n";
    return 0;
}
