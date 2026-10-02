# Number Line Jumps

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are choreographing a circus show with various animals. For one act, you are given two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity). 

- The first kangaroo starts at location $x1$ and moves at a rate of $v1$ meters per jump. 
- The second kangaroo starts at location $x2$ and moves at a rate of $v2$ meters per jump.

You have to figure out a way to get both kangaroos at the same location at the same time  as part of the show.  If it is possible, return `YES`, otherwise return `NO`.  

**Example**  
$x1 = 2$   
$v1 = 1$   
$x2 = 1$   
$v2 = 2$   

After one jump, they are both at $x = 3$, ($x1 + v1 = 2 + 1$, $x2 + v2 = 1 + 2$), so the answer is `YES`.

**Function Description**

Complete the function *kangaroo* in the editor below.    

kangaroo has the following parameter(s):  

- *int x1, int v1*: starting position and jump distance for kangaroo 1
- *int x2, int v2*: starting position and jump distance for kangaroo 2   

**Returns**   

- *string:* either `YES` or `NO`


**Input Format**

A single line of four space-separated integers denoting the respective values of $x1$, $v1$, $x2$, and $v2$.

**Constraints**

- $0 \le x1 < x2 \le 10000$  
- $1 \le v1 \le 10000$  
- $1 \le v2 \le 10000$  

**Output Format**

## Solution

**Language:** C  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-02T16:38:44.879Z  

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
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

char* kangaroo(int x1, int v1, int x2, int v2) {

    static char yes[] = "YES";
    static char no[] = "NO";

    /*
     * After n jumps:
     *
     * Kangaroo 1 = x1 + n*v1
     * Kangaroo 2 = x2 + n*v2
     *
     * They meet when:
     *
     * x1 + n*v1 = x2 + n*v2
     *
     * Therefore:
     *
     * n = (x2 - x1) / (v1 - v2)
     *
     * n must be a positive integer.
     */

    if (v1 == v2) {
        return no;
    }

    int distance = x2 - x1;
    int speedDifference = v1 - v2;

    /*
     * They must meet after a whole number of jumps.
     */
    if (distance % speedDifference == 0 &&
        distance / speedDifference >= 0) {

        return yes;
    }

    return no;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input =
        split_string(rtrim(readline()));

    int x1 = parse_int(*(first_multiple_input + 0));

    int v1 = parse_int(*(first_multiple_input + 1));

    int x2 = parse_int(*(first_multiple_input + 2));

    int v2 = parse_int(*(first_multiple_input + 3));

    char* result = kangaroo(x1, v1, x2, v2);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {

    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {

        char* cursor =
            data + data_length;

        char* line =
            fgets(
                cursor,
                alloc_length - data_length,
                stdin
            );

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 ||
            data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';
            break;
        }
    }

    if (data_length > 0 &&
        data[data_length - 1] == '\n') {

        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }

    } else {

        data = realloc(
            data,
            data_length + 1
        );

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {

    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' &&
           isspace(*str)) {

        str++;
    }

    return str;
}

char* rtrim(char* str) {

    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end =
        str + strlen(str) - 1;

    while (end >= str &&
           isspace(*end)) {

        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {

    char** splits = NULL;

    char* token =
        strtok(str, " ");

    int spaces = 0;

    while (token) {

        splits =
            realloc(
                splits,
                sizeof(char*) * ++spaces
            );

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {

    char* endptr;

    int value =
        strtol(str, &endptr, 10);

    if (endptr == str ||
        *endptr != '\0') {

        exit(EXIT_FAILURE);
    }

    return value;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/kangaroo/problem)