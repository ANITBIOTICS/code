#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N; cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x == 0){
            arr.pop_back();
        }else{
            arr.push_back(x);
        }
        
    }

    ll sum = 0;
    for(int a: arr)sum += a;
    cout << sum;

    return 0;
}