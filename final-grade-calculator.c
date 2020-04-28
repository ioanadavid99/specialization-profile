/* 
Author:			Ioana David
Purpose:		Generates the absolute minimum grade an individual must achieve in a course in order to pass it. 
Last modified:	December 22nd 2017 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

#define GRADES_SIZE	15					// number of grades the user can enter 
#define NAME_SIZE	30					// max number of characters a user can enter for the name of the course/assessment 			
#define SENTINTEL	-1.0

#define TRUE		1
#define FALSE		0
#define ERROR		2

void resetArray(double grades[2][GRADES_SIZE]); 
void storeGrades(double grades[2][GRADES_SIZE], int indexArray, char name[NAME_SIZE]); 
int checkWeights(double grades[2][GRADES_SIZE]); 
double welcomeMessage(double grades[2][GRADES_SIZE], char name[NAME_SIZE]); 
void checkGrades(double grades[2][GRADES_SIZE], double passing_grade); 
int askUser(void); 

int main(void) {
	int indexArray; 
	double passing_grade;

	double grades[2][GRADES_SIZE]; 														// the top row will store the grade, the bottom row will store the associated weight
	char name[NAME_SIZE]; 

	do {
		resetArray(grades);																// makes sure the array is completely set to SENTINEL before storing grade
		passing_grade = welcomeMessage(grades, name);
		indexArray = 1;																	// resets the index for each time the loop is run. indexArray set to 1 because when it is 0, it stores the value for the weight of the final assessment 
		do {
			storeGrades(grades, indexArray, name); 
			indexArray++; 
			if (indexArray >= GRADES_SIZE) {
				printf("You have maxed out the number of different grades you can enter. Please modify the program to add more spaces.\n"); 
				break;																	// breaks out of the loop if the array of grades has been completely filled, and resets the index if the loop will run again 
			} 

		} while (checkWeights(grades)==FALSE);	

		if (checkWeights(grades) == ERROR)												// checks if the weights of the grades are greater than 100% or 1 (in decimal value)
			printf("Sorry, the weights you have entered add up to more than 100 percent. Please try again.\n");
	
		else																			// displays the minimum grade otherwise 
			checkGrades(grades, passing_grade); 

	} while (askUser()); 

	printf("Thank you for using my program! :-) -Ioana\n"); 

	system("PAUSE"); 

	return 0; 
} 

/* 
Purpose:	initializes the grades array to -1
Parameters:	the grades array
Return:		none
*/
void resetArray(double grades[2][GRADES_SIZE]) {
	int index; 

	for (index = 0; index < GRADES_SIZE; index++) {
		grades[0][index] = SENTINTEL; 
		grades[1][index] = SENTINTEL; 
	}
}

/* 
Purpose:	scans the user's grade and weight 
Parameters:	the array of grades, the index (so the array knows where to put the grades/weights), and the string so that the user can input a name for the assessment 
Return:		none
*/
void storeGrades(double grades[2][GRADES_SIZE], int indexArray, char name[NAME_SIZE]){
	double grade, weight;

	printf("\nName of assessment (no spaces): \n"); 
	; scanf("%s", name);															// allows for user input for their name. program doesn't actually do anything to it 
	printf("Grade: \n"); 
	scanf_s("%lf", &grade);															// grade of specific assessment		
	printf("Weight: \n"); 
	scanf_s("%lf", &weight);														// weight of specific assessment 

	grades[0][indexArray] = grade; 
	grades[1][indexArray] = weight; 

}

/*
Purpose:	checks if the user's weights have added up to 1 (100%). 
Parameters:	the array of grades
Return:		FALSE if the user's weights are below 1, TRUE if they are equal to 1, ERROR otherwise 
*/
int checkWeights(double grades[2][GRADES_SIZE]) {
	int index;
	double sum = 0.0;

	for (index = 0; grades[1][index] != SENTINTEL; index++) {
		sum = sum + grades[1][index];												// checks the sum of the weights 
	}

	if (sum < 1)
		return FALSE; 

	if (sum == 1)
		return TRUE; 

	if (sum > 1)
		return ERROR; 

}

/* 
Purpose:	displays the welcome message at the beginning of each cycle. 
Parameters:	the array of grades
Return:		the minimum passing grade for the course 
*/
double welcomeMessage(double grades[2][GRADES_SIZE], char name[NAME_SIZE]) {
	double weight, grade; 

	printf("Please enter the name of the course (no spaces): \n"); 
	; scanf("%s", name);																	// program doesn't actually do anything to the name that's entered 
	printf("\n"); 
	printf("Please note that you are a restricted to entering a maximum of %i grades.\n", GRADES_SIZE);						// warns user of how many grades they can enter
	printf("Please enter your weights as a decimal value, and your grades as a whole value (eg. 90, 80, 63.4).\n"); 
	printf("Please enter the weight for the final assessment: \n"); 
	scanf_s("%lf", &weight);																// weight of final assessment 

	grades[1][0] = weight; 

	printf("Please enter the minimum grade you must achieve in the course in order to pass: \n"); 
	scanf_s("%lf", &grade); 

	return grade; 
}

/* 
Purpose:	calculates the minimum grade the user needs to achieve on their final in order to pass the course
Parameters:	the array of grades, as well as the minimum grade the user needs to achieve in order to pass the course 
Return:		none 
*/
void checkGrades(double grades[2][GRADES_SIZE], double passing_grade) {
	int index; 
	double sum_grades = 0.0;
	double final_grade; 
	double weight = grades[1][0]; 

	for (index = 1; grades[1][index] != SENTINTEL; index++) {
		sum_grades = sum_grades + grades[1][index] * grades[0][index];					
	}																					
	
	final_grade = (passing_grade - sum_grades) / weight; 

	if (final_grade > 100)
		printf("Sorry, it appears that you need to achieve a final grade of over 100 percent on the final assessment in order to pass the course.\n");

	else if (final_grade >= 0 && final_grade <= 100)
		printf("The absolute minimum to pass is a %.2lf percent on your final assessment.\n", final_grade);

	else if (final_grade < 0)
		printf("No matter the grade on your final assessment, you will pass the course. :-) \n"); 
}

/* 
Purpose:	asks the user if they wish to calculate another mark 
Parameters:	none
Return:		0 if the user does not wish to continue, 1 otherwise 
*/
int askUser(void) {
	int userResponse; 

	printf("Would you like to calculate a grade for another course?\n"); 
	printf("Please enter 1 for yes, or 0 for no: \n"); 
	scanf_s("%i", &userResponse); 
	printf("\n"); 

	return userResponse; 
}
