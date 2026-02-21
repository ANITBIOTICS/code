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
        ll tempDiff = difference;
        while(tempDiff >= K){
            numBig++;
            tempDiff -= K;
        }
        numSmall = tempDiff;
        ll temp = numBig + numSmall; 

        //case where you overshoot and subtract small steps
        numBig ++;
        numSmall = numBig*K - difference;
        ll smallest, saveBig, saveSmall;

        //saving the number of big and small steps
        if(temp > numBig + numSmall){ //overshooting case is smaller
            smallest = numBig + numSmall;
            saveBig = numBig;
            saveSmall = numSmall;
        }else{ //undershootign case is smaller
            smallest = temp;
            saveBig = numBig --;
            saveSmall = difference;
        }
        if(T == 1) cout << smallest;
        
        if(T == 2){ // you can the second smallest
            //case where you replace one big hop with a small hop
            numBig = saveBig - 1;
            numSmall = abs(difference - numBig*K);
            //case where you take one step forward one step back
            cout <<  min(smallest + 2, (ll) numBig+numSmall);           
        }

    }else{ //difference < K
        if(T == 1){
            cout << min(abs(difference), abs(1+K-difference));
        }else{ // T = 2
            if(difference != 1+K-difference){
                cout << max(B-A, 1+K-difference); //what do you do if these two are equal???
            }else{
                cout << min(B-A +2, 1+K-difference+2); //you take a step back and a step forward
            }
        }
    }
    return 0;
}

//sample case 2 and 3