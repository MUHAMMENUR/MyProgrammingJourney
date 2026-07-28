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

short CountLetter(string S1, char Letter)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Letter)
			Counter++;
	}
	return Counter;
}








int main() {

	// Step 1: Call ReadString() to get the full sentence from the user
	string Word = Readstring();
	cout << "You entered " << Word << endl;
	char Letter = ReadChar();
	short Count = CountLetter(Word, Letter);
	cout << "The letter '" << Letter << "' appears " << Count << " times in thestring" << endl;

	
	




	system("pause>0");

	return 0;


}
