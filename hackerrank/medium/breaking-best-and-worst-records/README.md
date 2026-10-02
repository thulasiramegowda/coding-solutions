# Between Two Sets

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Maria plays college basketball and wants to go pro.  Each season she maintains a record of her play.  She tabulates the number of times she breaks her season record for *most points* and *least points* in a game.  Points scored in the first game establish her record for the season, and she begins counting from there.

**Example**  
$scores = [12, 24, 10, 24]$   

Scores are in the same order as the games played.  She tabulates her results as follows:

<pre>
									 Count
    Game  Score  Minimum  Maximum   Min Max
     0      12     12       12       0   0
     1      24     12       24       0   1
     2      10     10       24       1   1
     3      24     10       24       1   1
</pre>

Given the scores for a season, determine the number of times Maria breaks her records for *most* and *least* points scored during the season.

**Function Description**  

Complete the *breakingRecords* function in the editor below. 

breakingRecords has the following parameter(s):  

- *int scores[n]:* points scored per game   

**Returns**   

- *int[2]:* An array with the numbers of times she broke her records. Index $0$ is for breaking *most points* records, and index $1$ is for breaking *least points* records.  

**Input Format**

The first line contains an integer $n$, the number of games.  		
The second line contains $n$ space-separated integers describing the respective values of $score_0, score_1, \ldots, score_{n-1}$.

**Constraints**

* $1 \le n \le 1000$
* $0 \le scores[i] \le 10^8$

**Output Format**

## Solution

**Language:** C  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-02T16:42:54.480Z  

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
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int getTotalX(int a_count, int* a, int b_count, int* b) {

    int count = 0;

    /*
     * Check every possible number.
     *
     * The answer must:
     * 1. Be divisible by every number in a.
     * 2. Divide every number in b.
     */

    for (int x = 1; x <= 100; x++) {

        bool valid = true;

        // Check if x is a multiple of every element in a
        for (int i = 0; i < a_count; i++) {

            if (x % a[i] != 0) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            continue;
        }

        // Check if x is a factor of every element in b
        for (int i = 0; i < b_count; i++) {

            if (b[i] % x != 0) {
                valid = false;
                break;
            }
        }

        if (valid) {
            count++;
        }
    }

    return count;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input =
        split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int m = parse_int(*(first_multiple_input + 1));

    char** arr_temp =
        split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {

        int arr_item =
            parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    char** brr_temp =
        split_string(rtrim(readline()));

    int* brr = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {

        int brr_item =
            parse_int(*(brr_temp + i));

        *(brr + i) = brr_item;
    }

    int total =
        getTotalX(n, arr, m, brr);

    fprintf(fptr, "%d\n", total);

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

[View on HackerRank](https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem)