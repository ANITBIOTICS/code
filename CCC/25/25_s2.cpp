#include <bits/stdc++.h>
#include <regex>
using namespace std;



int main(){
    string S;
    cin >> S;
    int length = S.size();
    long long c;
    cin >> c;

    long long numRepeats = 0;

    vector<char> letters;
    vector<long long> numF;

    for(int i = 0; i < length;){
        char a = S[i++];


        long long cnt = 0;
        // find the mul dig
        while (i < length && isdigit(S[i])) {
            cnt = cnt * 10 + (S[i++] - '0');
        }

        numRepeats += cnt;
        letters.push_back(a);
        numF.push_back(numRepeats);
    }
    
    long long out = c % numRepeats;
    int indx = upper_bound(numF.begin(), numF.end(), out) - numF.begin();
    cout << letters[indx];

    
    return 0;
}