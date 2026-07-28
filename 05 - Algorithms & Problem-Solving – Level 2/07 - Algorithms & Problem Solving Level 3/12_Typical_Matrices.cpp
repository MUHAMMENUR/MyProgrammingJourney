#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

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
			// Generate a random number between 1 and 100 and assign it to the cell
			int Random = RandomNumber(1, 10);
			
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
 * Checks if two 3x3 matrices are typically equal (cell-by-cell matching).
 * @param matrix The first source 3x3 matrix.
 * @param matrix2 The second source 3x3 matrix.
 * @return True if all corresponding elements match perfectly, otherwise false.
 */

bool AreMatricesTypicallyEqual(int matrix[3][3], int matrix2[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// 🌟 Early Return: If even a single mismatch is found, exit immediately
			if (matrix[i][j] != matrix2[i][j]) {
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
	int matrix2[3][3];
	

	// Step 1: Populate and display the first random matrix
	GenerateRandomMatrix(matrix1);
	cout << "Matrix 1: " << endl;
	PrintMatrix(matrix1);

	// Step 2: Populate and display the second random matrix
	GenerateRandomMatrix(matrix2);
	cout << "Matrix 2: " << endl; 
	PrintMatrix(matrix2);

	// Step 3: Evaluate typical equality and print the formatted result
	if (AreMatricesTypicallyEqual(matrix1, matrix2)) {
		cout << "YES: The matrices are equal" << endl;

	}
	else {
		cout << "NO: The matrices are NOT equal" << endl;
	}





	return 0;

   
}
