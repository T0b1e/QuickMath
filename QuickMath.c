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

int levelOne(int number1,int number2) //level 1
{
	int Ans = number1+number2;
	printf("%d + %d = ", number1, number2);
	printf("Your Answer: ");
        scanf("%d", &playerAnswer);
        printf("Your Answer: ");
        scanf("%d", &playerAnswer);
	if(Ans)
	{
		printf("Go to Next Level!:\n");
	}
	else
	{
		printf("Your Ans is Wrong!!!");
	}
}

int levelTwo(int number1,int number2) //level 2
{
	int Ans = number1-number2;
	printf("%d - %d = ", number1, number2);
	printf("Your Answer: ");
        scanf("%d", &playerAnswer);
        printf("Your Answer: ");
        scanf("%d", &playerAnswer);
	if(Ans)
	{
		printf("Go to Next Level!:\n");
	}
	else
	{
		printf("Your Ans is Wrong!!!");
	}
	
}

int levelThree(int number1,int number2,int number3) //level 3
{
	int Ans = number1+number2-number3;
	printf("%d + %d - %d = ", number1, number2,number3);
	printf("Your Answer: ");
        scanf("%d", &playerAnswer);
        printf("Your Answer: ");
        scanf("%d", &playerAnswer);
	if(Ans)
	{
		printf("Go to Next Level!:\n");
	}
	else
	{
		printf("Your Ans is Wrong!!!");
	}
	
}

int levelFour(int number1,int number2) //level 4
{
	int Ans = number1+number2;
	printf("%d + %d = ", number1, number2);
	printf("Your Answer: ");
        scanf("%d", &playerAnswer);
        printf("Your Answer: ");
        scanf("%d", &playerAnswer);
	if(Ans)
	{
		printf("Go to Next Level!:\n");
	}
	else
	{
		printf("Your Ans is Wrong!!!");
	}
	
}

int levelFive(int number1,int number2) //level 5
{
	int Ans = number1+number2;
	printf("%d + %d = ", number1, number2);
	printf("Your Answer: ");
        scanf("%d", &playerAnswer);
        printf("Your Answer: ");
        scanf("%d", &playerAnswer);
	if(Ans)
	{
		printf("Go to Next Level!:\n");
	}
	else
	{
		printf("Your Ans is Wrong!!!");
	}
	
}
