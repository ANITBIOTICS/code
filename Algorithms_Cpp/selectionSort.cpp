#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr){
    for(int i = 0; i < arr.size() -1; i++){
        int min_index = i;
        for (int j = i+1; j < arr.size(); j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}


void print(vector<int>& arr){
    for(int a : arr){
        cout << a << " ";
    }
}

int main(){
    vector<int> arr = {9, 5, 3, 4, 6, 7};
    selectionSort(arr);
    print(arr);
    return 0;
}