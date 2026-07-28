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


char ReadChar()
{
	char Ch1;
	cout << "\nPlease Enter a Character?\n";
	cin >> Ch1;
	return Ch1;
}

/**
 * Function: CountLetter
 * ---------------------
 * Scans a string to count occurrences of a specific character.
 * Supports both strict (Case-Sensitive) and flexible (Case-Insensitive) evaluation.
 *
 * @param S1 The source string to analyze.
 * @param Letter The target character to search for.
 * @param MatchCase Flag indicating whether to match exact case (true) or ignore case (false).
 * @return The frequency count of the target character as a short integer.
 */
short CountLetter(string S1, char Letter, bool MatchCase = true) {
	short Counter = 0;
	// Loop through each character of the string using index-based access
	for (short i = 0; i < S1.length(); i++) {

		if (MatchCase) {
			
			// Strict case matching: direct equality check (e.g., 'a' != 'A')
			if (S1[i] == Letter)
				Counter++;
		}
		else {
			// Case-insensitive matching: converts both characters to lowercase before comparison
			if (tolower(S1[i]) == tolower(Letter))
				Counter++;
		}

	}
	return Counter;
}







int main() {

	// Step 1: Call ReadString() to get the full sentence from the user
	string Word = Readstring();
	cout << "You entered " << Word << endl;

	
	// Step 2: Read the target character to count
	char Letter = ReadChar();



	// Step 3: Count occurrences ignoring case sensitivity (MatchCase = false)
	short Count = CountLetter(Word, Letter, false);
	cout << "The letter '" << Letter << "' appears or '"<<toupper(Letter)<<"' " << Count << " times in thestring" << endl;






	// Step 4: Count occurrences with strict case sensitivity (MatchCase = true)
	short Count1 = CountLetter(Word, Letter, true);
	cout << "The letter '" << Letter << "' appears " << Count1 << " times in thestring" << endl;
	

	system("pause>0");

	return 0;


}
