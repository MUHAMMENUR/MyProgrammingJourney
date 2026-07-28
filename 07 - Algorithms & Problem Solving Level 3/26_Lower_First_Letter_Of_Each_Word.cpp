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
string ReadString() {
	string S;
	cout << "Please Enter Your String: ";
	// Captures the entire line including spaces safely
	getline(cin, S);


	return S;
}
/**
 * Iterates through the string and prints the first letter of each word in Lower Case.
 * @param S The target string to process.
 */
void PrintFirstLetterOfEachWord(string S) {
	for (int i = 0; i < S.length(); i++) {
		if (i == 0 || S[i - 1] == ' ') {
			cout << (char)tolower(S[i]) ;
		}
		else {
			cout << S[i];
		}
		

			

	}
}



int main() {

	// Step 1: Read the full string from user input
	string Word = ReadString();



	// Step 2: Extract, and display the first letters
	cout << "\nFirst letters of this string:\n";
	PrintFirstLetterOfEachWord(Word);
	

	


	return 0;

   
}
