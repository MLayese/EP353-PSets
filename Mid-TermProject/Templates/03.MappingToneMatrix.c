#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Note {
  int pitch;
  int velocity;
  char *duration;
} Note;

void append2File(Note note);
int getSize(char *fileName);
void readSeries(int *series, int size);

int main(){
  system("rm -f notes.txt"); // delete notes.txt if it exists
  
  // TODO: create a mapping table (array) for pitch, velocity, and duration
  // Must use the Note struct in this process.

  int rowSize = sqrt(getSize("matrix.txt"));
  Note tone[rowSize];

  // TODO: Check to make sure that the table size is at least 
  // the size of row in the original matrix.
  
  // Count the number of sequence in the series.txt file
  int numSeries = getSize("series.txt");
  if(numSeries == 0){
    printf("The series.txt does not exist or the content is empty...\n");
    return 1;
  }

  // TODO: allocate enough memory space to hold all tone values in series.txt
  int *series = malloc(sizeof(int)*numSeries);
  if (series == NULL){
    printf("The series array does not have anything...\n");
    return 0;
  }

  // Read tone values and assign to the series array
  readSeries(series, numSeries);

  int *veloc = malloc(sizeof(int));
  char *duration = "8n";

  printf("MIDI Velocity for your tone row: ");
  scanf("%d", veloc);

  // TODO: Map the series aray to the mapping table
  for (int i = 0; i < row; i++)
  {
    tone[i].pitch = series[i];
    tone[i].duration = duration;
    tone[i].velocity = *veloc;
    append2File(tone[i]);
  }

  int instr;

  printf("Prompt the Tone Row to an instrument: \n1: Melody\n2: Bass\n3: Drums\n");
  scanf("%i", &instr);
    switch(instr)
    {
      case 1://Melody
      {
        int result = rename("notes.txt", "melody.txt");
        printf("\ec");
        break;
      }
      case 2://Bass
      {
        int result = rename("notes.txt", "bass.txt");
        printf("\ec");
        break;
      }
      case 3://Drums
      {
        int result = rename("notes.txt", "drum.txt");
        printf("\ec");
        break;
      }
    }
  
  // TODO: free memory space
  free(series);
  printf("Memory successfully freed.\n");
  return 0;
}

//-------------------- Utility Functions --------------------
int getSize(char *fileName){
  FILE *file;
  file = fopen(fileName, "r");

  if(file == NULL){
    printf("%s could not be opened...\n", fileName);
    return 0;
  }

  int value, count = 0;
  while(fscanf(file, "%d", &value) != EOF) count++;

  fclose(file);

  return count;
}

void readSeries(int *series, int size){
  FILE *file;
  file = fopen("series.txt", "r");

  if(file == NULL){
    printf("series.txt could not be opened...\n");
    return;
  }

  for (int i = 0; i < size * size; i++) {
    fscanf(file, "%d", &series[i]);
  }

  fclose(file);
}

void append2File(Note note){
  static unsigned int count = 0;
  FILE *file;
  file = fopen("notes.txt", "a");
  fprintf(file, "%d, %d %d %s;\n", count++, note.pitch, note.velocity, note.duration);
  fclose(file);
}