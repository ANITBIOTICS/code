#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    int n;
    cin >> n;

    vector<int> arr (n);
    
    for(int i = 0; i < n; i++) cin >> arr[i];

    int count = 0;
    for(int i = 0; i < n/2; i++){
        if(arr[i] == arr[i+n/2]) count++;
    }
    cout << count * 2;
    return 0;
}