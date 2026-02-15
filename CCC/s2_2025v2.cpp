#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    long long c; 
    cin >> c;

    long long num=0;

    vector<char> letters; //stores the letters that are repeated
    vector<long long> numF; //the last index that the letter repeats to

    for(int i = 0; i < (int)S.size();){
        char a = S[i++];
        long long count=0;
        while(i < (int)S.size() && isdigit(S[i])){
            count = count*10 + (S[i] - '0');
            i++;
        }

        num += count;
        letters.push_back(a);
        numF.push_back(num);
    }

    long long rep = c%num;
    int res = upper_bound(numF.begin(), numF.end(), rep) - numF.begin();
    cout << letters[res];

    return 0;
}