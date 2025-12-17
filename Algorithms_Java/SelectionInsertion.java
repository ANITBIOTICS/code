package Algorithms_Java;
public class SelectionInsertion {

    public static void insertionSort(int[] arr){
        for (int i = 0; i < arr.length-1; i++) {
            int min = i;

            for(int j = i+1; j<arr.length; j++){
                if (arr[j]<arr[min]){
                    min = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    public static void selectionSort(int[] arr){
        for(int i=1; i<arr.length; i++){
            int key = arr[i];
            int j= i-1;
            while(j>=0 && arr[j]>key){// soemthign funny
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
       
    }
        //    
    public static void printArray(int[] arr){
        for(int a: arr){
            System.out.print(a + " ");
        }
    }

    public static void main(String[] args) {
        int[] arr = {12, 43, 67, 14, 8};
        selectionSort(arr);
        printArray(arr);
    }
    
}
