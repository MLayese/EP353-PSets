#include <stdio.h>

int main()
{

    int i;
    for (int i = 11; i >= 0; i--)
    { 
         //starting from i= 11 and will subtract 1 (i--) every loop until i reaches 0
            switch (i) 
            {
                //Corresponds with alpha-numerical values
                case 11: printf("C ");
                    break;
                case 10: printf("Db ");
                    break;
                case 9: printf("D ");
                    break;
                case 8: printf("Eb ");
                    break;
                case 7: printf("E ");
                    break;
                case 6: printf("F ");
                    break;
                case 5: printf("Gb ");
                    break;              
                case 4: printf("G ");
                    break;
                case 3: printf("Ab ");
                    break;
                case 2: printf("A ");
                    break;
                case 1: printf("Bb ");
                    break;
                case 0: printf("B ");
                    break;

            }
    }   
    
    return 0;
}