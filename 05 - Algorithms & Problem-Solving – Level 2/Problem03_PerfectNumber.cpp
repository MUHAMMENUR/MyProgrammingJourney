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
//  Check Perfect Number 
bool CheckPerfectNumber(int number){
    int sum=0;
    // Logic: A perfect number is equal to the sum of its divisors (excluding itself)
    // Optimization: We only check up to half the number (number/2)
    for (int i = 1; i <=number/2; i++)
    {
        if (number%i==0)
        {
            sum+=i;

        }
        
    }
    // Return true if sum equals the original number, else false
    return (sum==number);
    
}
// --- Function to Print Results ---
void PrintResult(int number){
   if (CheckPerfectNumber(number))
   {
    cout <<number<< " is a Perfect Number."<<endl;
   }else{
    cout<<number<< " is NOT a Perfect Number."<<endl;
   }
    

}
int main(){
    // Reusability: Using the same function for different variables
   int number1= ReadInformation("Please enter a number to check if it's perfect:");
   int number2=ReadInformation("Please enter a number to check if it's perfect also:");

   PrintResult(number1);
   PrintResult(number2);
   
   return 0;
   
   
   
   
}