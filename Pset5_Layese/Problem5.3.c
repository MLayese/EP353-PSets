#include<stdio.h>

void copyString(char *str2, char *str1)
{
    while(*str1)
    {
        *str2 = *str1;        
        str1++;        
        str2++;
    }    
    *str2 = '\0';
}

int main()
{
    char str1[100];
    char str2[100];    

    printf("source string: \n"); 

    //Used this to get a new string input
    gets(str1); 
    copyString(str2, str1);    

    printf("Copied string is \"%s\" \n", str2);  

    return 0;
}