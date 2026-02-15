#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N;
    cin >> N;

    vector<int> mountains(N);
    for(int i = 0; i < N; i++) cin >> mountains[i];
    vector<long long> res (N+1, INT_MAX);

    vector<long long> dpOdd(N,0), dpEven(N,0);

    //len = 1
    res[1] = 0;

    //len = 2
    if(N >= 2){
        long long best = LONG_MAX;
        for (int i = 0; i + 1 < N; i++){
            dpEven[i] = llabs(mountains[i] - mountains[i+1]);
            best = min(best, dpEven[i]);
        }
        // len = 4, will use len = 2;
        res[2] = best;
    }

    // len >=3

    vector<long long> curt(N, 0);

    // len = 3, len = 1 should cost 0

    // len >=3
    for(int len = 3; len <= N; len++){
        long long best = LONG_MAX;

        auto &src = (len % 2 == 1) ? dpOdd : dpEven;

        for(int i = 0; i + len -1 < N; i++){
            int j = i + len -1;
            curt[i] = src[i+1] + llabs(mountains[i] - mountains[j]);
            best = min(best, curt[i]);
        }

        res[len] = best;

        if (len % 2 == 1){
            dpOdd.swap(curt);
        }else{
            dpEven.swap(curt);
        }
    }

    // for(int size = 1; size < N; size++){
    //     for(int i = 0; i <= N-(size+1); i++){
    //         long long sum = 0;
    //         for(int j = 0; j < (size+1)/2; j++){
    //             sum += abs(mountains[i+j]-mountains[size+i-j]); //suspicious numbers
    //         }
    //         res[size] = min(res[size], sum);
    //     }
    // }


    for(int i = 1; i <= N; i++){
        cout << res[i] << " ";
    }

    return 0;
}