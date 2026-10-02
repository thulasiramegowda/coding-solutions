# Apple and Orange

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Sam's house has an apple tree and an orange tree that yield an abundance of fruit. Using the information given below, determine the number of apples and oranges that land on Sam's house.  

In the diagram below: 

- The red region denotes the house, where $s$ is the start point, and $t$ is the endpoint. The apple tree is to the left of the house, and the orange tree is to its right. 
- Assume the trees are located on a single point, where the apple tree is at point $a$, and the orange tree is at point $b$.
- When a fruit falls from its tree, it lands $d$ units of distance from its tree of origin along the $x$-axis. *A negative value of $d$ means the fruit fell $d$ units to the tree's left, and a positive value of $d$ means it falls $d$ units to the tree's right. *

![Apple and orange(2).png](https://s3.amazonaws.com/hr-challenge-images/25220/1474218925-f2a791d52c-Appleandorange2.png)

Given the value of $d$ for $m$ apples and $n$ oranges, determine how many apples and oranges will fall on Sam's house (i.e., in the inclusive range $[s, t]$)?

For example, Sam's house is between $s = 7$ and $t = 10$.  The apple tree is located at $a = 4$ and the orange at $b = 12$.  There are $m = 3$ apples and $n = 3$ oranges.  Apples are thrown $apples = [2, 3, -4]$ units distance from $a$, and $oranges = [3, -2, -4]$ units distance.  Adding each apple distance to the position of the tree, they land at $[4 + 2, 4 + 3, 4 + -4] = [6, 7, 0]$.  Oranges land at $[12 + 3, 12 + -2, 12 + -4] = [15, 10, 8]$.  One apple and two oranges land in the inclusive range $7-10$ so we print 

    1
    2

**Function Description**  

Complete the *countApplesAndOranges* function in the editor below.  It should print the number of apples and oranges that land on Sam's house, each on a separate line.  

countApplesAndOranges has the following parameter(s):  

- *s*: integer, starting point of Sam's house location.       
- *t*: integer, ending location of Sam's house location.     
- *a*: integer, location of the Apple tree.      
- *b*: integer, location of the Orange tree.         
- *apples*: integer array, distances at which each apple falls from the tree.      
- *oranges*: integer array, distances at which each orange falls from the tree.  

**Input Format**

The first line contains two space-separated integers denoting the respective values of $s$ and $t$.		
The second line contains two space-separated integers denoting the respective values of $a$ and $b$.		
The third line contains two space-separated integers denoting the respective values of $m$ and $n$.			
The fourth line contains $m$ space-separated integers denoting the respective distances that each apple falls from point $a$.		
The fifth line contains $n$ space-separated integers denoting the respective distances that each orange falls from point $b$.

**Constraints**

* $1 \le s, t, a, b, m, n \le 10^{5} $
* $-10^{5} \le d \le 10^{5} $
* $ a < s < t < b $

**Output Format**

Print two integers on two different lines:

1. The first integer:  the number of apples that fall on Sam's house.
2. The second integer:  the number of oranges that fall on Sam's house.

## Solution

**Language:** C  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-02T16:38:04.147Z  

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
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER s
 *  2. INTEGER t
 *  3. INTEGER a
 *  4. INTEGER b
 *  5. INTEGER_ARRAY apples
 *  6. INTEGER_ARRAY oranges
 */

void countApplesAndOranges(
    int s,
    int t,
    int a,
    int b,
    int apples_count,
    int* apples,
    int oranges_count,
    int* oranges
) {

    int apple_count = 0;
    int orange_count = 0;

    // Check apples
    for (int i = 0; i < apples_count; i++) {

        int position = a + apples[i];

        if (position >= s && position <= t) {
            apple_count++;
        }
    }

    // Check oranges
    for (int i = 0; i < oranges_count; i++) {

        int position = b + oranges[i];

        if (position >= s && position <= t) {
            orange_count++;
        }
    }

    printf("%d\n", apple_count);
    printf("%d\n", orange_count);
}

int main()
{
    char** first_multiple_input =
        split_string(rtrim(readline()));

    int s = parse_int(*(first_multiple_input + 0));

    int t = parse_int(*(first_multiple_input + 1));

    char** second_multiple_input =
        split_string(rtrim(readline()));

    int a = parse_int(*(second_multiple_input + 0));

    int b = parse_int(*(second_multiple_input + 1));

    char** third_multiple_input =
        split_string(rtrim(readline()));

    int m = parse_int(*(third_multiple_input + 0));

    int n = parse_int(*(third_multiple_input + 1));

    char** apples_temp =
        split_string(rtrim(readline()));

    int* apples = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {

        int apples_item =
            parse_int(*(apples_temp + i));

        *(apples + i) = apples_item;
    }

    char** oranges_temp =
        split_string(rtrim(readline()));

    int* oranges = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {

        int oranges_item =
            parse_int(*(oranges_temp + i));

        *(oranges + i) = oranges_item;
    }

    countApplesAndOranges(
        s,
        t,
        a,
        b,
        m,
        apples,
        n,
        oranges
    );

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

[View on HackerRank](https://www.hackerrank.com/challenges/apple-and-orange/problem)