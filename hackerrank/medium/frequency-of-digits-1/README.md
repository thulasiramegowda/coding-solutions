# Digit Frequency

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string, $s$, consisting of alphabets and digits, find the frequency of each digit in the given string.

**Input Format**

The first line contains a string, $num$ which is the given number.

**Constraints**

$ 1 \le len(num) \le 1000$  
All the elements of num are made of english alphabets and digits.


**Output Format**

Print ten space-separated integers in a single line denoting the frequency of each digit from $0$ to $9$.

## Solution

**Language:** C  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-26T10:21:40.729Z  

```c
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char num[1000];
    int frequency[10] = {0};

    // Read the string
    scanf("%s", num);

    // Check every character
    for (int i = 0; num[i] != '\0'; i++)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            int digit = num[i] - '0';
            frequency[digit]++;
        }
    }

    // Print frequency of digits 0 to 9
    for (int i = 0; i < 10; i++)
    {
        printf("%d", frequency[i]);

        if (i != 9)
        {
            printf(" ");
        }
    }

    return 0;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/frequency-of-digits-1/problem)