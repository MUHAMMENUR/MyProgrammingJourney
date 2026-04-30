#include <iostream>
#include <string>
using namespace std;

//Function to Read Positive Number
int ReadPositiveNumber(string Message){
    int Number=0;
    do
    {
        cout<<Message<<endl;
        cin>>Number;


        
    } while (Number<0);// Repeat if the number is negative
    
return Number;

};
// Function to Print Number Pattern
// Logic: Prints an ascending triangle pattern (1, 22, 333, ...)

void PrintNumberPattern(int Number){
    // Outer Loop: Controls the number of rows (from 1 to the given Number)
    for (int i = 1; i <=Number; i++)
    {
        // Inner Loop: Controls how many times the digit 'i' is printed in the current row
        // Notice: The condition (j <= i) creates the triangle shape.
        for (int j = 1; j <=i ; j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
    
}
int main(){
    // 1. Get input from user
    int UserNumber=ReadPositiveNumber("Please Enter a positive number:");

    // 2. Call the function to display the pattern
    PrintNumberPattern(UserNumber);
}