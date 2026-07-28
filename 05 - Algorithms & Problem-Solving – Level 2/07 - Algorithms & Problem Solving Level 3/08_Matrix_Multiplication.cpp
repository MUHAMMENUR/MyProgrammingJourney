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
		// Break line after printing all columns of the current row to maintain matrix shape
		cout << endl;
	}
}



/**
 * Prints the 3x3 matrix in a clean grid format.
 * * @param Matrix The 3x3 2D array to be displayed.
 */
void PrintMatrix(int Matrix[3][3]) {
	for (int i = 0; i < 3; i++) {
		// Iterate through rows and columns to display the grid
		for (int j = 0; j < 3; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}



/**
 * Performs standard algebraic Matrix Multiplication (Row x Column).
 * @param matrix1 The first source 3x3 matrix.
 * @param matrix2 The second source 3x3 matrix.
 * @param result The destination 3x3 matrix to store the calculated product.
 */
void MultiplyMatrices(int matrix1[3][3], int matrix2[3][3],int result[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result[i][j] = 0; // Initialize the result cell to zero before summing products]

			// 3rd Loop (k) shifts horizontally across matrix1 and vertically down matrix2
			for (int k = 0; k < 3; k++) {
				result[i][j]+=matrix1[i][k]*matrix2[k][j];
				
			
			}
			
			
		}
		
	}
	
}



int main() {

	// Declare a static 3x3 matrix of integers
	int matrix1[3][3];
	int matrix2[3][3];


		
	
	int Result[3][3] = {0};
	GenerateRandomMatrix(matrix1);
	cout << "Matrix 1: " << endl;
	PrintMatrix(matrix1);
	GenerateRandomMatrix(matrix2);
	cout << "Matrix 2: " << endl;
	PrintMatrix(matrix2);
	MultiplyMatrices(matrix1, matrix2, Result);
	cout << "Result: " << endl;
	PrintMatrix(Result);


	// Step 2: Display the formatted matrix on the screen

	

	return 0;

   
}
