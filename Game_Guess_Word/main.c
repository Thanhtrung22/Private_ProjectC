#include "main.h"

int main()
{
	FILE *file = NULL;
	char word_secret[20];
	int *count_win = NULL;
	char input = '\0';
	int count = 10;
	char sel = '\0';

	while(1)
	{
		system("cls");
		menu();
		printf("\nEnter mode game: ");
		fflush(stdin);
		sel = getche();
		switch(sel)
		{
			case '1':
			{
				
				char answer = '\0';
				while(answer != 'n' && answer !='N')
				{
					system("cls");
					count = 10;
					printf("\n\t\tGame Started\n ");
					printf("--------------------------------------------------------\n");
					Word_Secret(file, word_secret);
					init(word_secret, &count_win);

					do
					{
						printf("\nYou have %d turns\n", count);
						printf("Word Secret: ");
						for(int i = 0; i < strlen(word_secret); i++)
						{
							if(count_win[i])
							{
								printf("%c", word_secret[i]);
							}
							else
							{
								printf("*");
							}
						}
						printf("\nEnter your char: ");
						fflush(stdin);
						input = getchar();
						if(!(check_ki_tu(input, count_win, word_secret)))
						{
							count--;
						}
						
						if(count == 0)
						{
							printf("\nYou lose!\n");
							printf("\nWord secret is: %s", word_secret);
							break;
						}
					}while(check_win(count_win, word_secret) == 0 && count > 0);
					if(check_win(count_win, word_secret))
					{
						printf("You win!\n");
						printf("\nWord secret is: %s", word_secret);
					}
					free(count_win);
					printf("\nDo you want to continue the game?(y/n)");
					fflush(stdin);
					answer = getche();
					

				}
				break;
			}
			case '2':
			{
				printf("\nSee you again!");
				return 0;
			}
			default:
			{
				printf("\nInvalid selection!");
				getch();
			}
		}
	}
}