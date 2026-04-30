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
//Function to Print All Digits Frequency
// This function reuses 'CountDigitFrequency' in a loop from 0 to 9
void PrintAllDigitsFrequency(int UserNumber){
    for (int i = 0; i <= 9; i++)
    {
        // Reuse our previous function to check each digit from 0 to 9
        int frequency =CountDigitFrequency(UserNumber,i);
        // Only print if the digit actually exists in the number
        if (frequency>0)
        {
            cout << "Digit " << i << " Frequency is " << frequency << " Time(s).\n";
        }
        
    }

    
}
    
    
    



int main(){
int UserNumber=ReadInformation("Please Enter a positive number:");

PrintAllDigitsFrequency(UserNumber);

}
