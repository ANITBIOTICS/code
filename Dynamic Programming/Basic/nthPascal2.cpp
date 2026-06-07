#include <bits/stdc++.h>
using namespace std;
#define ll long long

int recur(int i, int j, int n){
    if(i == 0 || i == 1){ // on the top 2 rows
        return 1;
    }else if (j == 0 || j == n){ //left column
        return 1;
    }

    return recur(i-1, j, n) + recur(i-1, j-1, n); 
}


int main(){
    

    return 0;
}
