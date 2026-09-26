#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b;
    float x, y;

    // Read two integers
    scanf("%d %d", &a, &b);

    // Read two floating-point numbers
    scanf("%f %f", &x, &y);

    // Sum and difference of integers
    printf("%d %d\n", a + b, a - b);

    // Sum and difference of floats
    printf("%.1f %.1f\n", x + y, x - y);

    return 0;
}
