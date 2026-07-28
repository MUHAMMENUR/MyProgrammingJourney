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
 * Function: SplitString
 * ---------------------
 * Splits a full string into individual word tokens based on a delimiter (default space).
 * Accumulates characters until a space is met, then pushes the word into a vector.
 *
 * @param InputString The full sentence to be split.
 * @param Delim The character delimiter used for splitting (defaults to " ").
 * @return A vector of strings containing all extracted word tokens.
 */
vector<string> SplitString(string InputString, string Delim = " ") {
	vector<string> vTokens;
	string word = "";
	cout << "Words in string are:" << endl;
	
	short Counter = 0;
	// Iterate through every character in the string
	for (char c : InputString) {
		if (c == ' ') {
			// Print the accumulated word when a delimiter (space) is met
			if (!word.empty()) {
				vTokens.push_back(word);
				word.clear();// Reset accumulator for the next word
				Counter++;// Increment word count
			}
		}
		else {
			word += c;// Build the word character by character
		}
	}
	if (!word.empty()) {
		vTokens.push_back(word);

		Counter++;// Increment for the last word if it exists
	}
	cout << "Total number of words: " << Counter << endl;
	return vTokens;
}







int main() {

	
	// Step 1: Read full text line from user
	string InputString = ReadString();

	vector<string> vTokens = SplitString(InputString);

	for (string& Word : vTokens) {
		cout << Word << endl;
	}


	system("pause>0");

	return 0;


}
