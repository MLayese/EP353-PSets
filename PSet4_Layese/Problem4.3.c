#include <stdio.h>

void MIDI (int pitch, int index, char pitches[]) //function [MIDI] runs the array and holds all ints
{
    printf("MIDI pitch (-127 to 128) and index[0-8]: \n");
    scanf("%d %d",&pitch, &index); //Had the scan function get both the pitch and index variab;e

    for (int i = 7; i >= index; i--)
    {
        pitches[i] = pitches[i-1];
    }
    pitches[index] = pitch; 

    printf("The new pitches are: \n \t");
    for (int j = 0; j < 8; j++)
    {
        printf("%d ",pitches[j]);
    }
}
int main()
{
    char pitches[8] = {74, 68, 54, 28, 89, 51, 35};
    int pitch, index;
    MIDI(pitch, index, pitches);
    
    return 0;
}