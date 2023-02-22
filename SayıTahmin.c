//Writer : Hasan Hüseyin Gümüştepe

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 100


void initialize_number_generator(void);
int choose_secret_number(void);
void read_guesses(int secret_number);


int main() {

	char command;
	int secret_number;
	printf("Guess the secret number between 1 and 100.");
	initialize_number_generator();
	
	do
	{
		secret_number = choose_secret_number();
		printf("A new number has been chosen.\n");
		read_guesses(secret_number);
		printf("Play again?(Y/y)");
		scanf(" %c",&command);
		printf("\n");
	} while (command=='Y' || command=='y');


	return 0;
}

void initialize_number_generator(void)
{	
	srand((unsigned)time(NULL));// generate random number
}

int choose_secret_number(void)
{
	return  rand() % MAX_NUMBER + 1;// select a number
}

void read_guesses(int secret_number)
{
	int guess, num_guesses = 0;
	for(;;){
		num_guesses++;
		printf("\nEnter guess: ");
		scanf("%d",&guess);
		if (guess == secret_number) {
			printf("You won in %d guessesw!\n\n", num_guesses);
			return;
		}
		else if (guess < secret_number) {
			printf("Too low! try again");
		}
		else  
			printf("Too high! try again");
		
	}

}
