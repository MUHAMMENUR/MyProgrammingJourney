#include <iostream>
using namespace std;

// --- Function to Read Data ---
int ReadInformation(string message){
     int number=0;
  do
  {
   
    cout<<message<<endl;
    cin>>number;
    cin.ignore();
    
  } while (number<0);
  return number;
   
    
}
//Function to Calculate Sum of Digits
int SumOfDigits(int number){
   int sum=0,remainder=0;
   // We use 'while' because we don't know the number of digits in advance
   while (number>0)
   {
    // 1. Get the last digit using Modulo (%) 10
    remainder=number%10;
    // 2. Remove the last digit using Integer Division (/) 10
    number=number/10;

    sum+=remainder;
    
   }
  return sum;
   

}


int main(){
   int UserNumber= ReadInformation("Please Enter a positive number:");


// Printing the result by calling the function inside the cout
   cout<<"Sum of digits = "<<SumOfDigits(UserNumber);


   return 0;

}
