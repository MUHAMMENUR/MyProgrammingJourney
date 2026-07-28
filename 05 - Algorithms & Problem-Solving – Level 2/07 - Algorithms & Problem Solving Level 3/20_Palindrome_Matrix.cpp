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
			int Random = RandomNumber(0, 10);
			
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
 * Determines if a 3x3 matrix is a Palindrome Matrix (Symmetrical Rows).
 * @param matrix The 3x3 2D array to evaluate.
 * @return True if every row reads the same forwards and backwards, otherwise false.
 */
bool IsPalindromeMatrix(int matrix[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[i][0] != matrix[i][2]) {
				return false;
			}
		}
	}

	return true;
}



int main() {
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator with the current time)
	// Declare a static 3x3 matrix of integers
	int matrix1[3][3];
	
	
	

	// Step 1: Populate and display the first random matrix
	GenerateRandomMatrix(matrix1);
	cout << "Matrix 1: " << endl;
	PrintMatrix(matrix1);
	if (IsPalindromeMatrix(matrix1)) {
		cout << "YES: Matrix 2 is a Palindrome Matrix." << endl;
	}
	else {
		cout << "No: Matrix 2 is NOT a Palindrome Matrix." << endl;
	}

	
	return 0;

   
}
 