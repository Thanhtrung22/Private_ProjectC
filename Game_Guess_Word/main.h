#ifndef _MAIN_HEADER_
#define _MAIN_HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <conio.h>


#define INPUT_FILE "Secret_Word.txt"


void Word_Secret(FILE *file, char *word_secret);
bool check_ki_tu(char input, int *count_win, char* word_secret);
bool check_win(int* count_win, char* word_secret);
void menu();
void init(char *word_secret, int **count_win);



#endif
