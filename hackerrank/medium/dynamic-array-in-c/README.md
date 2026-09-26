# Digit Frequency

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Snow Howler is the librarian at the central library of the city of HuskyLand.  He must handle requests which come in the following forms:  

*1 x y* : Insert a book with $y$ pages at the end of the $x^{th}$ shelf.  

*2 x y* : Print the number of pages in the $y^{th}$ book on the $x^{th}$ shelf.     

*3 x* : Print the number of books on the $x^{th}$ shelf.  

Snow Howler has got an assistant, Oshie, provided by the Department of Education.  Although inexperienced, Oshie can handle all of the queries of types *2* and *3*.  

Help Snow Howler deal with all the queries of type *1*.  

Oshie has used two arrays:  

```c
int* total_number_of_books;
/*
 * This stores the total number of books on each shelf.
 */

int** total_number_of_pages;
/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
```

**Input Format**

The first line contains an integer $total\_number\_of\_shelves$, the number of shelves in the library.  
The second line contains an integer $total\_number\_of\_queries$, the number of requests.  
Each of the following $total\_number\_of\_queries$ lines contains a request in one of the three specified formats.  

**Constraints**

- $1 \le \enspace total\_number\_of\_shelves \enspace \le 10^5$  
- $1 \le \enspace total\_number\_of\_queries \enspace \le 10^5$  
- For each query of the second type, it is guaranteed that a book is present on the $x^{th}$ shelf at $y^{th}$ index.  
- $0 \le \enspace x \enspace < total\_number\_of\_shelves$  
- Both the shelves and the books are numbered starting from 0.
- Maximum number of books per shelf $\leq 1100$.

**Output Format**

Write the logic for the requests of type 1.  The logic for requests of types 2 and 3 are provided.

## Solution

**Language:** C  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-26T10:21:51.305Z  

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

[View on HackerRank](https://www.hackerrank.com/challenges/dynamic-array-in-c/problem)