#include <iostream>
#include <math.h>

/*
 * for array of data  in the range [0,k] we will sort with save order the array in complexity of O(n + k)
 * 1) allocate array of Data objects in K size.
 * 2) histogram of counting the elements in the index i.
 * 3) find for each object in the sorted array what is the last index who storage him.
 * 4) run on the objects in the oldArray we are sorting from the end to the start, and storage
 *    in the last index what we saved in arr, then we reduce the counter of the object in srr[object]
 */
namespace sortingAlgorithms {
///=======================================countingSort================================================================
    __attribute__((unused)) int *countingSort(const int *oldArr, int len, int K) {
        //allocate arrays in size k
        int *arrLastIndex;
        int *sortedArr;
        try {
            arrLastIndex = new int[K];
            sortedArr = new int[len];
        } catch (__attribute__((unused)) std::exception const &ex) {
            std::cerr << ex.what() << '\n';
        }
        for (int i = 0; i < K; ++i) {
            arrLastIndex[i] = 0;
        }
        //Histogram of counting the elements in the index i.
        for (int i = 0; i < len; ++i) {
            arrLastIndex[oldArr[i]]++;
        }
        //find for each object in the sorted array what is the last index who storage him
        for (int i = 1; i < K; ++i) {
            arrLastIndex[i] = arrLastIndex[i - 1] + arrLastIndex[i];
        }
        //run on the objects in the oldArray we are sorting from the end to the start, and storage
        //in the last index what we saved in arr, then we reduce the counter of the object in srr[object]
        for (int i = len - 1; i >= 0; --i) {
            sortedArr[arrLastIndex[oldArr[i]]] = oldArr[i];
            arrLastIndex[oldArr[i]]--;
        }
        return sortedArr;
    }

///=======================================radixSort================================================================
    /*
     * sorting (balanced) n numbers with d digit types , in base b, with complexity  O(d•(n+b))
     * the algorithm sorting in the level i  the according the digit number i from the end
     */

// A utility function to get maximum value in arr[]
    int getMax(int arr[], int n) {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }

// A function to do counting sort of arr[] according to
// the digit represented by exp.
    void countSort(int arr[], int n, int exp) {
        int output[n]; // output array
        int i, count[10] = {0};

        // Store count of occurrences in count[]
        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        // Change count[i] so that count[i] now contains actual
        //  position of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // Copy the output array to arr[], so that arr[] now
        // contains sorted numbers according to current digit
        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }

// The main function to that sorts arr[] of size n using
// Radix Sort
    void radixsort(int arr[], int n) {
        // Find the maximum number to know number of digits
        int m = getMax(arr, n);

        // Do counting sort for every digit. Note that instead
        // of passing digit number, exp is passed. exp is 10^i
        // where i is current digit number
        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(arr, n, exp);
    }
}
///=======================================[0,n^2-1]================================================================
/*
 * idea only :
 * sorting array of n numbers in the range [0,n^-1]  in complexity of o(n•log(n))
 * convert all the numbers  to base n complexity of  o(1) per object
 * (this algorithm complexity dependes on the processor of the computer,perhaps the operations divide and mult rum in fix time  )
 * n^3 , n^2 , n ,  n^0
 * 0     1     1    12  = n^2 + n + 12
 * in this range for each number have 2 digit  maximum
 * now we use radixsort
 */


