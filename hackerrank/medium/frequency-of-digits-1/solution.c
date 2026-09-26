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
