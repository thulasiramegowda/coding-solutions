# Time Conversion

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Greg wants to build a string, $S$ of length $N$. Starting with an empty string, he can perform $2$ operations:<br>
	
1. Add a character to the end of $S$ for $A$ dollars.<br>
2. Copy any substring of $S$, and then add it to the end of $S$ for $B$ dollars.<br>

Calculate minimum amount of money Greg needs to build $S$.<br>

**Input Format**

The first line contains number of testcases $T$.		

The $2 \times T$ subsequent lines each describe a test case over $2$ lines:		
The first contains $3$ space-separated integers, $N$, $A$ , and $B$, respectively.	
The second contains $S$ (the string Greg wishes to build).

**Constraints**

* $1 \le T \le 3$
* $1 \le N \le 3 \times 10^4$
* $1 \le A,B \le 10000$
* $S$ is composed of lowercase letters only.

**Constraints**

 

**Output Format**

On a single line for each test case, print the minimum cost (as an integer) to build $S$.

## Solution

**Language:** C  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-02T16:30:58.052Z  

```c
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

char* timeConversion(char* s) {

    static char result[9];

    int hour;

    // Convert first two characters into integer
    hour = (s[0] - '0') * 10 + (s[1] - '0');

    if (s[8] == 'A') {

        // 12 AM becomes 00
        if (hour == 12) {
            hour = 0;
        }

    } else {

        // For PM, add 12 except for 12 PM
        if (hour != 12) {
            hour = hour + 12;
        }
    }

    sprintf(result, "%02d:%c%c:%c%c",
            hour,
            s[3], s[4],
            s[6], s[7]);

    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/build-a-string/problem)