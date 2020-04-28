/* 
Author:			Ioana David
Last modified:	Feb 18 2018 
Purpose:		A basic calculator. 
*/

/*
ASCII values 
40	(
41	)
42	*
43	+
45	-
47	/
https://ascii.cl/
*/

#define TRUE	1
#define FALSE	0

#define SIZE	4				// the size of the array to store the different operators	

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> 

void welcomeMessage(void); 
int checkUser(void); 
int checkOperator(char inputOperator[]); 
void askUser(char operators[]); 


int main(void) {
	char operators[] = "+, -, *, /";

	do {
		welcomeMessage();
		askUser(operators); 
	} while (checkUser());						// while the user wants to calculate another expression, the loop continues 
	printf("Thank you for using my program! -Ioana\n"); 
	system("PAUSE"); 
	return 0; 
}

/*
Purpose:	displays a message at the beginning of every calculation. 
Parameters:	none
Return:		none
*/

void welcomeMessage(void) {
	printf("Thank you for using this calculator. Please note that it is currently very basic."
		"\nIt can only currently do one operation (multiplication, addition, subtraction or division) with two numbers (eg. A * B, with A and B being numbers).\n"); 
	printf("There are currently no restrictions on the types of numbers you can use. Just note that fractions must be expressed as decimals prior to calculating a final answer.\n"); 
}

/* 
Purpose:	checks whether the user wants to calculate another equation
Parameters:	none
Return:		true (1) if the user wishes to calculate another equation, or false (0) otherwise 
*/

int checkUser(void) {
	int response; 

	printf("Do you wish to calculate another equation? Please enter 1 for yes, and 0 for no.\n");
	scanf_s("%i", &response); 

	return response; 
}

/* 
Purpose:	determines the operator the user wishes to use 
Parameters:	the user's input, and the array of operators available to use 
Return:		the index value of the array, which will indicate which operator it is (based on its position in the array) 
*/

int checkOperator(char inputOperator[]) { 
	int index; 
	
	if (inputOperator[0] == 43)				// addition 
		index = 0;	

	else if (inputOperator[0] == 45)			// subtraction 
		index = 1; 

	else if (inputOperator[0] == 42)			// multiplication 
		index = 2;

 	else									// division 
		index = 3;  

	return index; 
}

/* 
Purpose:	calculate's the user's equation 
Parameters:	the array of operators the user can use in their equation  
Return:		the answer 
*/

void askUser(char operators[]) {
	double var1, var2, response;
	int operatorValue;
	char operator1[2]; 
	printf("Please enter your equation now: \n"); 
//	printf("Please enter the first number: \n"); 
//	scanf("%lf", &var1); 
//	printf("Please enter the operator: \n"); 
//	scanf("%s", &operator1); 
//	printf("Please enter the second number: \n"); 
//	scanf("%lf", &var2); 

	 scanf("%lf %c %lf", &var1, &operator1, &var2); 

	operatorValue = checkOperator(operator1);

	if (operatorValue == 0)								// uses the assigned operator in the calculation 
		response = var1 + var2; 

	if (operatorValue == 1)
		response = var1 - var2; 

	if (operatorValue == 2)
		response = var1 * var2;

	else if (operatorValue == 3)
		response = var1 / var2; 

	printf("The answer is: %.2lf\n", response); 
}
