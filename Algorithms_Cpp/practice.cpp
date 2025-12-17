#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

void insertionSort(vector<int>& arr){

    for(int i = 1; i < arr.size(); i++){ //i is the key
        int value = arr[i];
        int j = i-1;
        while(arr[j] > i && j >=0){
            arr[j+1] = arr[j]; //copy to the right
            j--;
        }
        arr[j+1] = value;
    }
} //notes: don't forget the &

void selectionSort(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        int min_index = i;
        for(int j = i+1; j < arr.size(); j++){
            if(j < i){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int binarySearch(vector<int>& arr, int l, int r, int find){
    if(l > r){
        return -1;
    }
    int m = l + (r-l)/2;
    if(arr[m] == find){
        return m;
    }else if (arr[m] < find){
        binarySearch(arr, m+1, r, find);
    }else{ //arr[m] > find
        binarySearch(arr, l, m-1, find);
    }
} 

void quickSort(vector<int>& arr, int l, int r){
    if(l < r){
        int pivot = r;
        int i = l-1;
        for(int j = l; j < r; j++){
            if(arr[j] < arr[pivot]){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        i++;
        swap(arr[i], arr[pivot]);

        quickSort(arr, l, i-1);
        quickSort(arr, i+1, r);
    }
}

//To-Do: make a version of this that is compatible with unsorted arrays (2d matrix)

void merge(vector<int>& arr, int l, int m, int r){
    int size1 = m - l + 1;
    int size2 = r-m;

    vector<int> L = vector<int>(size1);
    vector<int> R = vector<int>(size2); //how to initialize vector??
    
    for(int i = 0; i < size1; i++){
        L[i] = arr[i+l];
    }

    for(int i = 0; i < size2; i++){
        R[i] = arr[m+i+1];
    }

    int i, j;
    i = 0;
    j = 0;
    int k = l;
   
    while(i < size1 && j < size2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < size1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < size2){
        arr[k] = R[j];
        j++;
        k++;
    }

}//note:don't screw up parameters [r-m+1]

void mergeSort(vector<int>& arr, int l, int r){
    if(l < r){
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }

}

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src){
    int V = adj.size(); //number of points
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //storing pair<int, int>, using a vector to store them, going from Greatest to Least
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.emplace(0, src);

    while(pq.size() != 0)
    { //while pq is not empty
        auto top = pq.top();
        int distance = top.first;
        int point = top.second;
        pq.pop(); //remove top air from the priority queue

        if(distance > dist[point]){
            continue; //skip this iteration of the while loop
        }

        for(auto& node : adj[point]){ //check every node that is connected to Point
            if(dist[node.first] < distance + node.second){
                dist[node.first] = distance + node.second;
                pq.emplace(dist[node.first], node.second);
            }
        }
        //note: when using node, REFERENCE ADJ, not pq. The order is different
    }
    
    return dist;

}

void print(vector<int> arr){
    for(int a: arr){
        cout << a << " ";
    }
}


int main(){
    return 0;

}