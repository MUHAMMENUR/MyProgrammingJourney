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
 * Checks if the given 3x3 matrix is a Scalar Matrix.
 * @param Matrix The 3x3 2D array to check.
 * @return True if all diagonal elements are equal and non-diagonal elements are 0, otherwise false.
 */
bool IsScalerMatrix(int Matrix[3][3]) {
	int FirstDigit = Matrix[0][0]; // Store the first diagonal element for comparison
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// Check diagonal elements (where row index equals column index)
			if (i == j && Matrix[i][j]!=FirstDigit) {
				return false;
			}
			// Check non-diagonal elements (where row index does not equal column index)
			else if (i != j && Matrix[i][j] != 0) {
				return false;
			}
		}
}
	// If the matrix passes both structural conditions, it is verified as a scalar matrix
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
	bool isScaler = IsScalerMatrix(matrix1);
	cout << "Is Scaler Matrix: " << (isScaler ? "Yes" : "No") << endl;




	
	return 0;

   
}
