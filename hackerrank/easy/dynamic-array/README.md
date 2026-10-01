# Dynamic Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

- Declare a 2-dimensional array, $arr$, with $n$ empty arrays, all zero-indexed.
- Declare an integer, $lastAnswer$, and initialize it to 0.

You need to process two types of queries:

1. Query: $1\ x\ y$
   - Compute $idx = (x \oplus lastAnswer) % n$.
   - Append the integer $y$ to $arr[idx]$.

2. Query: $2\ x\ y$
   - Compute $idx = (x \oplus lastAnswer) % n$.
   - Set $lastAnswer = arr[idx][y \% size(arr[idx])]$.
   - Store the new value of $lastAnswer$ in an answers array.

**Notes:**  
- $\oplus$ is the *bitwise XOR* operation, which corresponds to the `^` operator in most languages. Learn more about it on [Wikipedia](https://en.wikipedia.org/wiki/Exclusive_or).  
- $\%$ is the modulo operator.   
- Finally, $size(arr[idx])$ is the number of elements in $arr[idx]$.  

**Function Description**  

Complete the $dynamicArray$ function with the following parameters:  
- $int\ n$: the number of empty arrays to initialize in $arr$  
- $int\ queries[q][3]$: 2-D array of integers

**Returns**  

- $int[]$:  the results of each type 2 query in the order they are presented  

**Input Format**

The first line contains two space-separated integers, $n$, the size of $arr$ to create, and $q$, the number of queries, respectively.		
Each of the $q$ subsequent lines contains a query string, $queries[i]$.

**Constraints**

- $1 \leq  n, q \leq  10^5$
- $0 \leq x, y \leq 10^9$
- It is guaranteed that query type $2$ will never query an empty array or index.

**Output Format**

## Solution

**Language:** C  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-01T07:21:12.655Z  

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
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

int* dynamicArray(int n, int queries_rows, int queries_columns,
                  int** queries, int* result_count) {

    // Create n sequences
    int** seq = malloc(n * sizeof(int*));
    int* size = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        seq[i] = NULL;
        size[i] = 0;
    }

    int lastAnswer = 0;

    // Maximum possible number of answers is queries_rows
    int* result = malloc(queries_rows * sizeof(int));
    *result_count = 0;

    for (int i = 0; i < queries_rows; i++) {

        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int index = (x ^ lastAnswer) % n;

        if (type == 1) {

            // Add y to sequence[index]
            size[index]++;

            seq[index] = realloc(
                seq[index],
                size[index] * sizeof(int)
            );

            seq[index][size[index] - 1] = y;

        }
        else if (type == 2) {

            // Find the required element
            int position = y % size[index];

            lastAnswer = seq[index][position];

            // Store lastAnswer
            result[*result_count] = lastAnswer;
            (*result_count)++;
        }
    }

    // Free allocated sequence memory
    for (int i = 0; i < n; i++) {
        free(seq[i]);
    }

    free(seq);
    free(size);

    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));
    int q = parse_int(*(first_multiple_input + 1));

    int** queries = malloc(q * sizeof(int*));

    for (int i = 0; i < q; i++) {
        *(queries + i) = malloc(3 * sizeof(int));

        char** queries_item_temp =
            split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            int queries_item =
                parse_int(*(queries_item_temp + j));

            *(*(queries + i) + j) = queries_item;
        }
    }

    int result_count;

    int* result = dynamicArray(
        n,
        q,
        3,
        queries,
        &result_count
    );

    for (int i = 0; i < result_count; i++) {

        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;

        char* line =
            fgets(cursor, alloc_length - data_length, stdin);

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

char* ltrim(char* str) {

    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
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

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {

    char** splits = NULL;

    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {

        splits = realloc(
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

    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/dynamic-array/problem)