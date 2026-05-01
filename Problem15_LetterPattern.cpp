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
// Function to Print Letter Pattern 
// Example for input 3
// A
// BB
// CCC
void PrintLetterPattern(int Number){
    // Outer Loop: Starts from 'A' and goes up to the character offset by 'Number'
    // Logic: ('A' + Number - 1) gives us the target ending letter

    for (char i = 'A'; i <='A'+Number-1; i++)
    {
        // Inner Loop: Controls how many times the current character 'i' is printed
        // Logic: (i - 'A' + 1) calculates the row number (A=1, B=2, C=3...)

        for (int j = 1; j <=(i-'A'+1) ; j++)
        {
            cout<<i;
        }

        // Move to the next line after finishing the character row
        cout<<endl;
    }
    
}



int main(){
    // 1. Get user input
    int UserNumber=ReadPositiveNumber("Please Enter a positive number:");

// 2. Execute the letter pattern logic
   PrintLetterPattern(UserNumber);

    return 0;
}