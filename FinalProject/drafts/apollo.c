#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct 
{

    char *name;
    float freq;

} Note;

int main()
{
    FILE *ogFile = fopen("/Users/anthonylayese/Desktop/GitHub/EP-353/EP-353_PSets/FinalProject/BillEvans.beatmap.txt", "r");
    FILE *newFile = fopen("/Users/anthonylayese/Desktop/GitHub/EP-353/EP-353_PSets/FinalProject/BillEvans.EDIT.txt", "w");

    int NoteCount;
    fscanf(ogFile, "%i" ,&NoteCount);

    Note *passingNotes = malloc(sizeof(Note) * NoteCount);

    int passingCount = 0;
    for (int i = 0; i < NoteCount; i++)
    {
        int nameLen;

        fscanf(ogFile, "%i", &nameLen);

        char *name = malloc(sizeof(char) * (nameLen));
        name[nameLen] = '\0';
        float freq;

        fscanf(ogFile, "%s %f", name + 2, &freq);

        if (freq >=65.0)
        {
            passingNotes[passingCount].freq = freq; 
               
            passingCount++; //increment passingCount
        }
    }

    for (int i = 0; i < passingCount; i++)
    {
        fprintf(newFile, "play %.2f\nsleep 0.5\n", passingNotes[i].freq + 1);
    }

    fclose(ogFile);
    fclose(newFile);
    return 0;
}
