#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr){
    for(int i = 1; i < arr.size(); i++){
        int key = arr[i];
        int j = i-1;
        while (arr[j] >= key && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


void print(vector<int>& arr){
    for(int a : arr){
        cout << a << " ";
    }
}

int main(){
        vector<int> arr = {9, 5, 3, 4, 6, 7};
        insertionSort(arr);
        print(arr);
        return 0;
}