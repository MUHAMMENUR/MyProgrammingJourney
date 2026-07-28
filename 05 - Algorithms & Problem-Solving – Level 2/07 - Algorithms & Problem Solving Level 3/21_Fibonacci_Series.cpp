#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


/**
 * Prints the Fibonacci series up to a specified number of elements.
 * @param number The count of Fibonacci numbers to generate and display.
 */
void FibonacciSeries(int number) {
	int NextFib = 0;
	int Fib1 = 0;
	int Fib2 = 1;
	for (int i = 0; i < number; i++) {
		cout << Fib1 << " ";
		NextFib = Fib1 + Fib2;
		Fib1 = Fib2;
		Fib2 = NextFib;


	}
}



int main() {
	// Step 1: Execute the Fibonacci generator for the first 13 elements
	FibonacciSeries(13);
	return 0;

   
}
