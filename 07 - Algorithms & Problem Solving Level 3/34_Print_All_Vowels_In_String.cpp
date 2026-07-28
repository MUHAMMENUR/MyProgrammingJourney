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
 * Function: PrintLetterOfVowels
 * -----------------------------
 * Scans the entire string and prints out each vowel letter found.
 *
 * @param S The input string to analyze and display vowels from.
 */
void PrintLetterOfVowels(string S) {
	int VowelCount = 0;
	for (int i = 0; i < S.length(); i++)
	{
		if(IsVowel(S[i]))
		{
			cout << S[i] << " ";
		}
	}
	
}





int main() {

	
	// Step 1: Read full text line from user
	string InputString = ReadString();

	// Step 2: Print all vowels present in the input sentence
	cout << "Voles in string are:" << endl;
	PrintLetterOfVowels(InputString);

	system("pause>0");

	return 0;


}
