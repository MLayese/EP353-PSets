#include "dictionary.h"
#include "ntarray.h"
#include "macro.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void initDict() {
	srand(time(NULL));
}

//Defined DictionaryItem as a struct to hold all the data
DictItem* createDict(char* d, int w) {
	CHECK(d != NULL, NULL);
	DictItem* dict = malloc(sizeof(DictItem)); //allocate memory so it doesn't die
	CHECK(dict != NULL, NULL);

	//arrow operators inside structs
	dict->data = malloc(strlen(d));
	if(dict->data == NULL) {
		free(dict);
		return NULL;
	}
	strcpy(dict->data, d);

	//associates w with weight of a word
	dict->weight = w;
	dict->next = NULL;

	return dict;
}

//adds words to dictionary
int addToDict(DictItem** dict, char* d, int w) {
	DictItem* item = createDict(d, w);
	CHECK(item != NULL, -1);

//notates when words are used more than once or only once
	if(*dict == NULL) {
		*dict = item;
		return 1;
	}

	if((*dict)->next != NULL) {
		item->next = (*dict)->next;
	}

	(*dict)->next = item;
	return 1;
}

//clears dictionary after every iteration
void deleteDict(DictItem** d) {
	CHECKVOID(*d != NULL);

	if((*d)->next == NULL) {
		free(*d);
		return;
	}
	DictItem* cur;

	cur = *d;
	while(cur != NULL) {
		DictItem* save = cur;
		cur = cur->next;
		free(save);
	}
	*d = NULL;
}

//determines the value of a word (how many times it's iterated through the file)
int getDictWeight(DictItem* d) {
	CHECK(d != NULL, -1);

	DictItem* cur = d->next;
	int count = d->weight;
	while(cur != NULL) {
		count = count + cur->weight;
		cur = cur->next;
	}
	return count;
}

//functions like RandomWalk in TineMatrix
char* pickRandWord(DictItem* d) {
	CHECK(d != NULL, NULL);

	int weight = getDictWeight(d);
	int ran = rand() % weight;

	if(d->next == NULL) {
		return d->data;
	}

	DictItem* cur = d;
	int curWeight = 0;
	while(cur->next != NULL) {
		curWeight += cur->weight;
		if(curWeight >= ran) {
			return cur->data;
		}
		cur = cur->next;
	}
	return cur->data;
}

//determines weight of word (how often it's seen the nth order og the markov chain)
int calcWeight(int w) {
	return w * 2;
}

DictItem* buildDict(char** words, NTArray* keys) {
	int keyLen = ntLen(keys->data);
	CHECK(keyLen > 0, NULL);

	int wordLen = ntLen(words);
	CHECK(wordLen > 0, NULL);

	DictItem* dict = NULL;
	int i;
	int j;
	int weight;
	for(i = 0; i < wordLen; i++) {
		if(strcmp(words[i], keys->data[0]) == 0) {
			weight = 1;
			j = 1;
			while(j < keyLen && j <= i) {
				if(strcmp(words[i - j], keys->data[j]) == 0) {
					weight = calcWeight(weight);
				} else {
					break;
				}
				j++;
			}
			if(i < wordLen - 1) {
				CHECK(addToDict(&dict, words[i + 1], weight)!= -1, NULL);
			}
		}
	}

	if(dict == NULL) {
		CHECK(addToDict(&dict, ntRandom(words), 1) != -1, NULL);
	}
	return dict;
}
