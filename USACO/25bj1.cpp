#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;


bool ok(long long A, long long B, long long cA, long long cB, long long fA, long long x){
    i128 minB = (i128)B;
    i128 maxB = (i128)B + (i128)x;

    i128 num_minB = minB / (i128)cB;
    i128 num_maxB = maxB / (i128)cB;

    i128 usedB = num_minB * (i128)cB + (i128)(cB - 1);
    if(usedB > maxB) usedB = maxB;

    i128 numA = (usedB / (i128)cB) * (i128)cA - usedB;

    if(num_minB + 1 <= num_maxB - 1){
        i128 conv1;
        if((i128)cA < (i128)cB) conv1 = num_maxB - 1;
        else conv1 = num_minB + 1;

        i128 conv2 = conv1 * (i128)cB + (i128)cB - 1;
        i128 tempA = (conv2 / (i128)cB) * (i128)cA - conv2;
        if(numA > tempA) numA = tempA;
    }

    {
        i128 t = maxB;
        i128 tempA = (t / (i128)cB) * (i128)cA - t;
        if(numA > tempA) numA = tempA;
    }

    i128 totA = (i128)A + (i128)B + (i128)x + numA;
    return totA >= (i128)fA;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        long long A, B, cA, cB, fA;
        cin >> A >> B >> cA >> cB >> fA;

        //bsc
        long long l = 0;
        long long r = 1e18;

        while (l < r){
            long long middle = l + (r-l)/2;

            if(ok(A, B, cA, cB, fA, middle)){
                r = middle;
            }else{
                l = middle + 1;
            }
        }
        cout << l << "\n";        
    }

    return 0;
}

/* Bessie the cow has in her possession A
 chips of type A and B
 chips of type B (0≤A,B≤109
). She can perform the following operation as many times as she likes:

If you have at least cB
 chips of type B, exchange cB
 chips of type B for cA
 chips of type A (1≤cA,cB≤109
).
Determine the minimum non-negative integer x
 such that the following holds: after receiving x
 additional random chips, it is guaranteed that Bessie can end up with at least fA
 chips of type A (0≤fA≤109
).

INPUT FORMAT (input arrives from the terminal / stdin):
The first line contains T
, the number of independent test cases (1≤T≤104
).
Then follow T
 tests, each consisting of five integers A,B,cA,cB,fA
.

OUTPUT FORMAT (print output to the terminal / stdout):
Output the answer for each test on a separate line.
Note: The large size of integers involved in this problem may require the use of 64-bit integer data types (e.g., a "long long" in C/C++).

SAMPLE INPUT:
2
2 3 1 1 6
2 3 1 1 4
SAMPLE OUTPUT:
1
0
SAMPLE INPUT:
5
0 0 2 3 5
0 1 2 3 5
1 0 2 3 5
10 10 2 3 5
0 0 1 1000000000 1000000000
SAMPLE OUTPUT:
9
8
7
0
1000000000000000000
For the first test, Bessie initially starts with no chips. If she receives any 9
 additional chips, she can perform the operation to end up with at least 5
 chips of type A. For example, if she receives 2
 chips of type A and 7
 chips of type B, she can perform the operation twice to end up with 6≥5
 chips of type A. However, if she only receive 8
 chips of type B, she can only end up with 4<5
 chips of type A.

For the fourth test, she already has enough chips of type A from the start.

SCORING:
Input 3: cA=cB=1
Inputs 4-5: x≤10
 for all cases
Inputs 6-7: cA=2
, cB=3
Inputs 8-12: No additional constraints.
Problem credits: Benjamin Qi*/