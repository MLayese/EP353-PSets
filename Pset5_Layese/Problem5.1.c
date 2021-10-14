#include <stdio.h>
#include <string.h>

void countCharacter(char string[], char *p, int Count)
{
    p=string;
    while(*p!='\0')
    {
        Count++;
        p++;
    }
    printf("The string, \"%s\",  has %d characters", string, Count); // Initially had this in the main function but it kept outputting "0" for %d
}

int main()
{
    char string[100];
    char *p;
    int Count = 0;

    printf("Enter any string (hit space once before entering):  \n");
    scanf("%c", string);
    fgets(string, 100, stdin);
    strtok(string, "\n"); //added this to get rid of the newline input from fgets
    
    countCharacter(string, p, Count);

    return 0;
}