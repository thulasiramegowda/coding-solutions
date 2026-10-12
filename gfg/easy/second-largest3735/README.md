# Second Largest

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an array of positive integers  **arr[]**, return the second largest element from the array. If the second largest element doesn't exist then return  **-1.** 

Note: The second largest element should not be equal to the largest element.

 **Examples:** 

```
Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
```

```
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
```

```
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.
```

## Solution

**Language:** c(gcc5.4)  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-12T14:26:05.414Z  

```c(gcc5.4)

int getSecondLargest(int *arr, int n) {
    int first = arr[0];
    int second = -1;

    for (int i = 1; i < n; i++) {

        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < first && (second == -1 || arr[i] > second)) {
            second = arr[i];
        }
    }

    return second;
}

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/second-largest3735/1)