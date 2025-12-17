#include <iostream>
#include <vector>
using namespace std;

void swapArr(vector<int>& arr, int index_left, int index_right){
    int temp = arr[index_left];
    arr[index_left] = arr[index_right];
    arr[index_right] = temp;
}

void quickSort(vector<int>& arr, int l, int r){
    if (l < r){
        int pivot = r;
        int size = r - l + 1;
        int i = l - 1;
        for(int j = l; j < r-l; j++){
            if(arr[j] < arr[pivot]){
                i++;
                swapArr(arr, i, j);
            }
        }

        //traversal of j has ended, now swap pivot to the correct position
        i++;
        swapArr(arr, i, pivot);

        //recursion
        quickSort(arr, l, i-1);
        quickSort(arr, i+1, r);
    }
}

int main(){
    vector<int> arr = {9, 2, 4, 1, 3, 6, 7, 5, 8};
    quickSort(arr, 0, arr.size()-1);
    for(int i: arr){
        cout << i << " ";
    }

    return 0;
}

/*
Problems: Incorrect bounds for the j for-loop
Used for each loop wrong :wilted_flower:
*/