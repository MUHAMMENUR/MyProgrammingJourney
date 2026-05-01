#include <iostream>
#include <cmath>
using namespace std;


// Function: getfractionpart
// Purpose: Extracts the decimal part of a number (e.g., 2.7 -> 0.7)

// Function: MyRound
// Purpose: Custom implementation of the round function.
// Logic: If the fractional part is >= 0.5, it increments/decrements the integer part.
float getfractionpart(float Number){
    return Number-int(Number);
}



float MyRound(float Number){
int Inpart;
Inpart=int(Number);
float franctionpart=getfractionpart(Number);
// Using abs() to handle the fractional part comparison for both positive and negative numbers

if (abs(franctionpart)>=0.5)
{// If positive, add 1. If negative, subtract 1 to round away from zero.
    if (Number>0)
    
        return Inpart+1;
    else
        return Inpart-1;

   
    
}else{
    return Inpart;
}
}

// Function: ReadNumber
// Purpose: Prompts the user to enter a floating-point number.
float ReadNumber(){
    float Number=0;
    cout<<"Please Enter Number: ";
    cin>>Number;
    return Number;
}

int main(){
    // 1. Get user input
    float Number=ReadNumber();

    // 2. Display the result of our manual logic
    cout<<"My round is: "<<MyRound(Number)<<endl;

    // 3. Display the result of the standard C++ library function for validation
    cout<<"C++ round is: "<<round(Number);
}

