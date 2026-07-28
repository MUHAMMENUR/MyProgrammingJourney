#include <iostream>
using namespace std;

/**
 * 1. Simple Counter
 * Uses static to keep track of how many times the function was called.
 */
void MyFunc() {
	static int Number = 1; // Initialized only once
	cout << "Value of Number: " << Number << "\n";
	Number++; // Persistent increment
}



/**
 * 2. Sequential Ticket System
 * Simulates a dispenser where the number never resets between calls.
 */
void NextTicket() {
	static int Ticket = 1;// Preserved in static memory
	cout << "Ticket Number: " << Ticket << endl;
	Ticket++;
}


/**
 * 3. Total Accumulator (Savings Box)
 * Adds new input to a persistent sum without using global variables.
 */
void Saving_Box(int Amount) {
	static int Total_Money = 0;// Remembers the previous balance
	Total_Money += Amount; // Accumulation logic

	cout<< "Added: " << Amount << ". Current total savings: " << Total_Money << endl;
}


int main()
{


	// Test: Basic counting (Output: 1, 2, 3)
	MyFunc();
	MyFunc();
	MyFunc();


	// Test: Ticket sequence (Output: 1, 2, 3)
	NextTicket();
	NextTicket();
	NextTicket();

	// Test: Accumulation (Output: 30, then 84)
	Saving_Box(30);
	Saving_Box(54);

	
	


		
	return 0;
}