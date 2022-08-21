//A program that encripts any sentence using the caeser cipher
#include <stdio.h>
#include <string.h>
#define MAX 50
int main ()
{
    char word[MAX], wordaux[MAX], c;
    int i, shift, n, lenght;
    printf ("Put your chosen word (in lowercase): ");
    fgets (wordaux, MAX, stdin);
    printf ("Put your number of shift: ");
    scanf("%d", &shift);
    lenght = strlen(wordaux) - 1; //size of the string without the '\0'
    printf("The new word is: ");
    for (i = 0; i < lenght; i++)
    {
        word[i] = wordaux[i] + shift;
        if (word[i] > 'z')
        {
            n = word[i] - 123;
            word[i] = 'a' + n;
        }
        if (wordaux[i] < 'a' || wordaux[i] > 'z')
        {
            word[i] = wordaux[i];
        }
        printf("%c", word[i]);
    }
    return 0;
}
