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
void GenerateRandomMatrix(int matrix[3][3]) {
	// Loop through each column of the current row
	for (int i = 0; i < 3; i++) {
		// Generate a random number between 1 and 100 and assign it to the cell
		for (int j = 0; j < 3; j++) {
			// Generate a random number between 1 and 100 and assign it to the cell
			int Random = RandomNumber(1, 100);
			matrix[i][j] = Random;

			// Print the current element followed by a space
			cout << matrix[i][j] << " ";

		}
		// Break line after printing all columns of the current row to maintain matrix shape
		cout << endl;
	}
}

/**
 * Transposes a 3x3 matrix by swapping its rows with its columns.
 * This function implements a generic mirror-inversion mapping logic.
 * * @param Matrix The original 3x3 source 2D array.
 * @param Tranzpose The destination 3x3 2D array to store the transposed elements.
 */
void TransposeMatrix(int Matrix[3][3],int Tranzpose[3][3]) {
	// Loop through each row
	for (int i = 0; i < 3; i++) {
		// Loop through each column of the current row
		for (int j = 0; j < 3; j++) {

			// Formula: (i * 3) gives the row offset, + j gives column offset, + 1 makes it 1-indexed
			
			Tranzpose[j][i] = Matrix[i][j];
		}
	}
}

/**
 * Prints the 3x3 matrix in a clean grid format.
 * * @param Matrix The 3x3 2D array to be displayed.
 */
void PrintMatrix(int Tranzpose[3][3]) {
	for (int i = 0; i < 3; i++) {
		// Iterate through rows and columns to display the grid
		for (int j = 0; j < 3; j++) {
			cout << Tranzpose[i][j] << " ";
		}
		cout << endl;
	}
}



int main() {

	// Declare a static 3x3 matrix of integers
	int matrix[3][3];
		
	
	int Tranzpose[3][3];
	GenerateRandomMatrix(matrix);
	// Step 1: Fill the matrix with ordered sequential numbers
	TransposeMatrix(matrix, Tranzpose);

	// Step 2: Display the formatted matrix on the screen
	cout << "\nTransposed Matrix:" << endl;
	PrintMatrix(Tranzpose);

	return 0;

   
}
