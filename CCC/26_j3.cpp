#include <bits/stdc++.h>
using namespace std;
#define ll long long

int isN(char n, char m){
    if(n == m) {
        return 3;
    }else{
        if((n == 'R' && m == 'G' )||(n == 'G' && m == 'B') || (n == 'B' && m == 'R' )){
            return 1; //1 means n win
        }else if ((m == 'R' && n == 'G' )||(m == 'G' && n == 'B') || (m == 'B' && n == 'R' )){
            return 0;
        }
    }

    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 


    string N, M; cin >> N >> M;
    int ncount = 0;
    int mcount = 0;

    int n = 0;
    int m = 0;

    while(n < (int)N.size() && m < (int)M.size()){
        if(isN(N[n], M[m]) == 3){
            ncount ++; mcount ++;
            n++; m++;
        }else if(isN(N[n], M[m]) == 1){ // n wins
            ncount ++;
            m++;
        }else{ //m wins
            mcount ++;
            n++;
        }
    }

    while(n < (int)N.size()){
        ncount ++;
        n++;
    }

    while(m < (int)M.size()){
        mcount ++;
        m++;
    }


    cout << ncount << endl << mcount;
    return 0;
}
