
## Apollo - Poetry and Sound

Hello hello. This a text/MIDI generator built in C and utilizes some aspects of Sonic Pi.
This iteration generates text of *n* length by finding patterns in word sequences via Markov Chains. 

------------------ 
## Creating/Running the Program

I made a Makefile for easy compilation - In the terminal just type in ``` make ```. After compiling, there'll be a new file in your folder called ```Apollo```. The program will run by using the following format:
```
./Apollo file words depth
```
Filename is the relative file you want to use, wordcount is the amount of words you want to output, and depth is how many words back the program will check to assign values to new probable words. The output will be printed out in the terminal.
If we're using one of the Example Files it'd look like so:
```
./Apollo RapGod.txt 100 3
```
This is calling the ```Rapgod.txt``` file to be used as the dictionary, ```100``` words will be outputted from the program, and it'll go back ```3``` words to assign new values to a possible new word. 
If you just run 
```
./Apollo file or ./Apollo file words
```
it'll set the default values ( ```50``` for ```words``` and ```3``` for ```depth```) and run. 

----------------------
## There's a Library 

The ```paraphrace.h``` library is required to run:
```
#include "paraphrase.h"
```
It comes with paraBuild and arraytoStr:

## paraBuild

```paraBuild()``` is a null terminated array of char pointers consisting of the ```filename, wordcount and depth```. Leaving the ```wordcount``` or ```depth``` blank results in utilizing the default values. You can change the ```DEFAULT_LENGTH``` (line 6) and ```DEFAULT_DEPTH``` (line 7) in ```paraphrase.c```

## arrayToStr
Produces a string based off the null terminated array from ```paraBuild()```. You can directly fed the output of paraBuild.
Example:

```
arrayToStr(paraBuild("SummersDay.txt", -1, -1));
```
----------------
## Sonic Pi

There's Sonic Pi files in this folder that acted as sample beats to go along with the text output. You can use these as well or make your own.
