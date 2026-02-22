#include <bits/stdc++.h>
using namespace std;
#define ll long long

//helper method to deteremine the total number of hops if g big hops are taken
ll hops(ll K, ll diff, ll g){
    ll small = llabs(diff - g*K);
    return g + small;  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    //input values, calculate absolute differnece between starting and ending points
    ll A, B, K; cin >> A >> B >> K;
    int T; cin >> T;

    int diff = llabs(A-B);
    //Special case where the difference is 0
    if(diff == 0){
        cout << (T == 1 ? 0 : 2);
        return 0;
    }

    //have a vector to store the number of total hops taken 
    vector<ll> numHops;
    //calculate the max number, q,  of big hops taken if you don't over shoot
    int q = diff/K;

    //the min number of steps would be from q or one more than q (overshoot then go back with small steps)
    //check one below and one above both of those q values so that you also store second smallest
    for(int g = q-1; g <= q+2; g++){
        if(g>=0) numHops.push_back(hops(K, diff, g));
    }

    //sort the vector of values, removing duplicates.
    sort(numHops.begin(), numHops.end());
    numHops.erase(unique(numHops.begin(), numHops.end()), numHops.end());

    cout << (T == 1? numHops[0] : numHops[1]);

    return 0;
}