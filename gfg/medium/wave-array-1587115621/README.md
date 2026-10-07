# Wave Array

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an  **s**  **orted**  array arr[] of integers. Sort the array into a wave-like array (In Place). In other words, arrange the elements into a sequence such that : arr[0] ≥ arr[1] ≤ arr[2] ≥ arr[3] ≤ arr[4] ≥... and so on. If there are multiple solutions, find the lexicographically smallest one.

 **Note:** The given array is sorted in ascending order, and modify the given array in-place without returning a new array.

 **Examples:** 

```
Input: arr[] = [1, 2, 3, 4, 5]
Output: [2, 1, 4, 3, 5]
Explanation: Array elements after sorting it in the waveform are 2, 1, 4, 3, 5.
```

```
Input: arr[] = [2, 4, 7, 8, 9, 10]
Output: [4, 2, 8, 7, 10, 9]
Explanation: Array elements after sorting it in the waveform are 4, 2, 8, 7, 10, 9.

```

```
Input: arr[] = [1]
Output: [1]
```

## Solution

**Language:** c(gcc5.4)  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-07T13:34:36.872Z  

```c(gcc5.4)
void sortInWave(int *arr, int n) {
    // code here
    if(n>1){
    for(int i=0;i<n-1;i=i+2)
    {
     if(arr[i]< arr[i+1]){
       int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1]=temp;
     }
    }
    }
}
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1)