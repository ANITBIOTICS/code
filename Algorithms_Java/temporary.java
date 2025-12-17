package Algorithms_Java;

public class temporary {

    // Merge function to merge two sorted halves
    public static void merge(int[][] arr2d, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        int[][] L = new int[n1][2];
        int[][] R = new int[n2][2];

        // Copy data to temp arrays L[] and R[]
        for (int i = 0; i < n1; i++) {
            L[i] = arr2d[l + i];
        }

        for (int j = 0; j < n2; j++) {
            R[j] = arr2d[m + 1 + j];  // Corrected this line
        }

        int i = 0;
        int j = 0;
        int k = l;

        // Merge the temp arrays back into the original array arr2d[]
        while (i < n1 && j < n2) {
            if (L[i][1] <= R[j][1]) {
                arr2d[k] = L[i];
                i++;
            } else {
                arr2d[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of L[], if any
        while (i < n1) {
            arr2d[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining elements of R[], if any
        while (j < n2) {
            arr2d[k] = R[j];
            j++;
            k++;
        }
    }

    // MergeSort function to divide and conquer the sorting
    public static void mergeSort(int[][] arr2d, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;

            mergeSort(arr2d, l, m);
            mergeSort(arr2d, m + 1, r);

            merge(arr2d, l, m, r);
        }
    }

    // Function to convert a 1D array to a 2D array with the index as the first column
    public static void to2d(int[] arr, int[][] arr2d, int i) {
        if (i == arr.length) return;  // Fixed this condition to include the last index
        arr2d[i][0] = i + 1;  // First column as the index (1-based)
        arr2d[i][1] = arr[i];  // Second column as the value
        to2d(arr, arr2d, i + 1);
    }

    // Binary Search function to search for a value in the sorted 2D array
    public static int bsc(int[][] arr2d, int l, int r, int find) {
        if (l > r) {
            return -1;  // Element not found
        }
        int m = l + (r - l) / 2;
        if (arr2d[m][1] == find) {
            return arr2d[m][0];  // Return the 1-based index
        } else if (arr2d[m][1] < find) {
            return bsc(arr2d, m + 1, r, find);  // Search in the right half
        } else {
            return bsc(arr2d, l, m - 1, find);  // Search in the left half
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 28, 47, 5098, 198, 37, 21, 598, 3};
        int[][] arr2D = new int[arr.length][2];  // Corrected size of arr2D to match arr
        to2d(arr, arr2D, 0);  // Convert the array to 2D with indices and values
        mergeSort(arr2D, 0, arr2D.length - 1);  // Sort the 2D array based on the second column
        System.out.print(bsc(arr2D, 0, arr2D.length - 1, 198));  // Perform binary search for the value 198
    }
}