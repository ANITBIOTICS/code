#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N, K;
    cin >> N >> K;

    vector<int> x(K);
    vector<int> y(K);
    vector<int> z(K);
    vector<unsigned> mx(K);
    vector<unsigned> my(K);
    vector<unsigned> mz(K);

    unsigned long long bit = 1u << N; //first one has to be m right. putting the 1st one as O doenst do anything helpful

    for(int i = 0; i < K; i++){
        cin >> x[i] >> y[i] >>  z[i];
        x[i]--; y[i]--; z[i]--;
        mx[i] = 1u<<x[i];
        my[i] = 1u<<y[i];
        mz[i] = 1u<<z[i];
    }

    long long bestWays = 0;
    long long best = -1;

    for(int i = 0; i < bit; i++){ //j< something else
        long long score =0;
        for(int j = 0; j < K; j++){
            // int bitx = (i>>x[j]) & 1;
            // int bity = (i>>y[j]) & 1;
            // int bitz = (i>>z[j]) & 1;

            if(i&mx[j] && !(i&my[j])&& !(i&mz[j])){
                score ++;
            }
        }
    
        if (score > best) {
            best = score;
            bestWays = 1;
        } else if (score == best) {
            bestWays++;
        }
    }

   cout << best << " " << bestWays;


    return 0;
}