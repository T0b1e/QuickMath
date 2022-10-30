#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// ---------- Call Function ------------

void state();
int checkNumber();

int levelOne();
int levelTwo();
int levelThree();
int levelFour();
int levelFive();

int userInput();
int checkAnswer();

void endGame();

// ---------- Global Var ------------

int number1, number2;
char playerName[20];
int playerScore = 0, playerLevel = 1, number = 1, playerAnswer;


main()
{
	while (1)
	{
		int a = 1, u = 1, c = 1;
		
		checkNumber(playerLevel);
		
		state(playerLevel, playerScore, number);
		
		if (playerLevel = 1) 		{ a = levelOne(number1,number2);}
		else if (playerLevel = 2) 	{ a = levelTwo(number1,number2); }
		else if (playerLevel = 3) 	{ a = levelThree(number1,number2); }
		else if (playerLevel = 4) 	{ a = levelFour(number1,number2); }
		else if (playerLevel = 5) 	{ a = levelFive(number1,number2); }
		else { printf("Invalid"); }
		
		u = userInput();
		c = checkAnswer(a, u);
		
		if (c == 0){ endGame(); break; }
		
		number += 1;
		
	}
}

// ---------- Default ------------

void state()
{
	printf("Attemp : %d ", number);
	printf("Level : %d ", playerLevel);
	printf("Point : %d \n", playerScore);
}

void endGame()
{
	char ans;
	printf("\n\n---------GAME OVER---------\n");
	printf("Game Over Thank You For Playing Us\n");
	printf("This is Your Score\n");
	printf("\n---------------------------\n");
	printf("Attemp : %d ", number);
	printf("Level : %d ", playerLevel);
	printf("Point : %d \n", playerScore);
	
	printf("Try Again(Y/n) ?");
	ans = getchar();
	ans == 'Y' && printf("Goodluck");
}

// Random Number

int checkNumber(int level)
{
	int number;
	
	srand(time(0));
	
	if (level == 1)
	{
		number1 = (rand() % 10) + 1;
		number2 = (rand() % 10) + 1;
	}
	else if (level == 2)
	{
		number1 = (rand() % 10) + 1;
		number2 = (rand() % 10) + 1;
		
		if (number1 <= number2)
		{
			number2 = (rand() % 10) + number1;
		}
	}
	else if (level == 3)
	{
		number1 = (rand() % 50) + 1;
		number2 = (rand() % 50) + 1;	
	}
	else if (level == 4 || level == 5)
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

// ---------- Get Input and Check Answer ------------

int userInput()
{
	printf("\nYour Answer: ");
    scanf("%d", &playerAnswer);
    
    return playerAnswer;
}


int checkAnswer(int answer, int userAnswer)
{
	if (answer == userAnswer)
	{
		printf("Correct\n");
		playerScore += 10;
		
		if (playerScore <= 20) { playerLevel = 1 ; return 1;}
		else if (playerScore > 20 && playerScore <= 50) { playerLevel = 2; return 1;}
		else if (playerScore > 50 && playerScore <= 100) { playerLevel = 3; return 1;}
		else if (playerScore > 100 && playerScore <= 150) { playerLevel = 4; return 1;}
		else if (playerScore > 150 && playerScore <= 200) { playerLevel = 5; return 1;}
		else { printf("Invalid"); return 0;}
	}
	else
	{
		printf("Wrong\n");
	}
}

// ---------- Level ------------

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
