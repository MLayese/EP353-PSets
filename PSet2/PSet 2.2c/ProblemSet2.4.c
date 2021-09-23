#include <stdio.h>
#include <math.h>

int main (int argc, const char * argv[]){

    char loudness;
    printf("Enter 0 - 127: ");   //Input a random number as char
    scanf("%s", &loudness);
    double loud = (-loudness);   //Converted my char variable into a double called 'loud'
    float amp = pow(10, loud/20);  

    printf("The loudness of %fdB is %f.\n",  
        loud, amp);                 
		  
    return 0;
}