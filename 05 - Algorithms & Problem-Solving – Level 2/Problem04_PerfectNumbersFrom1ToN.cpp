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
// Function to iterate from 1 to N and print only the perfect ones
void Printresult(int number){
    cout << "\nPerfect Numbers from 1 to " <<number << " are: \n";
    
    for (int i = 1; i <=number; i++)
    {
        // We call the previously written function to check each number 'i'
        if (CheckPerfectNumber(i)){
             cout<<i<<" ";
            
        }
            
       
    
    
    }if (number<6)
    {
        cout<<endl;
        cout<<"There is NOT any perfect number.";
    }
    
    cout<<endl;
    

}
int main(){
    int number=ReadInformation("Please Enter number:");
    Printresult(number);
    return 0;
}