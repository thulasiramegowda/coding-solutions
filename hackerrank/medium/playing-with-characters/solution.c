#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char s[100];
    char sentence[100];

    // Take a character
    scanf("%c", &ch);

    // Remove the newline left by the previous input
    scanf("\n");

    // Take a string
    scanf("%s", s);

    // Remove the newline left by the string input
    scanf("\n");

    // Take a complete sentence
    scanf("%[^\n]%*c", sentence);

    // Print the character
    printf("%c\n", ch);

    // Print the string
    printf("%s\n", s);

    // Print the sentence
    printf("%s\n", sentence);

    return 0;
}
