#include <iostream>
#include <cmath>
using namespace std;


// Function: Myabs
// Purpose: Calculates the absolute value of a given number.
// Logic: Returns the number if >= 0, otherwise returns (number * -1).
float Myabs(float Number){
    if (Number>=0)
    {
        return Number;
    }else
    {
        return Number*-1;
    }
}

// Function: ReadNumber
// Purpose: Prompts the user to enter a number and returns it.
float ReadNumber(){
    int Number=0;
    cout<<"Please Enter Number: ";
    cin>>Number;
   return Number;

}
    
    


int main(){
    // Read input from the user
    float User=ReadNumber();
    // Display the result of our custom function
    cout<<"My abs result is "<<Myabs(User)<<endl;
    cout<<"C++ abs Result: "<<abs(User)<<endl;

}