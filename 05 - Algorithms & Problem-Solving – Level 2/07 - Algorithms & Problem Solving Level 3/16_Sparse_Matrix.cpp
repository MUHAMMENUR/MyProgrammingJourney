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
 * Checks if the given 3x3 matrix is a Sparse Matrix.
 * @param matrix The 3x3 2D array to evaluate.
 * @return True if the count of zeros outnumbers non-zero elements, otherwise false.
 */
bool IsSparceMatrix(int matrix[3][3]) {
	int ZeroCount = 0;
	int NoneZeroCount = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[i][j] == 0) {
				ZeroCount++;

			}
			else {
				NoneZeroCount++;
			}
				
		}
	}

	// 🌟 Clean Code: Directly return the boolean evaluation of the comparison
	return ZeroCount > NoneZeroCount;
}



int main() {
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator with the current time)
	// Declare a static 3x3 matrix of integers
	int matrix1[3][3];
	
	

	// Step 1: Populate and display the first random matrix
	GenerateRandomMatrix(matrix1);
	cout << "Matrix 1: " << endl;
	PrintMatrix(matrix1);

	// Step 2: Use a clean Ternary Operator to output the result based on function return
	IsSparceMatrix(matrix1) ? cout << "matrix 1 is a sparce matrix." << endl : cout << "Matrix 1 is NOT a sparce matrix." << endl;
	
	return 0;

   
}
