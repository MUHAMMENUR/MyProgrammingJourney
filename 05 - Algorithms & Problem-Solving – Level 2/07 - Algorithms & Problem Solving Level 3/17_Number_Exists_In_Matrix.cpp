#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

/**
 * Prompts the user for a positive integer and ensures compliance via a do-while loop.
 * @param Message The string prompt displayed to the user.
 * @return A strictly positive integer.
 */
int ReadPositiveNumber(string Message) {
	int Number;
	do {
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}
int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

/**
 * Populates a 3x3 matrix with random numbers and prints it in a grid format.
 * * @param matrix The 3x3 2D array to be generated and displayed.
 */
void GenerateRandomMatrix(int matrix1[3][3]) {
	// Loop through each column of the current row
	for (int i = 0; i < 3; i++) {
		// Generate a random number between 1 and 100 and assign it to the cell
		for (int j = 0; j < 3; j++) {
			int Random = RandomNumber(0, 1);
			
			matrix1[i][j] = Random;
			

			
			

		}
		
	}
}

/**
 * Prints a 3x3 matrix in a clean grid format.
 * @param Matrix The 3x3 2D array to be displayed.
 */
void PrintMatrix(int Matrix[3][3]) {
	for (int i = 0; i < 3; i++) {
		
		for (int j = 0; j < 3; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

/**
 * Checks if a specific target number exists anywhere inside a 3x3 matrix.
 * @param matrix The 3x3 2D array to search within.
 * @param target The integer to locate.
 * @return True immediately if found (Early Return), otherwise false after full traversal.
 */
bool IsNumberInMatrix(int matrix[3][3], int target) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[i][j] == target) {
				return true;
			}
		}
	}
	return false;
}


int main() {
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator with the current time)
	// Declare a static 3x3 matrix of integers
	int matrix1[3][3];
	
	

	// Step 1: Populate and display the first random matrix
	GenerateRandomMatrix(matrix1);
	cout << "Matrix 1: " << endl;
	PrintMatrix(matrix1);
	// Step 2: Read validated positive input from user
	int Target = ReadPositiveNumber("Enter a positive number to search in the matrix: ");

	// Step 3: Validate existence and display outcome
	if (IsNumberInMatrix(matrix1, Target)) {
		cout << "The number " << Target << " is found in the matrix." << endl;
	} else {
		cout << "The number " << Target << " is not found in the matrix." << endl;
	}	
	

	
	return 0;

   
}
