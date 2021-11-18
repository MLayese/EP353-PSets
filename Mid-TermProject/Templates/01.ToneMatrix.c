#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>


void shuffle(int *array, size_t n);
unsigned int randomInt(int min, int max);
void saveMatrix(int *matrix, int rowSize);

// Functions to implement
void initFirstRow(int *matrix, int rowSize);
void generateMatrix(int *matrix, int rowSize);

int main(){
  
  // TODO: Ask the user to enter the size of tone row
  int rowSize;
  printf("Enter size of the tone row: \n");
  scanf("%d", &rowSize);
  
  // TODO: Allocate the memory space for the matrix using rowSize
  int *matrix = NULL;
  matrix = (int*)calloc(rowSize, sizeof(int));
  
  if(matrix == NULL)
    {
      printf("Memory allocation failed...\n");
      return 1;
    }

  // Initialize the first row (P0) in the matrix
  initFirstRow(matrix, rowSize);
  
  // Generate the rest of the matrix based on the first row
  generateMatrix(matrix, rowSize);

  // Save the matrix to the text file
  int answer;
  printf ("\nSave the matrix?\n48 - Yes \n49 - No \nInput: ");
    scanf("%i", &answer);
    switch (answer)
    {
      case '0':
      {
        // TODO: Free the memory space allocated
        saveMatrix(matrix, rowSize);
        free(matrix);
        printf("Memory successfully freed.\n");
        break;
      }
      case '1':
      {
        printf("So long...\n");
        sleep(1);
        printf("Au revoir...\n");
        sleep(1);
        exit(0);
        break;
      }
    }
    
    return 0;
  
}

void initFirstRow(int *matrix, int rowSize)
{
  int i = 0; 
  int input;
  int fact = (rowSize-1); 
  
  printf("Enter Values between 0 - %i: \n", fact);
  while(i < rowSize)
  {
  int j = (i + 1);
    printf("Value %i : ", j);
      scanf("%i", &input);
    for(int k = 0; k < i; k++)
    {
      if(input == matrix[k])
      {
        printf("%i is already in use! Let's try again (Value %i): ", input, j);
        scanf("%i", &input);
      }
      if(input == matrix[k])
      {
        printf("No really, try something new... (Value %i): ", j);
        scanf("%i", &input);
      }  
      if (input > fact || input < 0)
      {
        printf("Not within range! Try again (Value %i): ", j);
        scanf("%i", &input);
      } 
    }
  matrix[i] = input;
  i++;
  }
}

void generateMatrix(int *matrix, int rowSize)
{
  // TODO; Keep a reference to the root tone (First tone in P0)
  int root = matrix[0];

  // TODO: Fix the pitch class to make the first tone start from 0
  for (int i=0; i < rowSize; i++)
  {
    matrix[i] = matrix[i] - root;
    if (matrix[i] < 0)
    {
      matrix[i] = matrix[i] + rowSize;
    }
  }
  // TODO: Get the inversion of P0 and populate I0
  for (int i = 0; i < rowSize; i++)
  {
    if (i !=0)
    {
      matrix[i * rowSize] = abs(rowSize - matrix[i]);
    }
    matrix = matrix + 1;
  // TODO: Fill out the rest of transposition
  for (int row = 1; row < rowSize; row++)
  {
    for (int column = 1; column < rowSize; column++)
    {
      int i = (row * rowSize + column);
      matrix[i] = matrix[row*rowSize] + matrix[column];
      if (matrix[i] >= rowSize)
      {
        matrix[i] = matrix[i] - rowSize;
      }
    }
  }
  // TODO: Add back the root tone to the matrix
  for (int i = 0; i < rowSize; i++)
  {
    for(int k =0; k < rowSize; k ++)
    {
      if(matrix[i*rowSize + k] + root >= rowSize)
      {
        matrix[i*rowSize + k]= root + matrix[i*rowSize + k] - rowSize;
      }
      else
      {
        matrix[i*rowSize + k]= matrix[i*rowSize + k]+ root;
      }
    }
  }
}

}

//-------------------- Utility Functions --------------------
{
void saveMatrix(int *matrix, int rowSize){
  FILE *file; // Keep a reference to a text file
  file = fopen("matrix.txt", "w"); // open a text file in the write mode
  
  if(file == NULL){ // Check if the file opened
    printf("matrix.txt file could not be opened...\n");
    return;
  }

  // Go through the matrix and write the values in the text file
  for(int r = 0; r < rowSize; r++){
    for(int c = 0; c < rowSize; c++){
      fprintf(file, "%d ", matrix[r * rowSize + c]);
    }
    fprintf(file, "\n");
  }

  fclose(file); // Close the text file
}

unsigned int randomInt(int min, int max){
  unsigned int randval;
  FILE *f;

  f = fopen("/dev/random", "r");
  fread(&randval, sizeof(randval), 1, f);
  fclose(f);

  return (randval % (max - min)) + min;
}

void shuffle(int *array, size_t n)
{
  if (n > 1) 
  {
      size_t i;
      for (i = 0; i < n - 1; i++) 
      {
        size_t j = i + randomInt(0, UINT_MAX) / (UINT_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
      }
  }
}
}
  // TEST NODE//
    /* we want the interval to be negative to make sums easier later on.
		 * thus, if the ith note in the base tone row is less than the
		 * 0th note, simply subtract the 0th note from the ith note;
		 * on the other hand, if the ith note is greater, again subtract the
		 * 0th note from the ith note, but also subtract 12 to make it the
		 * negative difference mod 12.
		  interval = (tr[i] < tr[0]) ? tr[i] - tr[0] : tr[i] - tr[0] - 12; */