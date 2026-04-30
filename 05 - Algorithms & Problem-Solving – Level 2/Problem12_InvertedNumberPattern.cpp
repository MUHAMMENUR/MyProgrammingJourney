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
//  Function to Print Inverted Number Pattern 
// Example for input 3
// 3 3 3
// 2 2
// 1
void PrintInvertedNumberPattern(int Number){
    // Outer Loop: Controls the number of rows (starts from top to 1)
    for (int i =Number ; i>0; i--)
    {
        // Inner Loop: Controls how many times the digit 'i' is printed in each row
        for (int j = i; j>0; j--)
        {
            cout<<i;// Print the current row number
        }
        // After finishing the inner loop, move to the next line
        cout<<endl;
    }
    
}

int main(){
    int UserNumber=ReadPositiveNumber("Please Enter Your Number:");
    PrintInvertedNumberPattern(UserNumber);


}