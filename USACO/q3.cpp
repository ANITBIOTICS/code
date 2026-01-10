#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int N, K; // NxN field, KxK photo
    cin >> N >> K;

    int Q;
    cin >> Q;

    
    int photoPerSide = N-K+1;
    int numPhoto = photoPerSide * photoPerSide;
    
    vector<long long> sum (numPhoto, 0); //beauty of photos
    vector<vector<long long>> field(N, vector<long long>(N, 0));

    long long best = 0;

    for(int i = 0; i < Q; i++){
        int r, c, v;
        cin >> r >> c >> v;

        r--;
        c--;
        
        int orig = field[r][c];
        field[r][c] = v;
        int delta = v - orig;

        int rLo = max(0, r - K + 1);
        int rHi = min(r, N - K);
        int cLo = max(0, c - K + 1);
        int cHi = min(c, N - K);

        for (int row = rLo; row <= rHi; row++) {
        int base = row * photoPerSide;
            for (int col = cLo; col <= cHi; col++) {
                int idx = base + col;
                sum[idx] += delta;
                if (sum[idx] > best){
                    best = sum[idx];
                }
            }
    }
    
    cout << best << "\n";


    }
   
    

    return 0;
}


/* Farmer John is looking at his cows in a magical field and wants to take pictures of subsets of his cows.

The field can be seen as a N×N
 grid (1≤N≤500)
, with a single stationary cow at each location. Farmer John's camera is capable of taking a picture of any K×K
 square that is part of the field (1≤K≤min(N,25))
.

At all times, each cow has a beauty value between 0
 and 106
. The attractiveness index of a picture is the sum of the beauty values of the cows contained in the picture.

The beauty value for every cow starts out as 0
, so the attractiveness index of any picture in the beginning is 0
.

At Q
 times (1≤Q≤3⋅104)
, the beauty of a single cow will increase by a positive integer due to eating the magical grass that is planted on Farmer John's field.

Farmer John wants to know the maximum attractiveness index of a picture he can take after each of the Q
 updates.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line contains integers N
 and K
.
The following line contains an integer Q
.

Each of the following Q
 lines contains three integers: r
, c
, and v
, which are the row, column, and new beauty value, respectively (1≤r,c≤N,1≤v≤106
). It is guaranteed that the new beauty value is greater than the beauty value at that location before.

OUTPUT FORMAT (print output to the terminal / stdout):
Output Q
 lines, corresponding to the maximum attractiveness index of a picture after each update.

SAMPLE INPUT:
4 2
3
2 2 11
3 4 3
3 1 100
SAMPLE OUTPUT:
11
11
111
After the first update, a picture with the maximum attractiveness index is the picture with upper left corner (2,2)
 and lower right corner (3,3)
, which has an attractiveness index of 11+0+0+0=11
.

The second update does not affect the maximum attractiveness index.

After the third update, the picture with the maximum attractiveness index changes to the picture with upper left corner (2,1)
 and lower right corner (3,2)
, which has an attractiveness index of 0+11+100+0=111
.

SAMPLE INPUT:
3 1
3
2 2 3
2 2 5
2 2 7
SAMPLE OUTPUT:
3
5
7
There is only one cow with a positive beauty value, so the maximum attractiveness index will always include that cow.*/