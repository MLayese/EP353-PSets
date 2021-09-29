#include <stdio.h>

int main()

{

    int value, number;
    // Made 'value' int hold 'number' in the for loop
    printf("Enter a random integer: ");
        scanf("%d", &number); 

    printf("Odd integers from %d to 1: \n", number); 
        if (number%2==0)
        {
            number --;    
            //If value isn't odd just subtract 1 and start the for loop//
        }  
            for (value = number ; value >= 1; value -=2) 
            {
                printf("%i  ", value);
            }
    return 0;
}