# XOR Operation in an Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer `n` and an integer `start`.

Define an array `nums` where `nums[i] = start + 2 * i` (**0-indexed**) and `n == nums.length`.

Return  *the bitwise XOR of all elements of*  `nums`.

 

 **Example 1:** 

```
Input: n = 5, start = 0
Output: 8
Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
Where "^" corresponds to bitwise XOR operator.

```

 **Example 2:** 

```
Input: n = 4, start = 3
Output: 8
Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.

```

 

 **Constraints:** 

- 1 <= n <= 1000
- 0 <= start <= 1000
- n == nums.length

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.4 MB (beats 77.15%)  
**Submitted:** 2026-09-28T12:30:43.449Z  

```c
int xorOperation(int n, int start) {
   int nums[n];
    for(int i=0;i<n;i++){
      nums[i] = start + 2 * i;
    }
    int answer=0;
    for(int i=0;i<n;i++){
    answer=answer ^ nums[i];
    }
    return answer;
}
```

---

[View on LeetCode](https://leetcode.com/problems/xor-operation-in-an-array/)