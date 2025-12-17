package Algorithms_Java;
public class binarySearch {

    public static int bS(int[] arr, int find){
        int left=0;
        int right = arr.length-1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if (arr[mid] == find){
                return mid;
            } else if (arr[mid] < find){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
        return -1;
    }

    public static int bsc(int[] arr, int left, int right, int find){
        if (left > right){
            return -1;
        }
        
        int mid = left + (right - left) / 2;

        if (arr[mid] == find){
            return mid;
        }else if (arr[mid] < find){
            return bsc(arr, mid + 1, right, find);
        }else{
            return bsc(arr, left, mid -1, find);
        }
    }

    public static void main(String[] args){
        int[] arr = {1, 3, 7, 11, 17, 23, 29, 40, 45};
        int index = bsc(arr, 0, arr.length-1, 239489);
        System.out.print(index);
    }
}
