#include <iostream>
#include <cstdlib>// Required for rand() and srand() functions
#include <ctime>   // Required for time() function to get system time
using namespace std;



//Function to Generate a Random Number within a Range
int PrintRandomNumbersFrom1To10(int From,int To){
    // Standard Formula: Generates a random number between (From) and (To)
    // rand() % (Range) + Offset
    int RandNum=rand()%(To-From+1)+From;
    return RandNum;

}

int main(){
    //Seeds the Random Number Generator
    // We use time(NULL) to get a different 'seed' every second
    // This ensures that the numbers are truly different every time the program runs.
    srand((unsigned)time(NULL));
cout<< PrintRandomNumbersFrom1To10(1,21)<<endl;
cout<< PrintRandomNumbersFrom1To10(1,21)<<endl;
cout<< PrintRandomNumbersFrom1To10(1,21)<<endl;
cout<< PrintRandomNumbersFrom1To10(1,21)<<endl;
cout<< PrintRandomNumbersFrom1To10(1,21)<<endl;

return 0;


}