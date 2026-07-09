#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    string s; cin >> s;
    int n = s.size();
    int start = 0;
    int end = 0;
    int maxLength = -1;
    int length = 1;
    for(int i = 0; i < n; i++){
        end ++;
        if(s[end] == s[start]) length ++;
        else{
            start = end;
            maxLength = max(maxLength, length);
            length = 1;
        }
    }
 
    cout << maxLength;
    return 0;
}