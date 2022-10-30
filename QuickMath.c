#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void state();
int checkNumber();

main()
{
	int i;
	
	char playerName[20];
	int playerScore = 0, playerLevel = 3, number = 1;
	
	srand(time(0));
		
	int number1 = (rand() % 99) + 1;
	int number2 = (rand() % 99) + 1;
	
	// printf("%d %d", number1, number2);
	
	state(playerLevel, playerScore, number);
	int checkNumber(int playerLevel, int number2);
	printf("%d", number2);
}

void state(int level, int score, int no)
{
	printf("Attemp : %d ", no);
	printf("Level : %d ", level);
	printf("Point : %d \n", score);
}

int getInput()
{

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
