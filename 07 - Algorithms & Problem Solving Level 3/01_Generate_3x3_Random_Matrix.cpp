#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * Generates a random integer within a specific range [From, To].
 * 
 * @param From The lower bound of the range.
 * @param To The upper bound of the range.
 * @return A random integer between From and To inclusive.
 */

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

/**
 * Fills a 3x3 matrix with random numbers and prints it in a grid format.
 * 
 * @param matrix The 3x3 2D array to be populated and displayed.
 */
void GenerateRandomMatrix(int matrix[3][3]) {

    for (int i = 0; i < 3; i++) {
        // Loop through each row of the matrix
        for (int j = 0; j < 3; j++) {
            // Generate a random number between 1 and 100
            int Random = RandomNumber(1, 100);
            // Assign the generated random number to the current matrix cell
            matrix[i][j] = Random;

            // Print the current cell followed by a space for alignment
            cout << matrix[i][j] << " ";

        }

        // Print a new line after completing each row to create a 3x3 visual grid

        cout << endl;
    }
}

int main() {
    // Declare a 3x3 matrix of integers
    int MyMatrix[3][3];


    // Seed the random number generator with the current system time
    // This ensures different random numbers are generated on every run
    srand(time(NULL));

    // Call the function to populate and display the matrix
    GenerateRandomMatrix(MyMatrix);
}
