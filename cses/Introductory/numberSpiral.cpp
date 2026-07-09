#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll numberSpiral(ll x, ll y){
    ll num;
    if(y > x){ //row
        // if y is even, number is decreasing. if y is odd, number increasing
        //if y is even, the left most number = y^2, if odd, its (y-1)^2 + 1
        if(y%2 == 0){ //even
            num = y * y - x + 1;
        }else{ //odd
            num = (y-1) * (y-1) + x;
        }
    }else{ //column, y <=x
        //if x is odd, number decreasing. if x is even, increasing
        //if x is odd, top number i sx^2, is even, its (x-1)^2 + 1
        if(x%2 != 0){ // odd
            num = x * x - (y-1);
        }else{
            num = (x-1) * (x-1) + y;
        }
    }
    return num;
}
 
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        cout << numberSpiral(y, x) << endl;
    }
    return 0;
}