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
//Function to Count Digit Frequency
// Takes the main number and the digit we are looking for
int CountDigitFrequency(int number,int targetnumber){
   int count=0,remainder=0;
  
  
   // We use 'while' because we don't know the number of digits in advance
   while (number>0)
   {
    // 1. Get the last digit using Modulo (%) 10
    remainder=number%10;

    // 2. Check if the extracted digit matches our target
if (remainder==targetnumber)
{
    count++;
}


// 3. Remove the last digit to move to the next one
number=number/10;

   
    

    
    
   }
  return count;
   

}


int main(){
   int UserNumber= ReadInformation("Please Enter a positive number:");
   cout<<endl;
int TargetDigit=ReadInformation("Please Enter the digit to check its frequency:");

// Display the final result
  cout << "\nDigit " << TargetDigit << " Frequency is " 
         << CountDigitFrequency(UserNumber, TargetDigit) << " Time(s)." << endl;


   return 0;

}
