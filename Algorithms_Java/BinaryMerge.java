package Algorithms_Java;
public class BinaryMerge {

    public static void merge(int[][] arr2d, int l, int m, int r){
        int n1 = m-l+1;
        int n2 = r-m;

        int[][] L = new int[n1][2];
        int[][] R = new int[n2][2];

        for (int i = 0; i < n1; i++){
            L[i] = arr2d[l+i];
        }

        for (int j = 0; j < n2; j++){
            R[j] = arr2d[m+j+1]; 
        }

        int i = 0;
        int j = 0;
        int k = l;

        while( i < n1 && j < n2){
            if(L[i][1] <= R[j][1]){
                arr2d[k] = L[i];
                i++;
            }else{
                arr2d[k] = R[j];
                j++;
            }
            k++;
        }

        while(i < n1){
            arr2d[k] = L[i];
            i++;
            k++;
        }

        while(j < n2){
            arr2d[k] = R[j];
            j++;
            k++;
        }
    
    
    }

    public static void mergeSort(int[][] arr2d, int l, int r){
        if (l < r){
            int m = l + (r-l)/2;

            mergeSort(arr2d, l, m);
            mergeSort(arr2d, m+1, r);

            merge(arr2d, l, m, r);
        }
    }

    public static void to2d(int[] arr, int[][] arr2d, int i){
        if (i == arr.length) return;
        arr2d[i][0] = i+1;
        arr2d[i][1] = arr[i];
        to2d(arr, arr2d, i+1);
    }

    public static int bsc(int[][] arr2d, int l, int r, int find){
        if(l > r){
            return -1;
        }
        int m = l + (r-l)/2;
        if(arr2d[m][1] == find){
            return arr2d[m][0];
        }else if (arr2d[m][1] < find){
            return bsc(arr2d, m+1, r, find);
        }else{
            return bsc (arr2d, l, m-1, find);
        }

    }
    public static void main(String[] args){
        int[] arr = {1, 28, 47, 5098, 198, 37, 21, 598, 3};
        int[][] arr2D = new int[arr.length-1][2];
        to2d(arr, arr2D, 0);
        mergeSort(arr2D, 0, arr2D.length-1);
        System.out.print(bsc(arr2D, 0, arr2D.length-1, 198));

    }
    
}

// homework: suffer :D
//try to see if can do binary/merge without 2d arrays. :C while still giving the index of the original array
// review dij-thingk alg