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
	int Counter = 0; // Initialize a counter to track matches (not strictly necessary for this implementation)
	

	// Scan through the vector to match against defined vowels
	for (int i = 0; i < Vowel.size(); i++) {
		if(LowerCh==Vowel[i])
		{
			return true;
			
		}
	}
	// Return the count of matched vowels
	return false;
}

/**
 * Function: CountVowels
 * ---------------------
 * Scans the entire string and counts how many vowel letters it contains.
 *
 * @param S The input string to scan.
 * @return Total number of vowels found in the string.
 */
int CountVowels(string S) {
	int VowelCount = 0;
	for (int i = 0; i < S.length(); i++)
	{
		VowelCount += IsVowel(S[i]);
	}
	return VowelCount;
}





int main() {

	
	// Step 1: Read full text line from user
	string InputString = ReadString();
	
	// Step 2: Calculate and output total vowel count
	cout << "Number of vowels in the string: " << CountVowels(InputString) << endl;

	system("pause>0");

	return 0;


}
