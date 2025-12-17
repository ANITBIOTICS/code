#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

void insertionSort(vector<int>& arr){
    for(int i = 1; i < arr.size(); i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && key < arr[j]){
            arr[j+1] = arr[j]; //copy arr[j] to the right
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        int min_index = i;
        for(int j = i+1; j < arr.size(); j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

}

void quickSort(vector<int>& arr, int l, int r){
    if(l<r){
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

int binarySearch(vector<int> &arr, int l, int r, int find){
    if(l < r){
        int m = l + (r-l)/2;
        if(arr[m] == find){
            return m;
        }else if(arr[m] < find){
            binarySearch(arr, m+1, r, find);
        }else{
            binarySearch(arr, l, m-1, find);
        }
    }else{
        return -1;
    }
}

void merge(vector<int> &arr, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    vector<int> L (n1);
    vector<int> R (n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[l+i];
    }

    for(int i = 0; i < n2; i++){
        R[i] = arr[m+i+1];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[j] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(vector<int> &arr, int l, int r){
    if(l < r){
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/*
dijkstra
bfs
*/
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src){
    vector<int> dist (adj.size(), INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, src);

    while(pq.size() != 0){
        auto top = pq.top();
        int distance = top.first;
        int vertice = top.second;
        pq.pop();

        if(distance > dist[vertice]){
            continue;
        }

        for(auto& a: adj[vertice]){
            if(dist[a.first] > a.second + distance){
                dist[a.first] = a.second + distance;
                pq.emplace(dist[a.first], a.second);
            }
        }
    }
    return dist;
}

vector<int> bfs(vector<vector<int>> &arr, vector<bool> & visited, vector<int> &result, int src){
    queue<int> q;
    visited[src] = true;
    q.push(src);
    
    while(q.size() != 0){
        int temp = q.front();
        q.pop();

        for(int a: arr[temp]){
            if(!visited[a]){
                visited[a] = true;
                q.push(a);
            }
        }
        result.push_back(temp);
    }

}

void display(vector<int> arr){
    for(int a: arr){
        cout << a;
    }
}

int main(){
    vector<int> result;
    vector<vector<int>> arr = {{2, 3},{2}, {0, 1}, {0}, {5}, {4}};
    vector<bool> visited(arr.size(), false);

    vector<int> arr2 = bfs(arr, visited, result, 0);

    for(int i = 0; i < visited.size(); i++){
        if(!visited[i]){
            arr2 = bfs(arr, visited, result, i);
        }
    }
    for(int a: arr2){
        cout << a;
    }
    return 0;
}