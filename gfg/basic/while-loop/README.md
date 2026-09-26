# While Loop

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

Given a number  **x**, print the numbers from x to 0 in decreasing order in a single line.

 **Examples:** 

```
Input: x = 3
Output: 3 2 1 0
Explanation: Numbers in decreasing order from 3 are 3 2 1 0.
```

```
Input: x = 5
Output: 5 4 3 2 1 0
Explanation: Numbers in decreasing order from 5 are 5 4 3 2 1 0.
```

## Solution

**Language:** c(gcc5.4)  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-26T10:04:25.604Z  

```c(gcc5.4)
#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    // code here
    for(int i=x;i>=0;i--){
        printf("%d ",i);
    }
    
}

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/while-loop/1)