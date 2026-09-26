# Dynamic Array in C

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Strings are usually ordered in lexicographical order. That means they are ordered by comparing their leftmost different characters. For example, $abc<abd$ because $c<d$. Also $z>yyy$ because $z>y$. If one string is an exact prefix of the other it is lexicographically smaller, e.g., $gh<ghij$.

Given an array of strings sorted in lexicographical order, print all of its permutations in strict lexicographical order.  If two permutations look the same, only print one of them.  See the 'note' below for an example.

Complete the function `next_permutation` which generates the permutations in the described order.  

For example, $s=[ab,bc,cd]$.  The six permutations in correct order are:
```
ab bc cd
ab cd bc
bc ab cd
bc cd ab
cd ab bc
cd bc ab
```

**Note:** There may be two or more of the same string as elements of $s$.  
For example, $s = [{ab,ab,bc}]$.  Only one instance of a permutation where all elements match should be printed.  In other words, if $s[0]==s[1]$, then print either $s[0]\enspace s[1]$ or $s[1]\enspace s[0]$ but not both.  

A three element array having three distinct elements has six permutations as shown above.  In this case, there are three matching pairs of permutations where $s[0]={ ab}$ and $s[1]={ ab}$ are switched.  We only print the three visibly unique permutations:  
```
ab ab bc
ab bc ab
bc ab ab
```

**Input Format**

The first line of each test file contains a single integer $n$, the length of the string array $s$. 

Each of the next $n$ lines contains a string $s[i]$.

**Constraints**

+ $2 \leq n \leq 9$
+ $1 \leq |s[i]| \leq 10$
+ $s[i]$ contains only lowercase English letters.

**Output Format**

Print each permutation as a list of space-separated strings on a single line.

## Solution

**Language:** C  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-26T10:26:15.074Z  

```c

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    // Allocate memory for number of books on each shelf
    total_number_of_books = malloc(
        total_number_of_shelves * sizeof(int)
    );

    // Allocate memory for pages on each shelf
    total_number_of_pages = malloc(
        total_number_of_shelves * sizeof(int*)
    );

    // Initialize all shelves
    for (int i = 0; i < total_number_of_shelves; i++)
    {
        total_number_of_books[i] = 0;
        total_number_of_pages[i] = NULL;
    }

    while (total_number_of_queries--)
    {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            // Current number of books on shelf x
            int current_books = total_number_of_books[x];

            // Increase book count
            total_number_of_books[x]++;

            // Increase memory for one more book
            total_number_of_pages[x] = realloc(
                total_number_of_pages[x],
                total_number_of_books[x] * sizeof(int)
            );

            // Store pages of the new book
            total_number_of_pages[x][current_books] = y;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/permutations-of-strings/problem)