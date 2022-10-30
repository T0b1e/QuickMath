#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void state();
int checkNumber();

int levelOne();
int levelTwo();
int levelThree();
int levelFour();
int levelFive();

main()
{
	int i;
	
	char playerName[20];
	int playerScore = 0, playerLevel = 1, number = 1, playerAnswer;
	
	srand(time(0));
		
	int number1 = (rand() % 99) + 1;
	int number2 = (rand() % 99) + 1;
	
	// printf("%d %d", number1, number2);
	
	number2 = checkNumber(playerLevel,number2);
	
	while (1)
	{
		state(playerLevel, playerScore, number);
		if (playerLevel == 1)
		{
			levelOne(number1,number2);
			// Check Answer
		}
		else if (playerLevel == 2)
		{
			levelTwo(number1,number2);
			// Check Answer
		}
		else if (playerLevel == 3)
		{
			levelThree(number1,number2);
			// Check Answer
		}
		else if (playerLevel == 4)
		{
			levelFour(number1,number2);
			// Check Answer
		}		
		else if (playerLevel == 5)
		{
			levelFive(number1,number2);
			// Check Answer
		}
		else
		{
			printf("End Game");
		}
		
	}
}

void state(int level, int score, int no)
{
	printf("Attemp : %d ", no);
	printf("Level : %d ", level);
	printf("Point : %d \n", score);
}

int checkNumber(int level, int number2)
{
	int number;
	
	if (level == 3 || level == 4)
	{
		if (number2 >= 10)
		{
			srand(time(0));
			int number = (rand() % 10) + 1;
			return number;
		}
	}
	else
	{
		return number2;
	}
}

int levelOne(int number1,int number2)
{
	printf("%d + %d = ", number1, number2);
}

int levelTwo()
{
	
}

int levelThree()
{
	
}

int levelFour()
{
	
}

int levelFive()
{
	
}
