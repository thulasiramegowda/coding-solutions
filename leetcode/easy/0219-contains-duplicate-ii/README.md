# Contains Duplicate II

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer array `nums` and an integer `k`, return `true`  *if there are two  **distinct indices*** `i` *and* `j` *in the array such that* `nums[i] == nums[j]` *and* `abs(i - j) <= k`.

 

Original
C
 **Example 1:** 

```
Input: nums = [1,2,3,1], k = 3
Output: true

```

 **Example 2:** 

```
Input: nums = [1,0,1,1], k = 1
Output: true

```

 **Example 3:** 

```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109
- 0 <= k <= 105

## Solution

**Language:** C  
**Runtime:** 33 ms (beats 72.12%)  
**Memory:** 43.1 MB (beats 31.89%)  
**Submitted:** 2026-11-18T14:21:43.187Z  

```c
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    typedef struct {
        int key;
        int index;
        int used;
    } Entry;

    if (k == 0 || numsSize < 2) {
        return false;
    }

    int size = 1;
    while (size < numsSize * 2) {
        size *= 2;
    }

    Entry* table = calloc(size, sizeof(Entry));

    if (table == NULL) {
        return false;
    }

    for (int i = 0; i < numsSize; i++) {
        unsigned int h = ((unsigned int)nums[i] * 2654435761u) & (size - 1);

        while (table[h].used && table[h].key != nums[i]) {
            h = (h + 1) & (size - 1);
        }

        if (table[h].used && i - table[h].index <= k) {
            free(table);
            return true;
        }

        table[h].key = nums[i];
        table[h].index = i;
        table[h].used = 1;
    }

    free(table);
    return false;
}
```

---

[View on LeetCode](https://leetcode.com/problems/contains-duplicate-ii/)