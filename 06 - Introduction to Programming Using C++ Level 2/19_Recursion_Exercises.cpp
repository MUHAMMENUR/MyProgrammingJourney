#include <iostream>
using namespace std;


/**
 * 1. Recursive Ascending Print
 * Prints numbers from N up to M.
 * Base Case: Stops when N exceeds M.
 */

void PrintNumbers(int N, int M) {
	if (N <= M)
	{
		cout << N << endl;
		// Recursive Call: Increment N to move towards the Base Case
		PrintNumbers(N + 1, M);
	}
}


/**
 * 2. Recursive Descending Print
 * Prints numbers from M down to N.
 * Base Case: Stops when M becomes less than N.
 */

void PrintNumbers1(int N, int M) {
	if (N<=M)
	{
		cout << M << endl;
		// Recursive Call: Decrement M to move towards the Base Case
		PrintNumbers1(N, M - 1);
	}
}

/**
 * 3. Recursive Power Series Print
 * Uses the built-in pow() function to print powers of A from B down to 0.
 * Base Case: Stops when the Exponent B is less than 0.
 */

void PrintPowNumbers(int A, int B) {
	if (B >= 0) {

		cout << pow(A, B) << endl;
		// Recursive Call: Decrement the exponent
		PrintPowNumbers(A, B - 1);

	}
}

/**
 * 4. Manual Recursive Power Function (The Professional Way)
 * Calculates A raised to the power of B without using cmath.
 * Base Case: Any number raised to 0 is 1.
 * Logic: Returns A multiplied by the result of (A raised to B-1).
 */

int MyPow(int A, int B) {
	if (B==0)
	{
		return 1;
	}
	// This creates layers in the Call Stack until B reaches 0
	return A * MyPow(A, B - 1);
}

int main() {
	// Testing the ascending print from 1 to 30
	PrintNumbers(1, 30);

	// Testing the descending print from 10 down to 1
	PrintNumbers1(1, 10);

	// Printing the power sequence of 2^4, 2^3... down to 2^0
	PrintPowNumbers(2, 4);


	// Calculating and printing a specific power (19^3) using our custom function
	cout << "Result of MyPow(19, 3): " << MyPow(19, 3)<<endl;

	return 0;
	
}