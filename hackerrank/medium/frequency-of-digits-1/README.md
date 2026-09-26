# Pointers in C

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
**Submitted:** 2026-09-26T10:20:43.933Z  

```c
#include <stdio.h>

void update(int *a, int *b)
{
    int sum;
    int difference;

    sum = *a + *b;
    difference = *a - *b;

    if (difference < 0)
    {
        difference = -difference;
    }

    *a = sum;
    *b = difference;
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);

    update(pa, pb);

    printf("%d\n%d", a, b);

    return 0;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/frequency-of-digits-1/problem)