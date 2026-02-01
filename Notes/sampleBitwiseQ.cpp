#include <bits/stdc++.h>
using namespace std;
/*
you have N light switches in a row, each either ON (1) or OFF (0)
youre given K queries
e ach query gives you three switch positions a, b, c and asks:
does (switch[a] AND switch[b]) XOR switch[c] equal 1 or not
given a starting configuration of switches, count how many queries return 1
input:
line1: N (number of switches) and K (number of queries)
line2: N values (0 or 1) representing switch states
next K lines: three integers a, b, c (1-indexed)
sample input
4 3
1 1 0 1
1 2 3
1 3 4
2 4 3
output
2
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int count = 0;
    for(int i = 0; i < K; i++){
        int a, b, c;
        cin >> a >> b >> c;

        int temp = (arr[a-1]&arr[b-1])^arr[c-1 ];
        if(temp == 1){
            count ++;
        }
    }

    cout << count;
    return 0;
}