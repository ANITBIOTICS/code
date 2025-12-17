#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r-m;

    vector<int> L(n1);
    vector<int> R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[m + j + 1];
    }
    
    int i = 0; 
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(vector<int>& arr, int l, int r){
    if(l >= r){
        return;
    }
        int m = l + (r-l)/2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);

    


}

void print(vector<int>& arr){
    for(int a : arr){
        cout << a << " ";
    }
}

int main(){
    vector<int> arr = {9, 5, 3, 4, 6, 7};
    mergeSort(arr, 0, arr.size()-1);
    print(arr);
    return 0;
}