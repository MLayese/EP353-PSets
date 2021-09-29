#include <stdio.h>

int main()
//I copied and pasted syntax from the switch excercise we did in class "switch.c"
//Just in case you noticed that it looked familiar

{
    char note;
    int PitchClass;
    printf("Enter a note in the C Major Scale (uppercase only): ");
        scanf("%s", &note); 
    switch (note) 
    {
        case 'C':  // Switch held different int 'PitchClass' for every Case
        {
            int PitchClass = 0;
            printf("A note '%c' translates to %i in pitch class.", note, PitchClass);
            break;
        }
        case 'D':
        {
            int PitchClass = 2;
            printf("A note '%c' translates to %i in pitch class.\n", note, PitchClass);
            break;
        }
        case 'E':
        {
            int PitchClass = 4;
            printf("A note '%c' translates to %i in pitch class.\n", note, PitchClass);
            break;
        }
        case 'F':
        {
            int PitchClass = 5;
            printf("A note '%c' translates to %i in pitch class.\n", note, PitchClass);
            break;
        }   
        case 'G':
        {
            int PitchClass = 7;
            printf("A note '%c' translates to %i in pitch class.\n", note, PitchClass);
            break;
        }
        case 'A':
        {
            int PitchClass = 9;
            printf("A note '%c' translates to %i in pitch class.\n", note, PitchClass);
            break;
        }
        case 'B':
        {
            int PitchClass = 11;
            printf("A note '%c' translates to %i in pitch class.\n", note, PitchClass);
            break;
        }
    default:
        printf("Not is not in the C major scale!\n"); 
    }

    return 0;

}