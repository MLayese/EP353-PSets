#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

typedef enum Mode {
  prime = 1, invert, retrograde, retrogradeInvert
} Mode;

unsigned int randomInt(int min, int max);
int getRowSize();
void readMatrix(int *matrix, int rowSize);
void append2File(int value);

// Functions to implement
void randomWalk(int *value, int maxStep, int size);
int getPrime(int *matrix, int rowSize, int row, int column);
int getInvert(int *matrix, int rowSize, int row, int column);
int getRetrograde(int *matrix, int rowSize, int row, int column);
int getRetrogradeInvert(int *matrix, int rowSize, int row, int column);

int main(){

  // Remove the series.txt file if it exist
  system("rm -f series.txt");

  int *matrix = NULL, rowSize = 0;

  rowSize = getRowSize(); // Get the row size from the matrix.txt file.

  if(rowSize == 0){ // Check if the row size is not 0.
    printf("the matrix.txt file does not exist or nothing is in the file...\n");
    return 1;
  }

  // TODO: allocate the memory space to hold all values in the matrix

  matrix = (int*)calloc(rowSize, sizeof(int));

  if(matrix == NULL){ // Check if matrix is not a null pointer
    printf("Matrix is empty...\n");
    return 1;
  }  

  // Read values from the matrix.txt file and assign them to the matrix
  readMatrix(matrix, rowSize);

  printf("Let's create a series of numbers based on your tone matrix.\n");
  sleep(1);
  // TODO: Interactively ask the user to generate tone series
  // Make sure to use all the functions you are supposed to implement
  int Form;
  int i = 0;
  int r0w;
  int c0lumn;
  int k = 0;
  int *value = malloc(sizeof(int));

  printf("1: Prime \n2: Invert \n3: Retrograde \n4: Retro Invert \n0: Exit\n");
  scanf("%i",&Form);
  
  while (i == 0)
  {
    if(Form == 0)
    {
      printf("So long...\n");
      exit(0);
    }
    if(Form > 4)
    {
      printf("Please input a number 0-4: ");
      scanf("%i",&Form);
    }
    if(Form > 4)
    {
      printf("Failure to comply will exit the program \nPlease input a number 0-4: ");
      scanf("%i",&Form);
    }
    else if (Form > 4)
    {
      exit(0);
    }
    else 
    {
      i++;
    }
  }
  switch(Form)
  {
    case 1: //Prime
    {
      printf("Prime\nChoose a row between 0 - %i to play: ", rowSize-1);
      scanf("%i", &r0w);

        while(k < 1)
        {
          if(r0w > rowSize-1)
          {
            printf("Out of bounds, try again...");
            scanf("%i", &r0w);
          }
          else if (r0w == 0)
          {
            exit(0);
          }
          else if (r0w < 0)
          {
            printf("Random Walk...");
            int maxStep = abs(r0w);
            randomWalk(value, maxStep, rowSize);
            r0w = *value;
            getPrime(matrix, rowSize, r0w, c0lumn);
          }
          else
          {
            getPrime(matrix, rowSize, r0w, c0lumn);
            k++;
          }
        }
      break;
    }
    case 2: //Invert
    {
      printf("Inversion\nChoose a row between 0 - %i to play: ", rowSize-1);
      scanf("%i", &c0lumn);

        while(k < 1)
        {
          if(c0lumn > rowSize-1)
          {
            printf("Out of bounds, try again...");
            scanf("%i", &c0lumn);
          }
          else if (c0lumn == 0)
          {
            exit(0);
          }
          else if (c0lumn < 0)
          {
            printf("Random Walk...");
            int maxStep = abs(r0w);
            randomWalk(value, maxStep, rowSize);
            c0lumn = *value;
            getInvert(matrix, rowSize, r0w, c0lumn);
          }
          else
          {
            getInvert(matrix, rowSize, r0w, c0lumn);
            k++;
          }
        }
      break;
    }
    case 3: //Retro
    {
      printf("Retrograde\nChoose a row between 0 - %i to play: ", rowSize-1);
      scanf("%i", &r0w);

        while(k < 1)
        {
          if(r0w > rowSize-1)
          {
            printf("Out of bounds, try again...");
            scanf("%i", &r0w);
          }
          else if (r0w == 0)
          {
            exit(0);
          }
          else if (r0w < 0)
          {
            printf("Random Walk...");
            int maxStep = abs(r0w);
            randomWalk(value, maxStep, rowSize);
            r0w = *value;
            getRetrograde(matrix, rowSize, r0w, c0lumn);
          }
          else
          {
            getRetrograde(matrix, rowSize, r0w, c0lumn);
            k++;
          }
        }
      break;
    }
    case 4: //Retro Invert
    {
      printf("Retro Invert\nChoose a row between 0 - %i to play: ", rowSize-1);
      scanf("%i", &c0lumn);

        while(k < 1)
        {
          if(c0lumn > rowSize-1)
          {
            printf("Out of bounds, try again...");
            scanf("%i", &c0lumn);
          }
          else if (c0lumn == 0)
          {
            exit(0);
          }
          else if (c0lumn < 0)
          {
            printf("Random Walk...");
            int maxStep = abs(r0w);
            randomWalk(value, maxStep, rowSize);
            c0lumn = *value;
            getRetrogradeInvert(matrix, rowSize, r0w, c0lumn);
          }
          else
          {
            getRetrogradeInvert(matrix, rowSize, r0w, c0lumn);
            k++;
          }
        }
      break;
    }
  }
  
  // TODO: Free the memory space 
  free(matrix);
  printf("Memory successfully freed.\n");
  return 0;
}


void randomWalk(int *value, int maxStep, int size){
  *value = randomInt(1, maxStep);
}

int getPrime(int *matrix, int rowSize, int row, int column){
  int value;
  int rowIndex = row * rowSize;
  int columnIndex = 0;

  for(columnIndex = 0; columnIndex < rowSize; columnIndex++)
  {
  value = matrix[rowIndex+columnIndex];
  append2File(value);
  }
  return -1;
}

int getInvert(int *matrix, int rowSize, int row, int column){
  int value;
  int rowIndex;

  for(rowIndex = 0; rowIndex < rowSize; rowIndex++)
  {
    int columnIndex = (column + (rowIndex * rowSize));
    value = matrix[columnIndex];
    append2File(value);
  }
  return -1;
}

int getRetrograde(int *matrix, int rowSize, int row, int column){
  int value;
  int columnIndex;

  for(columnIndex = rowSize-1; columnIndex >= 0; columnIndex--)
  {
    value = matrix[columnIndex + (row * rowSize)];
    append2File(value);
  }
  return -1;
}

int getRetrogradeInvert(int *matrix, int rowSize, int row, int column){
  int value;
  int rowIndex;

  for(rowIndex = rowSize-1; rowIndex >= 0; rowIndex--)
  {
    int columnIndex = (column + (rowIndex * rowSize));
    value = matrix[columnIndex];
    append2File(value);
  }
  return -1;
}

//-------------------- Utility Functions --------------------
void append2File(int value){
  FILE *file;
  file = fopen("series.txt", "a");
  fprintf(file, "%d ", value);
  fclose(file);
}

int getRowSize(){
  FILE *file;
  file = fopen("matrix.txt", "r");

  if(file == NULL){
    printf("matrix.txt could not be opened...\n");
    return 0;
  }

  int value, count = 0;
  while(fscanf(file, "%d", &value) != EOF) count++;

  fclose(file);

  return sqrt(count);
}

void readMatrix(int *matrix, int rowSize){
  FILE *file;
  file = fopen("matrix.txt", "r");

  if(file == NULL){
    printf("matrix.txt could not be opened...\n");
    return;
  }

  for (int i = 0; i < rowSize * rowSize; i++) {
    fscanf(file, "%d", &matrix[i]);
  }

  fclose(file);
}

unsigned int randomInt(int min, int max){
  unsigned int randval;
  FILE *f;

  f = fopen("/dev/random", "r");
  fread(&randval, sizeof(randval), 1, f);
  fclose(f);

  return (randval % (max - min)) + min;
}