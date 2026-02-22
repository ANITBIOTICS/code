#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long hops(long long D, long long K, long long G){
    long long pos = G * K;
    long long baby = llabs(D - pos);
    return G + baby;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    // for inputs
    long long A, B, K;
    int T; // 1 or 2    

    cin >> A >> B >> K >> T;

    long long D = llabs(A - B);

    //special case
    if (D == 0){
        cout << (T  == 1 ? 0 : 2) << "\n";
        return 0;
    }

    //number of K
    long long q = D / K;

    //list to save result
    vector<long long> vals;

    for (long long g = q -1; g <= q + 2; g++){
        if (g >= 0){
            vals.push_back(hops(D, K, g));
        }
    }

    // sorted, and remove duplciated
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());


    if (T == 1){
        cout << vals[0] << "\n";
    }else{
        cout << vals[1] << "\n";
    }

    return 0;
}