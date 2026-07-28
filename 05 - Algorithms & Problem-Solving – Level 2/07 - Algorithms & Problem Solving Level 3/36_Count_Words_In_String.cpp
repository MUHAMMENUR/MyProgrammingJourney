#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Function: Readstring
 * --------------------
 * Prompts the user to enter a full string/sentence.
 * Uses getline to read the complete input line including spaces.
 * 
 * @return The full text string entered by the user.
 */
string Readstring() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    return input;
}

/**
 * Function: PrintEachWordInString
 * -------------------------------
 * Parses a string using std::string::find and std::string::erase.
 * Prints each word on a new line and calculates the total word count.
 * 
 * @param str The input string to parse and count words from.
 */
void PrintEachWordInString(string str) {
    string delimiter = " ";
    short pos = 0;
    string sWord;
    short Counter = 0; // Word counter initialization

    // Loop through the string while spaces (delimiters) are found
    while ((pos = str.find(delimiter)) != std::string::npos) {
        sWord = str.substr(0, pos); // Extract the word before the space
        
        if (sWord != "") {
            cout << sWord << endl; // Print the extracted word
            Counter++;            // Increment word counter
        }

        // Erase the processed word and its space from the original string
        str.erase(0, pos + delimiter.length());
    }

    // Process the final remaining word left in the string (after the last space)
    if (str != "") {
        cout << str << endl;
        Counter++; // Increment count for the final word
    }

    cout << "\nTotal Words: " << Counter << endl;
}

int main() {
    // Step 1: Read string input from user
    string input = Readstring();

    // Step 2: Extract, print words, and display total count
    PrintEachWordInString(input);

    return 0;
}