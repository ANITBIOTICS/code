#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    string s; cin >> s;
    sort(s.begin(), s.end());
    int count = 0;
    do { count++;} while (next_permutation(s.begin(), s.end()));
 
    cout << count << "\n";
    do{ cout << s << "\n"; }while(next_permutation(s.begin(), s.end()));
 
    return 0;
}