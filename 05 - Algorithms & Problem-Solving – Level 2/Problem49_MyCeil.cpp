#include <iostream>
#include <cmath>
using namespace std;


float getfractionpart(float Number){
    return Number-int(Number);
}


int MyCeil(float Number){

    if (abs(getfractionpart(Number))>0)
    {
        if (Number>0)
   
        return int(Number)+1;
    else
        return int(Number);
    
    }else{
        return Number;
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
    float Number=ReadNumber();
    //2. Display the result of our manual logic
    cout<<"My Ceil is: "<<MyCeil(Number)<<endl;

     // 3. Display the result of the standard C++ library function for validation
    cout<<"C++ Ceil is: "<<ceil(Number);
}
