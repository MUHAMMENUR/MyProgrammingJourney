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




void PrintMatrix(int Matrix[3][3]) {
	for (int i = 0; i < 3; i++) {
		
		for (int j = 0; j < 3; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}


/**
 * Prints the middle row of a 3x3 matrix (Row index 1).
 * @param matrix The 3x3 2D array to extract the row from.
 */
void PrintMiddleRow(int matrix[3][3]) {
	cout << "Middle Row of this matrix is:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << matrix[1][i] << " ";
	}
	cout << endl;
}


/**
 * Prints the middle column of a 3x3 matrix (Column index 1).
 * @param matrix The 3x3 2D array to extract the column from.
 */
void PrintMiddleColumn(int matrix[3][3]) {
	cout << "Middle Column of this matrix is: " << endl;
	for (int i = 0; i < 3; i++) {
		cout << matrix[i][1] << " ";
	}
	cout << endl;
}



int main() {
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator with the current time)
	// Declare a static 3x3 matrix of integers
	int matrix1[3][3];
	


	// Step 1: Populate the matrix with random integers
	GenerateRandomMatrix(matrix1);
	cout << "Matrix 1: " << endl;
	// Step 2: Display the full initial matrix
	PrintMatrix(matrix1);


	// Step 3: Extract and print the middle row
	PrintMiddleRow(matrix1);

	// Step 4: Extract and print the middle column
	PrintMiddleColumn(matrix1);	

	

		
	
	

	

	return 0;

   
}
