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
  * Converts the entire string to Lowercase and prints it.
  * @param S The target string to process.
  */
void PrintLower(string S) {
	for (int i = 0; i < S.length(); i++) {
		S[i] = tolower(S[i]);
		cout << S[i]; 



	}
}

/**
 * Converts the entire string to Uppercase and prints it.
 * @param S The target string to process.
 */
void PrintUpper(string S) {
	for (int i = 0; i < S.length(); i++) {
		S[i] = toupper(S[i]);
		cout << S[i];
	}
}



int main() {

	// Step 1: Read the full string from user input
	string Word = ReadString();



	// Step 2: Convert to Upper and print
	cout << "\nString after Upper:\n";
	PrintUpper(Word);


	// Step 3: Convert to Lower and print
	cout << "\nString after Lower:\n";
	PrintLower(Word);




	return 0;

}
