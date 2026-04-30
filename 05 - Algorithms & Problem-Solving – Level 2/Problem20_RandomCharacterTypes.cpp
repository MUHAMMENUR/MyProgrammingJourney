#include <iostream>
#include <cstdlib>// Required for rand() and srand() functions
#include <ctime>   // Required for time() function to get system time
using namespace std;
// Enumeration for character types to make the code more readable
enum enRand{
    Upper_Case=1,
    Lower_Case=2,
    SpechialCharecter=3,
    Digit=4,

};


//Function to Generate a Random Number within a Range
int Getrandom(int From,int To){
    // Standard Formula: Generates a random number between (From) and (To)
    // rand() % (Range) + Offset
    int RandNum=rand()%(To-From+1)+From;
    return RandNum;

}
// Function to get a random character based on the passed enCharType
char GetRandomCharacter(enRand CharType){
    switch (CharType )
    {
    case enRand::Upper_Case:
    // ASCII Range for 'A'-'Z' is 65-90
       return char(Getrandom(65,90));
        break;
    // ASCII Range for 'a'-'z' is 97-122
    case enRand::Lower_Case:
   return char(Getrandom(97,122));
        break;
    // ASCII Range for some special characters
    case enRand::SpechialCharecter:
    return char(Getrandom(33,47));
    break;
    // ASCII Range for '0'-'9' is 48-57
    case enRand::Digit:
    return char(Getrandom(48,57));
    break;
    // Safety return
   default:
  return 'a';
   
    }
    
}
int main(){
    srand((unsigned)time(NULL));
    cout<<GetRandomCharacter(enRand::Upper_Case)<<endl;
    cout<<GetRandomCharacter(enRand::Lower_Case)<<endl;
    cout<<GetRandomCharacter(enRand::SpechialCharecter)<<endl;
    cout<<GetRandomCharacter(enRand::Digit)<<endl;

        


}