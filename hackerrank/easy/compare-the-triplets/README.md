# Compare the Triplets

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Alice and Bob each created one problem for HackerRank. A reviewer rates the two challenges, awarding points on a scale from <em>1</em> to <em>100</em> for three categories: <em>problem clarity</em>, <em>originality</em>, and <em>difficulty</em>. 
  
The rating for Alice's challenge is the triplet <em>a = (a[0], a[1], a[2])</em>, and the rating for Bob's challenge is the triplet <em>b = (b[0], b[1], b[2])</em>.
  
The task is to calculate their comparison points by comparing each category:    
   
<ul>
<li> If <em>a[i] > b[i]</em>, then Alice is awarded <em>1</em> point. </li>
<li> If <em>a[i] &lt; b[i]</em>, then Bob is awarded <em>1</em> point. </li>
<li> If <em>a[i] = b[i]</em>, then neither person receives a point.</li>
</ul>
 
  
<strong>Example</strong>   
  
<em>a = [1, 2, 3]</em>  
<em>b = [3, 2, 1]</em>  
<br/ >  
<ul>
<li>For elements *0*, Bob is awarded a point because <em>a[0] &lt; b[0]</em>. </li> 
<li>For the equal elements <em>a[1]</em> and <em>b[1]</em>, no points are earned. </li> 
<li>Finally, for elements <em>2</em>, <em>a[2] > b[2]</em> so Alice receives a point. </li> 
</ul>
  
The return array is <em>[1, 1]</em> with Alice's score first and Bob's second.  
  
<strong>Function Description</strong>  
  
Complete the function <em>compareTriplets</em> with the following parameter(s):  
  

- <em>int a[3]</em>: Alice's challenge rating  
- <em>int b[3]</em>: Bob's challenge rating   

  
<strong>Returns</strong>  
  
- <em>int[2]</em>: the first element is Alice's score and the second is Bob's score

**Input Format**

The first line contains <em>3</em> space-separated integers, <em>a[0]</em>, <em>a[1]</em>, and <em>a[2]</em>, the respective values in triplet <em>a</em>.		
The second line contains <em>3</em> space-separated integers, <em>b[0]</em>, <em>b[1]</em>, and <em>b[2]</em>, the respective values in triplet <em>b</em>.

**Constraints**

   
<ul>
<li> <em>1 &le; a[i] &le; 100</em></li>
<li> <em>1 &le; b[i] &le; 100</em></li>
</ul>

**Output Format**

## Solution

**Language:** C  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-03T06:05:07.810Z  

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
 * Complete the 'compareTriplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    int* result = malloc(2 * sizeof(int));

    int alice = 0;
    int bob = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            alice++;
        }
        else if (a[i] < b[i]) {
            bob++;
        }
    }

    result[0] = alice;
    result[1] = bob;

    *result_count = 2;

    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** a_temp = split_string(rtrim(readline()));

    int* a = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++) {
        int a_item = parse_int(*(a_temp + i));

        *(a + i) = a_item;
    }

    char** b_temp = split_string(rtrim(readline()));

    int* b = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++) {
        int b_item = parse_int(*(b_temp + i));

        *(b + i) = b_item;
    }

    int result_count;
    int* result = compareTriplets(3, a, 3, b, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, " ");
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
        char* line = fgets(cursor, alloc_length - data_length, stdin);

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

    if (data_length > 0 && data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    }
    else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        }
        else {
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
        splits = realloc(splits, sizeof(char*) * ++spaces);

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

[View on HackerRank](https://www.hackerrank.com/challenges/compare-the-triplets/problem)