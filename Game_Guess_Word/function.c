#include "main.h"

void Word_Secret(FILE *file, char *word_secret)
{
	int count_file = 0;
	int random = 0;
	char temp = '\0';
	srand(time(NULL));
	file = NULL;
	file = fopen(INPUT_FILE, "r");
	if(file !=  NULL)
	{
		while(!feof(file))
		{
			if((temp = getc(file)) == '\n')
			{
				count_file++;
			}
				
		}
		
		random = (rand() % count_file) + 1;
		rewind(file);
		for(int i = 0; i < random; i++)
		{
			fgets(word_secret, 20, file);
			
		}
		word_secret[strlen(word_secret) - 1] = '\0';
		fclose(file);
	}
	else
	{
		printf("\nError! No file");
	}
}

bool check_ki_tu(char input, int *count_win,  char* word_secret)
{
	bool flag = 0;
	int len = strlen(word_secret);
	for(int i = 0; i < len; i++)
	{
		if(input == word_secret[i])
		{
			count_win[i] = 1;
			flag = 1;
			
		}
	}
	return flag;
}
bool check_win(int* count_win, char *word_secret )
{
	bool flag = 1;
	int len = strlen(word_secret);
	for(int i = 0; i < len; i++)
	{
		if(count_win[i] == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

void menu()
{
	printf("\n\t\tGAME GUESS WORD\n");
	printf("----------------------------------------------------------------\n");
	printf("1.Play with computer\n");
	printf("2.Exit\n");
}

void init(char *word_secret, int **count_win)
{
	int len = strlen(word_secret);
	*count_win = (int*) malloc (len * sizeof(int));
	for(int i = 0; i < len; i++)
	{
		(*count_win)[i] = 0;
	}
}
