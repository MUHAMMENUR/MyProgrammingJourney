#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

/**
 * Prompts the user to input a full line of text.
 * @return The complete string entered by the user.
 */
char ReadChar() {
	char S;
	cout << "Please Enter Your String: ";
	// Captures the entire line including spaces safely
	cin >> S;


	return S;
}


char InvertCase(char C) {
	return islower(C) ? toupper(C) : tolower(C);
}



int main() {

	// Step 1: Read the full string from user input
	char Word = ReadChar();
	cout << "You entered " << Word << endl;
	cout << "The Inverted case of the charecter is: " << InvertCase(Word) << endl;





	system("pause>0");

	return 0;


}
