#include <stdio.h>
#include <math.h>

int main (int argc, const char * argv[]){

    /*char loudness;
    printf("Enter 0 - 127: ");   //Input a random number as char
    scanf("%s", &loudness);
    double loud = (-loudness);   //Converted my char variable into a double called 'loud'
    float amp = pow(10, loud/20);  */

    // Couldn't get the above to work properly on time so I opted for a more dry program. Oh well 

    char loudness = -70;
    double loud = (-loudness);   //Converted my char variable into a double called 'loud'
    float amp = (float) pow(10, loudness/20);  

    printf("The loudness of %fdB is %f.\n",  
        loud, amp);                 
		  
    return 0;
}