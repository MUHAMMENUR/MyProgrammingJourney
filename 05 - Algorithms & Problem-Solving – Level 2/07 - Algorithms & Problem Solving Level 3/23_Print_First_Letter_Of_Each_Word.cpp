#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;


string ReadString() {
	string S;
	cout << "Please Enter Your String: ";
	getline(cin, S);


	return S;
}

void PrintFirstLetterOfEachWord(string S) {
	for (int i = 0; i < S.length(); i++) {
		if (i == 0 || S[i - 1] == ' ') {
			cout << S[i] << " ";
		}
		

			

	}
}



int main() {


	string Word = ReadString();
	PrintFirstLetterOfEachWord(Word);
	

	


	return 0;

   
}
