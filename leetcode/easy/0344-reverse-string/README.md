# Reverse String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array in-place with `O(1)` extra memory.

 

 **Example 1:** 

```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

```

 **Example 2:** 

```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s[i] is a printable ascii character.

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 17.5 MB (beats 99.51%)  
**Submitted:** 2026-09-30T08:52:57.708Z  

```c
void reverseString(char* s, int sSize) {
    int left=0;
    int right = sSize-1;
    while(left<right){
        int temp = s[left];
        s[left] = s[right];
        s[right]=temp;
        left++;
        right--;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-string/)