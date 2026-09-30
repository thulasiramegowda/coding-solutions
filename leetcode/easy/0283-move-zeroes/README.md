# Move Zeroes

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

 **Note**  that you must do this in-place without making a copy of the array.

 

 **Example 1:** 

```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

```

 **Example 2:** 

```
Input: nums = [0]
Output: [0]

```

 

 **Constraints:** 

- 1 <= nums.length <= 104
- -231 <= nums[i] <= 231 - 1

 

 **Follow up:**  Could you minimize the total number of operations done?

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 20.2 MB (beats 97.45%)  
**Submitted:** 2026-09-30T08:49:40.899Z  

```c
void moveZeroes(int* nums, int numsSize) {
    int j=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0){
            int temp = nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            j++;
        }
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/move-zeroes/)