package Algorithms_Java;
public class binarySearch2 {
    
    static void merge(int[] arr, int left, int mid, int right){
        
        int n1 = mid - left + 1;
        int n2 = right-mid; //check this

        int[] L = new int [n1];
        int[] R = new int [n2];

        for(int i = 0; i < n1; i++){
            L[i] = arr[left + i];
        }
        for(int j = 0; j < n2; j++){
            R[j] = arr[mid + 1 + j];
        }

        int i = 0; 
        int j = 0;
        int k = left;

        while(i < n1 && j < n2){
            if(L[i] <= R[j]){ //check
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
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
            k++;
            j++;
        }

    }



    static void mergeSort(int[] arr, int left, int right){

        if(left<right){
            int mid = left + (right-left)/2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid+1, right);

            merge(arr, left, mid, right);
        }
    }

    static int bS(int[] arr, int l, int r, int find){
        if(r<=l){
            return -1;
        }
        int m = l + (r-l)/2;
        if(arr[m] == find){
            return m;
        }else if (arr [m] < find){
            return bS(arr, m+1, r, find);
        }else{
            return bS(arr, l, m-1, find);
        }


    }


    public static void main (String[] args){
        int[] arr = {10, 19, 8, 4, 5, 29, 2, 19, 40};
        int find = 29; 
        //determine if its unsorted

        mergeSort(arr, 0, arr.length-1);
        bS(arr, 0, arr.length-1, find);

        for(int a: arr){
            System.out.print(a + " ");
        }

    }
}
