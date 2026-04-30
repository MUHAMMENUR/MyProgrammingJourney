#include <iostream>
#include <string>
#include <cstdlib>// Required for rand() and srand() functions
#include <ctime>   // Required for time() function to get system time
using namespace std;

// Enum to make the code more readable
enum EnPrimeNotPrime{prime=2,notprime=1};


//Function to Read Positive Number
int ReadPositiveNumber(){
    int Number=0;
    do
    {
        cout<<"Please Enter Number:";
        cin>>Number;


        
    } while (Number<0);// Repeat if the number is negative
    
return Number;

};

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
//Function to Generate a Random Number within a Range
int Getrandom(int From,int To){
    // Standard Formula: Generates a random number between (From) and (To)
    // rand() % (Range) + Offset
    int RandNum=rand()%(To-From+1)+From;
    return RandNum;

}
// Function to fill the array with random numbers
void FillArrayWithRandomNumbers(int Arr[100],int Size){
    cout<<"Array Elements:";
    for (int i = 0; i < Size; i++)
    {
        Arr[i]=Getrandom(1,100);
       
    }
    
}






/**
 * AddArrayElement:
 * This function adds a new element to the array and updates 
 * the length using 'Pass by Reference' (&Length).
 */

void AddArrayElements(int Number,int Arr[100],int& Length){
    Length++;
    Arr[Length-1]=Number;
    
}

/**
 * CoppyOddNumbers:
 * This acts as a FILTERING ORCHESTRATOR.
 * Logic:
 * 1. Loop through every element in the source array.
 * 2. Apply a CONDITION (Modulo 2).
 * 3. Only if the condition is TRUE, call the Add function for the destination array.
 */
void CoppyOddNumbers(int Arr[100],int Arr2[],int Length,int& Size){
    for (int i = 0; i < Length; i++)
    {
        // IF the current value inside the source array is ODD
        if (CheckPrime(Arr[i])==EnPrimeNotPrime::prime)
        {
            // Reuse the dynamic addition logic
            AddArrayElements(Arr[i],Arr2,Size);
        }else{
            cout<<"There is not any prime number.";
        }
        
    }
    

}


// Function to print all array elements separated by space
void PrintArray(int Arr[100],int Size){
    for (int i = 0; i < Size; i++)
    {
       
        cout<<Arr[i]<<" ";
        
    }
   
    
}




int main(){
    srand((unsigned)time(NULL));
  
    int Length2=0 , Length=0; // Initialize empty array
    int Arr[100];
    int Arr2[100];
    // 1. Initialize Source Data
    Length=ReadPositiveNumber();
    FillArrayWithRandomNumbers(Arr,Length);



    // 2. Perform Intelligent Copying
    // We pass 'Length2' by reference so it grows as we add elements
    CoppyOddNumbers(Arr,Arr2,Length,Length2);
   

// 3. Display Results
cout<<"\nArray 1 elements:\n";
PrintArray(Arr,Length);

cout<<"\nArray 2 prime numbers: \n";
PrintArray(Arr2,Length2);



 


    return 0;
}