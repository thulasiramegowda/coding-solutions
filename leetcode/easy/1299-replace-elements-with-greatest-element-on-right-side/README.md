# Replace Elements with Greatest Element on Right Side

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an array `arr`, replace every element in that array with the greatest element among the elements to its right, and replace the last element with `-1`.

After doing so, return the array.

 

 **Example 1:** 

```
Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation: 
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.

```

 **Example 2:** 

```
Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.

```

 

 **Constraints:** 

- 1 <= arr.length <= 104
- 1 <= arr[i] <= 105

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 64.3 MB (beats 11.77%)  
**Submitted:** 2026-09-29T16:38:26.204Z  

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {

    int* answer = malloc(arrSize * sizeof(int));

    int maxRight = -1;

    for (int i = arrSize - 1; i >= 0; i--) {

        answer[i] = maxRight;

        if (arr[i] > maxRight) {
            maxRight = arr[i];
        }
    }

    *returnSize = arrSize;

    return answer;
}
```

---

[View on LeetCode](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/)