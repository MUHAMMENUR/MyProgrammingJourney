#include <iostream>
#include <cstdlib>
#include <ctime>
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
 * Calculates and prints the sum of each row individually.
 * * @param matrix The 3x3 2D array used to calculate row sums.
 */

void SumOfRaw(int matrix[3][3]) {
    // Loop through each row to calculate its sum separately
    for (int i = 0; i < 3; i++) {
        // Reset the accumulator to 0 for every new row
        int RowSum = 0;
        // Sum all elements in the current row
        for (int j = 0; j < 3; j++) {
            RowSum += matrix[i][j];
        }
     // Print the final sum of the current row (using i + 1 for human-readable 1-based indexing)
     cout << "This is the sum of row " << i + 1 << ": " << RowSum << endl;
    }
    }

int main() {

    // Declare a 3x3 matrix of integers
    int MyMatrix[3][3];
    srand(time(NULL));


    // Step 1: Generate and display the matrix
    GenerateRandomMatrix(MyMatrix);

    // Step 2: Calculate and display the sum of each row below the matrix
    SumOfRaw(MyMatrix);
}
