#include <stdio.h>
 
// Function [dog] to print the array
// Holds an undefined int numbers[] for the array 
void dog(int numbers[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("The value of arr at index [%d] is %d \n", i, numbers[i]);
    }
}
 
// Function [god] to reverse the array
// Gets the inverse of int [numbers]
void god(int numbers[], int n)
{
    int backwards[n];
 
    for (int i = 0; i < n; i++) {
        backwards[n - 1 - i] = numbers[i]; 
        // Gets all the integers out in reverse order
    }
 
    for (int i = 0; i < n; i++) {
        numbers[i] = backwards[i]; 
    }
}
 
int main(void)
{
    int numbers[] = { 5, 9, 1, 2, 4, 8, 3 };
    int n = sizeof(numbers)/sizeof(numbers[0]);
 
    god(numbers, n);
    dog(numbers, n);
 
    return 0;
}