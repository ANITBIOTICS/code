#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;

    int width1 = A + X;
    int height1 = max(B, Y);

    int width2 = max(A, X);
    int height2 = B + Y;
    
    cout << min(2*(width1+height1), 2*(width2+height2));

    return 0;
}