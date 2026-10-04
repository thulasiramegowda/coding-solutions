# Intersection of Two Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two integer arrays `nums1` and `nums2`, return  *an array of their intersection*. Each element in the result must be  **unique**  and you may return the result in  **any order**.

 

 **Example 1:** 

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

```

 **Example 2:** 

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

```

 

 **Constraints:** 

- 1 <= nums1.length, nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 1000

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.9 MB (beats 40.00%)  
**Submitted:** 2026-10-04T05:01:12.588Z  

```c
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int resultIdx = 0;
    
    int* mp = (int*)calloc(1001, sizeof(int));
    
    for (int i = 0; i < nums1Size; i++) {
        mp[nums1[i]] = 1;
    }
    
    for (int i = 0; i < nums2Size; i++) {
        if (mp[nums2[i]]) {
            result[resultIdx++] = nums2[i];
            mp[nums2[i]] = 0;
        }
    }
    
    *returnSize = resultIdx;
    
    free(mp);
    return result;
}
```

---

[View on LeetCode](https://leetcode.com/problems/intersection-of-two-arrays/)