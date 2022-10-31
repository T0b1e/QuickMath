#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// ---------- Call Function ------------

char start();
char userName();

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
int playerScore = 0, playerLevel = 1, number = 1, playerAnswer, Ans;


main()
{
	
	char s;
	char playerName[20];
	s = start();

	if (s == 'Y' || s == 'y')
	{
		//playerName[20] =  userName();
		//printf("%s", playerName);
		while (1)
		{
			int a = 1, u = 1, c;
			
			checkNumber(playerLevel);
			
			state(playerLevel, playerScore, number);
			
			
			if (playerLevel == 1) 		{ a = levelOne(number1,number2);}
			else if (playerLevel == 2) 	{ a = levelTwo(number1,number2); }
			else if (playerLevel == 3) 	{ a = levelThree(number1,number2); }
			else if (playerLevel == 4) 	{ a = levelFour(number1,number2); }
			else if (playerLevel == 5) 	{ a = levelFive(number1,number2); }
			else { printf("Invalid"); }
			
			
			u = userInput();
			c = checkAnswer(a, u);
			
			if (c == 0){ endGame(); break; }
			
			number += 1;
		}
	}
	else if (s == 'H' || s == 'h')
	{
		printf("\n\n\n\n");
		printf("						How to Play\n");	
		printf("				This game is created for education and fun purpose\n");
		
		printf("					type y in CMD or Y in play\n\n");
		
		printf("The Question Will Appear (Ex 1+1= )\n");
		printf("Then The Answer Space Will Appear (Ex Ans: )\n");
		printf("If your answer is matched or correct then it will pass to next question to next level \n\n");
		
		printf("Game Plan\n");
		printf("The Level\n");
		printf("----------------\n");
		printf("|level 1| +    |\n");
		printf("|level 2| -    |\n");
		printf("|level 3| +, - |\n");
		printf("|level 4| *    |\n");
		printf("|level 5| /    |\n");
		printf("----------------\n");
		printf("In each question will has own 10 point\n\n");
		
		printf("Else if your answer is Wrong Then Game Will be over and you can try again by typing y in CMD\n");
		printf("If there has any bug or Error I am aplogize for that, We will find and improve as soon as possible\n");
		printf("Hope you Enjoy\n");
	}	
	else
	{
		getch();
	}
	
}

// ---------- Default ------------

void state()
{
	// printf("Username : %s ", playerName);
	printf("\n-----------------\n");
	printf("Attemp : %d ", number);
	printf("Level : %d ", playerLevel);
	printf("Point : %d \n", playerScore);
}

char start()
{	
	char state;
	printf("\n\n\n\n\n");
	printf("              			    	   Hello And Welcome To\n");
	printf("						Quick Math");
	printf("\n\n\n");
	printf("						Play (y)\n");
	printf("                                            How to play (h)\n");
	printf("						Exit (q)\n");
	printf("\n\n\n");
	printf("ENTER : ");
	scanf("%s", &state);
	// printf("%s",  state);
	return state;
}

char userName()
{
	char user[20];
	printf("UserserName: ");
	scanf("%s", &user);
	return user[20];
}

void endGame()
{
	char ans;
	printf("\n							GAME OVER\n");
	printf("					 Game Over Thank You For Playing Us\n");
	printf("						   This is Your Score\n");
	printf("\n						---------------------------\n");
	printf("						Attemp : %d \n", number);
	printf("						Level : %d \n", playerLevel);
	printf("						Point : %d \n", playerScore);
	
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
		
		if (number2 > number1)
		{
			srand(time(0));
			number2 = (rand() % number1) + 1;
		}
	}
	else if (level == 3)
	{
		number1 = (rand() % 50) + 1;
		number2 = (rand() % 50) + 1;	
	}
	else if (level == 4 || level == 5)
	{
		
		number1 = (rand() % 50) + 1;
		number2 = (rand() % 10) + 1;
		
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
		else if (playerScore > 20 && playerScore <= 50) { playerLevel = 2; return 1;} // 2 round or less 5 round
		else if (playerScore > 50 && playerScore <= 100) { playerLevel = 3; return 1;}
		else if (playerScore > 100 && playerScore <= 150) { playerLevel = 4; return 1;}
		else if (playerScore > 150 && playerScore <= 200) { playerLevel = 5; return 1;}
		else { printf("Invalid"); return 0;}
	}
	else
	{
		printf("Wrong\n");
		printf("And The correct answer is %d", Ans);
		return 0;
	}
}

// ---------- Level ------------

int levelOne(int number1,int number2) //level 1
{
	Ans = number1+number2;
	printf("%d + %d = ", number1, number2);
	return Ans;
}

int levelTwo(int number1,int number2) //level 2
{
	Ans = number1-number2;
	printf("%d - %d = ", number1, number2);
	return Ans;
}

int levelThree(int number1, int number2) //level 3
{
	int num = (rand() % 2) + 1;
	char d;
	char operator[2] = {'+', '-'}; 
	d = operator[num - 1];
	Ans = num - 1 == 0 ? number1 + number2 : number1 - number2;
	printf("%d %c %d = ", number1, d, number2);
	return Ans;
}

int levelFour(int number1,int number2) //level 4
{
	Ans = number1 * number2;
	printf("%d * %d = ", number1, number2);
	return Ans;
}

int levelFive(int number1,int number2) //level 5
{
	int Ans = number1 / number2;
	printf("%d / %d = ", number1, number2);
	return Ans;
}
