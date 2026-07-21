#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k; cin >> n >> k;
    vector<int> arr(k);
    ll x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> pre(n);
    vector<int> suf(n);
    
    for(int i = 0; i < n; i++){
        int value = (int)x;
        
        suf[i] = value;

        if(i % k == 0) pre[i] = value;
        else pre[i] = pre[i-1] | value;
        
        x = (a * x + b) % c;
    }

    for(int i = n-1; i >= 0; i--){

        if(i == n-1 || i % k == k -1){
            continue;
        }

        suf[i] |= suf[i+1];
    }
    
    int ans = 0;
    for(int l = 0; l <= n - k; l++){
        int r = l+k-1;
        int windowOr = suf[l] | pre[r];
        ans ^= windowOr;
    }
    cout << ans << endl;

    return 0;
}


/*


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> pre(n), suf(n);

    for(int i = 0; i < n; i++){
        int value = (int) x;

        if(i % k == 0) pre[i] = value;
        else pre[i] = pre[i-1] | value;

        suf[i] = value;

        x = (a * x + b)%c;
    }

    for(int i = n-1; i >=0; i--){
        if(i == n-1 || i % k == k-1) continue;

        suf[i] |= suf[i+1];
    }
    int ans = 0;
    for(int l = 0; l <= n-k; l++){
        int r = l + k - 1;
        int orw = suf[l] | pre[r];
        ans ^= orw;
    }
   
    cout << ans << "\n";

    return 0;
}*/