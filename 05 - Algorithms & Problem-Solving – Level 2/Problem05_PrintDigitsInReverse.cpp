#include <iostream>
using namespace std;

// --- Function to Read Data ---
int ReadInformation(string message){
     int number=0;
  do
  {
   
    cout<<message<<endl;
    cin>>number;
    
  } while (number<0);
  return number;
   
    
}
//Function to Extract and Print Digits in Reverse
void PrintDigitsInReverse(int number){
   int remainder=0;
   // We use 'while' because we don't know the number of digits in advance
   while (number>0)
   {
    // 1. Get the last digit using Modulo (%) 10
    remainder=number%10;
    // 2. Print the extracted digit
    cout<<remainder<<endl;
    // 3. Remove the last digit using Integer Division (/) 10
    number=number/10;
   }
   

}

int main(){
   int UserNumber= ReadInformation("Please Enter a positive number:");

   PrintDigitsInReverse(UserNumber);


   return 0;

}
