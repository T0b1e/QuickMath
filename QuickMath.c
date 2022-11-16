// Quick Math Game Project

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<conio.h>

// ---------- Call Function ------------

char start(); // text when start game
char howToPlay(); // text page how to play function

void state();  // Board Above Question Number Attemp Level 
void mainGame(); // Function call main process
int checkNumber(); // Checking numberical for reduce negative number

int levelOne(); // +
int levelTwo(); // -
int levelThree(); // +, -
int levelFour(); // *
int levelFive(); // /

int userInput(); // get user answer
int checkAnswer(); // check if correct or wrong

char endGame(); // text page endGame function

// ---------- Global Var ------------

int number1, number2; // Change everytime and use in a lot of func so it would be wasier if i did global var
int playerScore = 0, playerLevel = 1, number = 1, playerAnswer, Ans, a = 1, u = 1; 
int health = 3;
main()
{
	char s;

	s = start(); // Start Screen Y(Play) H(Help) Q(Exit)

	if (s == 'Y' || s == 'y') // Play
	{
		mainGame();
	}
	else if (s == 'H' || s == 'h') // How to play from start line 35
	{
		howToPlay(); // Go to how to play funcion page
	}	
	else
	{
		getch(); // TYPE GET OUT OF THIS GAME
	}
}

// ---------- Default ------------

void state() // Board
{
	printf("\n------------------------\n");
	printf("Attemp : %d ", number);
	printf("Health : %d \n", health);
	printf("Level : %d ", playerLevel);
	printf("Point : %d \n", playerScore);
}

void mainGame()
{	
	clock_t t;
	t = clock();
			
	while (1) // While True
	{
		int c, e; // Set function return to default
		
		checkNumber	(); // When level reach 4-5 i decrease hard
		
		state(); // Show Board
		
		// Check Player Level And Go on Each Level Function
		
		if (playerLevel == 1) 		{ a = levelOne();}
		else if (playerLevel == 2) 	{ a = levelTwo(); }
		else if (playerLevel == 3) 	{ a = levelThree(); }
		else if (playerLevel == 4) 	{ a = levelFour(); }
		else if (playerLevel == 5) 	{ a = levelFive(); }
		else { printf("Invalid"); }
		
		// Get user answer
		u = userInput();
		// Check answer is correct or no
		c = checkAnswer();
		
		// if (u == 404){ time_t end = time(NULL); break; } //ADMIN COMMAND !!!
		
		if (c == 0) // Wrong Answer
		{ 
			if (health == 0)
			{
				t = clock() - t;
				double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
				
				e = endGame(time_taken); 
				
				if (e == 0) // Try again is false GO BACK HOME
				{
					printf("\nThank You For Get In Touch with us");
					break;
				}
				else // Go again
				{
					// Reset Valiable
					playerScore = 0; playerLevel = 1; number = 1; playerAnswer; Ans, health = 3;
					continue;
				}
			}
			
		}
		else if (c == 2) // Pass the game congratulation
		{
			break;
		}
		
		number += 1; // Attemp number
		
		}
		
}

char start() // Start Page
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
	return state; // return state value (y, h, q)
}

char howToPlay() // How To Play Page
{
	char letPlay; // State Did you Play if play go mainGame else Break
	
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
	
	printf("\nLet Play or Exit (Y/n) ?"); // For get out of this page
	scanf("%s", &letPlay); 
	if (letPlay == 'N' || letPlay == 'n') { return 0; } // If not go next then we go home
	else { mainGame(); return 1; } //  else go previous page start page line 109
}

char endGame(double time_usage) // Game over page
{
	char playNext;
	
	printf("\n							GAME OVER\n");
	printf("					 Game Over Thank You For Playing Us\n");
	printf("						   This is Your Score\n");
	printf("\n						---------------------------\n");
	printf("						Attemp : %d \n", number);
	printf("						Level : %d \n", playerLevel);
	printf("						Point : %d \n", playerScore);
	printf("						Time : %f \n", time_usage);
	printf("Try Again(Y/n) ?: "); // Go Play Next Game
	scanf("%s", &playNext);
	printf("\n                              			*** END Credit ***\n");
	
	printf("\n					Narongkorn Kitrungrot 6505065\n");
	printf("					Patiphat Sombat 6506335\n");
	printf("					Kongpop Chomseang 6506201\n");
	printf("					Nattapat Mosagul 6505486\n");
	printf("					Sathaporn Wongwaikitkajohn 6505252\n");
	printf("\n   						 In TERM | PRIVACY \n");
	
	printf("\nThis Game Is Testing\n");
	printf("Please Donate Monny For us\n");
	
	if (playNext == 'N' || playNext == 'n') { return 0; } // if play again then return value to 0
	else { return 1; } 

}

// Random Number

int checkNumber()
{

	srand(time(0)); // generate new seed each attemp
	
	if (playerLevel == 1) // Random number 1-10
	{
		number1 = (rand() % 10) + 1;
		number2 = (rand() % 10) + 1;
		
		if (number1 == number2)
		{
			number2 = (rand() % 10) + 1; // generate new number to be not same as number 1
		}
	}
	else if (playerLevel == 2) // random 1-10
	{
		number1 = (rand() % 10) + 1;
		number2 = (rand() % 10) + 2;
		
		if (number2 >= number1) // check number to be unnegative ex. -1 -2 -3
		{
			srand(time(0)); // generate new number
			number1 = (rand() % 10) + number2; // random number at 1-first number for has more value to be positive minus
		}
	}
	else if (playerLevel == 3) // random 1-50
	{
		number1 = (rand() % 50) + 2; 
		number2 = (rand() % 50) + 2;
		if (number2 >= number1) // check number to be unnegative ex. -1 -2 -3
		{
			srand(time(0)); // generate new number
			number1 = (rand() % 50) + number2; // random number at 1-first number for has more value to be positive minus
		}	
	}
	else if (playerLevel == 4 || playerLevel == 5) // random 1-50
	{
		
		number1 = (rand() % 50) + 2; 
		number2 = (rand() % 10) + 2; // secondary number is less than 10
		printf("%d %d %d", number1, number2 , number1 % number2);
		if (number1 % number2 != 0) 
		{
			number2 -= (number1 % number2); //try to be odd and even number
			if (number1 % number2 != 0) // For make sure second number should be divided correctly
			{ 
				number1 += (number1 % number2);
			}
		}
		
	}
}

// ---------- Get Input and Check Answer ------------

int userInput() 
{
	printf("\nYour Answer: ");
    scanf("%d", &playerAnswer);
    if (playerAnswer){ playerAnswer; } // Check if user input something isn't NULL or EMPTY
    else {
    	return 0;
	}

}

int checkAnswer() // Check answer if correct or no
{
	if (a == u) // Correct Answer
	{
		printf("Correct\n");
		playerScore += 10; // Add point 10 points
		
		if (playerScore <= 20) { playerLevel = 1 ; return 1;} // return 1 it mean correct
		else if (playerScore > 20 && playerScore <= 50) { playerLevel = 2; return 1;} // 2 round or less 5 round
		else if (playerScore > 50 && playerScore <= 100) { playerLevel = 3; return 1;}
		else if (playerScore > 100 && playerScore <= 150) { playerLevel = 4; return 1;}
		else if (playerScore > 150 && playerScore <= 200) { playerLevel = 5; return 1;}
		else // Finish Game
		{ 
			printf("\n\n\n             CONGRATULTIONS \n"); 
			printf("	You can recieve reward from !! Mr. KONGPOP !!");
			return 2; // return 2 is mean congratulations
		}
	}
	else // If answer wrong or any case sensitive
	{
		health -= 1;
		printf("Wrong\n");
		printf("And The correct answer is %d", Ans);
		return 0; // return 0 for wrong answer
	}
}

// ---------- Level ------------

int levelOne() //level 1
{
	Ans = number1 + number2;
	printf("\n	%d + %d = \n", number1, number2); // Show Question
	return Ans;
}

int levelTwo() //level 2
{
	Ans = number1 - number2;
	printf("\n	%d - %d = \n", number1, number2); // Show Question
	return Ans;
}

int levelThree() //level 3
{
	int num = (rand() % 2) + 1; // random number 1-2
	if (num == 1)
	{
		printf("\n    %d + %d = \n", number1, number2);
		Ans = number1 + number2;

	} 
	else
	{
		printf("\n    %d - %d = \n", number1, number2);
		Ans = number1 - number2;
	}
	return Ans;
}

int levelFour() //level 4
{
	Ans = number1 * number2;
	printf("\n	%d * %d = \n", number1, number2); // Show Question
	return Ans;
}

int levelFive() //level 5
{
	int Ans = number1 / number2;
	printf("\n	%d / %d = \n", number1, number2); // Show Question
	return Ans;
}
