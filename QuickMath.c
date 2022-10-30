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

int userInput();
int checkAnswer();

int number1, number2;
char playerName[20];
int playerScore = 0, playerLevel = 1, number = 1, playerAnswer;

main()
{
	while (1)
	{
		int a = 1, u = 1, c = 1;
		
		srand(time(0));

		number1 = (rand() % 99) + 1;
		number2 = (rand() % 99) + 1;
		
		number2 = checkNumber(playerLevel,number2);
		
		state(playerLevel, playerScore, number);
		
		if (playerLevel == 1)
		{
			a = levelOne(number1,number2);
			u = userInput();
			c = checkAnswer(a, u, playerScore);
		}
		else if (playerLevel == 2)
		{
			a = levelTwo(number1,number2);
			u = userInput();
			c = checkAnswer(a, u, playerScore);
		}
		else if (playerLevel == 3)
		{
			a = levelThree(number1,number2);
			u = userInput();
			c = checkAnswer(a, u, playerScore);
		}
		else if (playerLevel == 4)
		{
			a = levelFour(number1,number2);
			u = userInput();
			c = checkAnswer(a, u, playerScore);
		}		
		else if (playerLevel == 5)
		{
			a = levelFive(number1,number2);
			u = userInput();
			c = checkAnswer(a, u, playerScore);
		}
		else
		{
			printf("End Game");
		}
		
		number += 1;
		
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

int userInput()
{
	printf("\nYour Answer: ");
    scanf("%d", &playerAnswer);
    
    return playerAnswer;
}

int checkAnswer(int answer, int userAnswer, int playerScore)
{
	if (answer == userAnswer)
	{
		printf("Correct\n");
		playerScore += 10;
	}
	else
	{
		printf("Wrong\n");
	}
}

int levelOne(int number1,int number2) //level 1
{
	int Ans = number1+number2;
	printf("%d + %d = ", number1, number2);
	return Ans;
}

int levelTwo(int number1,int number2) //level 2
{
	int Ans = number1-number2;
	printf("%d - %d = ", number1, number2);
	return Ans;
}

int levelThree(int number1,int number2,int number3) //level 3
{
	int Ans = number1+number2;
	printf("%d + %d = ", number1, number2);
	return Ans;
}

int levelFour(int number1,int number2) //level 4
{
	int Ans = number1+number2;
	printf("%d + %d = ", number1, number2);
	return Ans;
}

int levelFive(int number1,int number2) //level 5
{
	int Ans = number1+number2;
	printf("%d + %d = ", number1, number2);
	return Ans;
}
