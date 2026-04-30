#include <iostream>
#include <cmath>
using namespace std;

int Mysquare(float Number){
   return  pow(Number,0.5);
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
    float Number=ReadNumber();
    
     //2. Display the result of our manual logic
    cout<<"My square is: "<<Mysquare(Number)<<endl;

     // 3. Display the result of the standard C++ library function for validation
    cout<<"C++ square is: "<<sqrt(Number);
}