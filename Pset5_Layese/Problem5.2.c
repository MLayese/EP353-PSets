#include<stdio.h>

void setArray(int *numbers, int value, int size)
{    
    scanf("%d", &value);
    // Declares Array
    int i;
    for (i = 0; i < size ; i++)
    {
        numbers[i] = value;
    }
  
    // Prints array
    printf("The 'numbers' array is now initialized to %i: \n", value);
    for (i = 0; i < size ; i++)
    {
        printf("%d ", numbers[i]);
    }   
}
int main(void)
{
    int size = 8;
    int value;    
    int numbers[size];

    setArray(&numbers[size], value, size);
  
    return 0;
}  

/*int main(void)
{
    int size = 8;
    int value;
    scanf("%d", &value);
  
    // array declaration
    int numbers[size];
    int i;
  
    // initializing array elements
    for (i = 0; i < size ; i++){
        numbers[i] = value;
    }
  
     // print array
     printf("The 'numbers' array is now initialized to %i: \n", value);
     for (i = 0; i < size ; i++){
         printf("%d ", numbers[i]);
    }   
  
    return 0;
}*/