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
//Function to Reverse a Number

int ReverseNumber(int number){
   int ReversedNumber=0,remainder=0;
   // We use 'while' because we don't know the number of digits in advance
   while (number>0)
   {
    // 1. Get the last digit using Modulo (%) 10
    remainder=number%10;

// 2. Shift existing digits left and add the new one
    ReversedNumber=ReversedNumber*10 +remainder;

// 3. Delete the last digit from the original number
    number=number/10;
    

    
    
   }
  return ReversedNumber;

}
//Function to Validate Palindrome
// Logic: If original equals reversed, it's a palindrome
bool IsPalindorme(int orginal,int reserve){
   
    return(orginal==reserve);

}
   
        
    
    
  
   




int main(){
   int UserNumber= ReadInformation("Please Enter a positive number:");

int reserve=ReverseNumber(UserNumber);
// Printing the result by calling the function inside the cout
   cout<<"Reverse number is = "<<ReverseNumber(UserNumber)<<endl;
if(IsPalindorme(UserNumber,reserve)){
    cout << "Yes, it is a Palindrome number."<< endl;
}else{
    cout<<"No, İt is not a Palindrome number."<<endl;
}


   return 0;

}
