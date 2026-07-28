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


string TrimLeft(string S1) {
	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ') {
			return S1.substr(i, S1.length() - 1);
		}
	}
}


string TrimRight(string S1)
{
	for (short i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}
	}
	return "";
}


string Trim(string S1)
{
	return (TrimLeft(TrimRight(S1)));
}




int main() {

	
	string S1 = " Muhammed Nur Sanda";
	cout << "\nString = " << S1;
	cout << "\n\nTrim Left = " << TrimLeft(S1);
	cout << "\nTrim Right = " << TrimRight(S1);
	cout << "\nTrim = " << Trim(S1);

	return 0;


}
