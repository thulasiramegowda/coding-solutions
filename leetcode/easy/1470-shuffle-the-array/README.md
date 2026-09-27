# Shuffle the Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the array `nums` consisting of `2n` elements in the form `[x1,x2,...,xn,y1,y2,...,yn]`.

 *Return the array in the form*  `[x1,y1,x2,y2,...,xn,yn]`.

 

 **Example 1:** 

```
Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

```

 **Example 2:** 

```
Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]

```

 **Example 3:** 

```
Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]

```

 

 **Constraints:** 

- 1 <= n <= 500
- nums.length == 2n
- 1 <= nums[i] <= 10^3

## Solution

**Language:** C  
**Runtime:** 16 ms (beats 30.99%)  
**Memory:** 12.4 MB (beats 31.11%)  
**Submitted:** 2026-09-27T18:05:52.713Z  

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
     int* answer = malloc(2*n * sizeof(int));
     for(int i=0;i<=n-1;i++){
        answer[2*i]=nums[i];
        answer[2*i+1]=nums[n+i];
     }
     *returnSize = numsSize;
     return answer;
}
```

---

[View on LeetCode](https://leetcode.com/problems/shuffle-the-array/)