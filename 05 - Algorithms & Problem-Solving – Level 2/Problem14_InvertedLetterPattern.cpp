#include <iostream>
#include <string>
using namespace std;

//Function to Read Positive Number
int ReadPositiveNumber(string Message){
    int Number=0;
    do
    {
        cout<<Message;
        cin>>Number;


        
    } while (Number<0);// Repeat if the number is negative
    
return Number;

};
//Function to Print Inverted Letter Pattern
void PrintInvertedLetterPattern(int Number){

    // Outer Loop: Starts from the calculated Letter (e.g., 'C') down to 'A'
    // Formula: 'A' + Number - 1 helps find the target starting letter

    for (char i ='A' + Number - 1;i >='A' ; i--)
    {
        // Inner Loop: Controls how many times the current letter 'i' is printed
        // Logic: (i - 'A') converts the letter's ASCII position into a count (0-indexed)
        for (int j =0 ; j <= (i - 'A'); j++)
        {
            cout<<i;
        }
        // Move to the next line after each letter row
        cout<<endl;
    }
    
}
int main(){
    // 1. Get user input
    int UserNumber=ReadPositiveNumber("Please Enter a positive number:");

// 2. Execute the letter pattern logic
    PrintInvertedLetterPattern(UserNumber);

    return 0;
}