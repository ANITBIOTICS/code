#include <bits/stdc++.h>
#include <regex>
using namespace std;



int main(){
    string S;
    cin >> S;
    int length = S.size();
    int c;
    cin >> c;
    regex numberRegex("(\\d+)");
    sregex_iterator it(S.begin(), S.end(), numberRegex);
    sregex_iterator end;

    
    
//isdigit9) gives you boolean
    return 0;
}