#include <stdio.h>

//function [beatbox] that holds two integers
void beatbox(int bar, int value)
{
    for (bar = 1; bar <= value; bar++)
    if (bar%4!=0)
    
        printf("Boots N Cats N\n");

    else if (bar%4==0)
    {
        printf("Potato Cats!\n\n");
    }
    
}

int main()
{
    int bar, value;

    printf("How many bars? \n");
    scanf("%i", &value);

    beatbox(bar, value);
    return 0;
}