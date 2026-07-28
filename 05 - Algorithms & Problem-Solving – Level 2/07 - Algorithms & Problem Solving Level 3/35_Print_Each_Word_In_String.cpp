#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// Vector containing all standard vowel characters
// Defined globally or within the function for comparison
vector <char> Vowel = { 'a', 'e', 'i', 'o', 'u' };



/**
 * Function: ReadString
 * --------------------
 * Prompts the user to input a full sentence.
 * @return The complete string input.
 */
string ReadString() {
	string Input;
	cout << "Enter a string: ";
	getline(cin,Input);
	return Input;
}

/**
 * Function: PrintWord
 * -------------------
 * Parses an input string and prints each word on a new line.
 * Handles trailing words and prevents empty lines caused by consecutive spaces.
 *
 * @param InputString The full sentence to break down into words.
 */
void PrintWord(string InputString) {
	cout << "Words in string are:" << endl;
	string word = "";
	// Iterate through every character in the string
	for (char c : InputString) {
		if (c == ' ') {
			// Print the accumulated word when a delimiter (space) is met
			if (!word.empty()) {
				cout << word << endl;
				word.clear();// Reset accumulator for the next word
			}
		}
		else {
			word += c;// Build the word character by character
		}
	}
	if (!word.empty()) {
		cout << word << endl;
	}
}







int main() {

	
	// Step 1: Read full text line from user
	string InputString = ReadString();



	// Step 2: Extract and display each word independently
	PrintWord(InputString);


	system("pause>0");

	return 0;


}
