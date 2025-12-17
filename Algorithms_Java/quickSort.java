package Algorithms_Java;
public class quickSort {
    public static void qs(int[] arr, int l, int r){
        if(r<l){ 
            return;
        }

        int pivot = arr[r];
        int i = l-1;

        for(int j = l; j < r; j++){
            if(arr[j] < pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = pivot;
        arr[r] = temp;   
     
        qs(arr, l, i);
        qs(arr, i+2, r); 
    }


    public static void main(String[] args){
        int[] arr = {4, 7, 5, 6, 2, 1, 9, 3, 3, 8};

        qs(arr, 0, arr.length-1);
        for(int i : arr){
            System.out.print(i + " ");
        }

    }


}
