#include <bits/stdc++.h>
using namespace std;

int s1(long long N){
    if(N < 4)return 0; 
    else if (N == 5 || N == 4) return 1;
    
    long long ans = 0;
    for (long long b = 0; 5 * b <= N; b++) {
        long long r = N - 5 * b;
        if (r % 4 == 0) ans++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    long long N;
    cin >> N;
    cout << s1(N);
    return 0;
}