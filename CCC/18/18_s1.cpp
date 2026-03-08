#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N; cin >> N;
    vector<int> arr(N);
    for(int i = 0 ; i < N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    double minSize = (double) INT_MAX;
    for(int i = 1; i < N-1; i++){
        long double area = 0;
        area += ((arr[i]-arr[i-1])*1.0 )/ 2.0;
        area += ((arr[i+1]-arr[i])*1.0)/2.0;
        if(minSize > area){
            minSize = area;
        }
    }

    // cout << minSize;
    cout << fixed << setprecision(1) << minSize << "\n";
    return 0;
}