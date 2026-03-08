#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*second shorters woudl be replacing one big step with small steps?*/

/*
if distance between A and B < K, you have to only take small steps. (you either only take small steps, or back track until you can take a big step)
your second smallest is max(only take small steps, big steps and back track)


if distance between A and B > K, you take as many big steps as you can then take small steps. that gives you ur smallest
your second smallest is replacing one big step with small steps

*/

int main(){
    ll A; cin >> A; //start here
    ll B; cin >> B; //go to here
    ll K; cin >> K; //size of big hop
    int T; cin >> T;
   
    //make it so that A is always the smaller value;
    if(A > B){
        int temp = A;
        A = B;
        B = temp;
    }

    int numBig = 0; 
    int numSmall = 0;
    ll difference = B-A;

// CHECK THE PART WHER EYOU CALCULATE THE SECOND BIGGEST BECUASE IM HIGH

    if(difference == 0){
        cout << 0; 
    }else if(difference == K){
        if(T == 1){
            cout << 1;
        }else{ //T =2, second smallest
            cout << min(3, (int) difference); //sketchy
        }
    }else if(difference > K){    
       //smallest possible number of steps
        //case where you undershoot with the big steps and add small steps
        int tempDiff = difference;
        while(difference > K){
            numBig++;
            tempDiff -= K;
        }
        numSmall = tempDiff;
        int temp = numBig + numSmall; 

        //case where you overshoot and subtract small steps
        numBig ++;
        numSmall = numBig*K - B+A;
        int smallest, saveBig, saveSmall;

        //saving the number of big and small steps
        if(temp > numBig + numSmall){ //overshooting case is smaller
            smallest = numBig + numSmall;
            saveBig = numBig;
            saveSmall = numSmall;
        }else{ //undershootign case is smaller
            smallest = temp;
            saveBig = numBig --;
            saveSmall = tempDiff;
        }

        if(T == 1) cout << min(smallest, saveSmall+saveBig);
        
        if(T == 2){ // you can the second smallest
            //case where you replace one big hop with a small hop
            numBig = saveBig - 1;
            numSmall = abs(B-A - numBig*K);
            //case where you take one step forward one step back
            cout << min(smallest + 2, numBig+numSmall);           
        }

    }else{ //difference < K
        if(T == 1){
            cout << min(difference, 1+K-B);
        }else{
            if(difference != 1+K-B){
                cout << max(A-B, 1+K-B); //what do you do if these two are equal???
            }else{
                cout << A-B+2; //you take a step back and a step forward
            }
        }
    }
    return 0;
}
