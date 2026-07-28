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
string Readstring() {
	string S;
	cout << "Please Enter Your String: ";
	// Captures the entire line including spaces safely
	getline(cin, S);


	return S;
}

/**
 * Function: CountCapitalLetters
 * -----------------------------
 * Iterates through the string to count all uppercase alphabet characters.
 * @param s The input string to analyze.
 * @return The total number of capital letters.
 */
int CountCapitalLetters(string s) {
	int count = 0;
	// Using a clean range-based for loop to check every character
	for (char c : s) {
		if (isupper(c)) {
			count++;
		}
	}
	return count;
}

/**
 * Function: CountSmallLetters
 * ---------------------------
 * Iterates through the string to count all lowercase alphabet characters.
 * @param s The input string to analyze.
 * @return The total number of small letters.
 */
int CountSmallLetters(string s) {
	int count = 0;
	
	for (char c : s) {
		if (islower(c)) {
			count++;
		}
	}
	return count;
}

/**
 * Function: StringLength
 * ----------------------
 * Manually calculates the total number of characters in the string.
 * @param S The input string.
 * @return The length of the string.
 */
int StringLength(string S) {
	for (int I = 0; I < S.length(); I++) {

		
	}
	return S.length();
}



int main() {

	// Step 1: Call ReadString() to get the full sentence from the user
	string Word = Readstring();
	cout << "You entered " << Word << endl;
	cout << "string length: " << StringLength(Word) << endl;
	cout << "Number of capital letters: " << CountCapitalLetters(Word) << endl;
	cout << "Number of small letters: " << CountSmallLetters(Word) << endl;





	system("pause>0");

	return 0;


}
