# Mean or Average of an Array

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

Given an array  **arr[]**, return the floor value of the mean of its elements.

 **Examples:** 

```
Input: arr[] = [1, 3, 4, 2, 6, 5, 8, 7]
Output: 4
Explanation: Sum of the elements is 1 + 3 + 4 + 2 + 6 + 5 + 8 + 7 = 36, Mean = 36/8 = 4.5, floor(4.5) = 4.
```

```
Input: arr[] = [4, 4, 4, 4, 4]
Output: 4
Explanation: Sum of the elements is 4 + 4 + 4 + 4 + 4 = 20, Mean = 20/5 = 4

```

 **Constraints:** 
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106

## Solution

**Language:** c(gcc5.4)  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-27T16:58:44.475Z  

```c(gcc5.4)
int findMean(int* arr, int size) {
    // code here
    int sum=0;
    for(int i=0;i<size;i++){
        sum = sum + arr[i];
    }
    float mean = sum/size;
    return mean;
}
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/mean0021/1)