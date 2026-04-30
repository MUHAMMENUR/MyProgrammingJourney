#include <iostream>
using namespace std;
// Enum to make the code more readable
enum EnPrimeNotPrime{prime=2,notprime=1};
// Function to read a positive number from the user
int ReadInformation(string message){
     int number=0;
  do
  {
   
    cout<<message<<endl;
    cin>>number;
    
  } while (number<0);
  return number;
   
    
}
EnPrimeNotPrime CheckPrime(int number){
    // 1 and numbers less than 1 are NOT prime
    if (number<=1)
    
       return EnPrimeNotPrime::notprime;
    // 2 is the ONLY even prime number
    if (number==2)
        return EnPrimeNotPrime::prime;
    // Loop from 2 to half of the number to check for divisors
    for (int i = 2; i <=number/2; i++)
    {
        if (number%i==0)
        {
            return EnPrimeNotPrime::notprime;
        }
        
    }
    
return EnPrimeNotPrime::prime;


}
void PrintInformation(int number){
    cout << "\nPrime Numbers from 1 to " << number << " are: \n";
    for (int i = 1; i <=number; i++)
    {// Call CheckPrime for each number 'i'
        if (CheckPrime(i)==EnPrimeNotPrime::prime)
        {
            cout<<i<<" ";
        }
       
    }
    
 cout<<endl;
}
    
        
  
int main(){
  int user=ReadInformation("Please Enter number to find sum of the prime number: ");
  PrintInformation(user);
  
}
