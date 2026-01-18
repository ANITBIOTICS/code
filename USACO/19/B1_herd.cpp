#include <bits/stdc++.h>
using namespace std;

/*
look for a length N chunk that has the most cows

Special case: 
C C C C _ ... _ C

*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 


    int N; 
    cin >> N;
    vector<bool> arr (false);

    for(int i = 0; i < N; i ++){
        //minimums
        int minMoves;
        if (arr[N-2] - arr[0] == (long long)N - 2 && arr[N-1] - arr[N-2] > 2){
            minMoves = 2;
        }else if (arr[N-1] - arr[1] == (long long)N - 2 && arr[1] - arr[0] > 2){
            minMoves = 2;
        }else{
            int best = 0;
            int j = 0;
            for (int i = 0; i < N; i++) {
            while (j + 1 < N && arr[j + 1] - arr[i] <= (long long)N - 1) j++;
            best = max(best, j - i + 1);
            if (j < i) j = i;
        }
        minMoves = N - best;
    }
    //maximum
    int maxMoves = max(arr[N-2] - arr[0], arr[N-1] - arr[1]) - ((long long)N - 2);
    cout << minMoves << "\n" << maxMoves << "\n";

    }
    



    return 0;
}