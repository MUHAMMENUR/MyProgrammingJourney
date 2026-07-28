#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


/**
 * Calculates the Fibonacci number for a given position using Recursion.
 * @param number The position in the sequence (0-indexed).
 * @return The Fibonacci number at the specified position.
 */
int FibonacciSeries(int number) {

	if (number <= 1) {
		return number;
	}


	return FibonacciSeries(number - 1) + FibonacciSeries(number - 2);
	


	}


int main() {
	

	cout << "Fibonacci Series using Recursion: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << FibonacciSeries(i) << " ";
	}



	return 0;

   
}
