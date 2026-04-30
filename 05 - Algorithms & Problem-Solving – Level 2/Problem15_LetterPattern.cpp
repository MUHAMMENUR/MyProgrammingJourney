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

void PrintLetterPattern(int Number){
    for (char i = 'A'; i <='A'+Number-1; i++)
    {
        for (int j = 1; j <=(i-'A'+1) ; j++)
        {
            cout<<i;
        }
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