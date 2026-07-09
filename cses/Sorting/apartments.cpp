#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<int> people(n);
    vector<int> apartments(m);
    for(int i = 0; i < n; i++) cin >> people[i];
    for(int i = 0; i < m; i++) cin >> apartments[i];
    sort(people.begin(), people.end());
    sort(apartments.begin(), apartments.end());

    ll i = 0, j = 0; ll numppl = 0;
    while(i < n && j < m){
        if(people[i] + k < apartments[j])i++;//the apartment does not meet the minimum, check the next house    
        else if(people[i] - k > apartments[j])j++; // the smallest psosible apartment is too big, skip the person    
        else{ 
            numppl ++;
            i++;
            j++;
        }
    }

    cout << numppl;
    return 0;
}
