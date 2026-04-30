#include <iostream>
#include <string>
#include <cstdlib>// Required for rand() and srand() functions
#include <ctime>   // Required for time() function to get system time
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
//Function to Generate a Random Number within a Range
int Getrandom(int From,int To){
    // Standard Formula: Generates a random number between (From) and (To)
    // rand() % (Range) + Offset
    int RandNum=rand()%(To-From+1)+From;
    return RandNum;

}
// Function to generate a single word (4 random uppercase letters)
string GenerateWord(){
    string word="";
    for (int i = 0; i < 4; i++)
    {
        // ASCII range for 'A' (65) to 'Z' (90)
        word=word+char(Getrandom(65,90));
    }
    return word;

}
// Function to generate a full key (4 blocks of words separated by hyphens)
// Example: AAAA-BBBB-CCCC-DDDD
string GenerateKey(){
    string Key="";
    for (int i = 1; i <=4; i++)
    {
        Key=Key+GenerateWord();
        // Add hyphen between blocks, except after the last block
        if (i<4)
        {
            Key=Key+"-";
        }
        
    }
    return Key;
    
}
// Function to print a specified number of keys
void GetGeneratekeys(int Number){
    for (int i = 1; i <=Number; i++)
    {
        cout<<"Key ["<<i<<"]: "<<GenerateKey()<<endl;
    }
    
}


int main(){
    // Seeds the random number generator with current system time
    srand((unsigned)time(NULL));
    // Input: How many keys to generate
    int SumOfNumber=ReadPositiveNumber("Please Enter How Many keys do yo want:");
    // Logic & Output: Generate and print the keys
    GetGeneratekeys(SumOfNumber);
    return 0;
}