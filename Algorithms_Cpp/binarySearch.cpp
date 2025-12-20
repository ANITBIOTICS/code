#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int find){
    if(l<=r){
        int m = l + (r-l)/2;
        if(arr[m] == find){
            return m;
        }else if(arr[m] < find){
            return binarySearch(arr, m+1, r, find);
        }else{
            return binarySearch(arr, l, m-1, find);
        }
    }    
    return -1;   
} 

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << binarySearch(arr, 0, arr.size(), 4)+1;
    return 0;
}