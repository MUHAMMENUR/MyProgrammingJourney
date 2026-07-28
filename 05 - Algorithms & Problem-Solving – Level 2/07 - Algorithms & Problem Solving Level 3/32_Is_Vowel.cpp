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
 * Function: ReadChar
 * ------------------
 * Prompts the user to input a single character from the console.
 *
 * @return The character entered by the user.
 */
char ReadChar()
{
	char Ch1;
	cout << "Please Enter a Character?\n";
	cin >> Ch1;
	return Ch1;
}


/**
 * Function: IsVowel
 * -----------------
 * Evaluates whether a given character is a vowel (a, e, i, o, u).
 * Converts the input to lowercase first to ensure a case-insensitive check.
 *
 * @param Ch The target character to evaluate.
 * @return True if the character matches any vowel, False otherwise.
 */
bool IsVowel(char Ch) {
	// Convert character to lowercase to safely handle both uppercase and lowercase inputs
	char LowerCh= tolower(Ch);

	// Scan through the vector to match against defined vowels
	for (int i = 0; i < Vowel.size(); i++) {
		if(LowerCh==Vowel[i])
		{
			return true;// Match found, return true immediately
		}
	}
	// Return false if no match was found after traversing the full vector
	return false;
}







int main() {

	
	
	// Step 1: Read the target character to count
	char Letter = ReadChar();

	// Step 2: Validate whether the letter is a vowel and display the result
	if (IsVowel(Letter)) {
		cout << "\nYES!Letter '" << Letter << "' is vowel.";
	}
	else {
		cout << "\nNO! Letter '" << Letter << "' is NOT vowel.";
	}


	system("pause>0");

	return 0;


}
