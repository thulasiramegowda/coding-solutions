# Palindrome Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer `x`, return `true` if `x` is a  **palindrome**, and `false` otherwise.

 

 **Example 1:** 

```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

```

 **Example 2:** 

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

```

 **Example 3:** 

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

```

 

 **Constraints:** 

- -231 <= x <= 231 - 1

 

 **Follow up:**  Could you solve it without converting the integer to a string?

## Solution

**Language:** C  
**Runtime:** 4 ms (beats 25.18%)  
**Memory:** 8.8 MB (beats 89.80%)  
**Submitted:** 2026-10-05T11:55:03.101Z  

```c
bool isPalindrome(int x) {
 //negitive numbers are not palindrome
 if(x<0)
 return false;
 int original=x;
 long reversed=0;
 while(x>0){
    //digit is in integer so it will consider only first number 
    int digit= x % 10;
    reversed = reversed * 10 + digit;
    x=x/10;
 } 
 if(original==reversed)
 return true;
 else
 return false;  
}
```

---

[View on LeetCode](https://leetcode.com/problems/palindrome-number/)