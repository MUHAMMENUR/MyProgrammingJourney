#include <iostream>
#include <string>
#include <cstdlib>// Required for rand() and srand() functions
#include <ctime>   // Required for time() function to get system time
using namespace std;

// Enum to make the code more readable
enum EnPrimeNotPrime{prime=2,notprime=1};

//Function to Read Positive Number
int ReadPositiveNumber(string Message){
    int Size=0;
    do
    {
        cout<<Message<<endl;
        cin>>Size;


        
    } while (Size<0);// Repeat if the number is negative
    
return Size;

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
// Function to print all array elements separated by space
void PrintArray(int Arr[100],int Size){
    for (int i = 0; i < Size; i++)
    {
       
        cout<<Arr[i]<<" ";
        
    }
}
int CopyOnlyPrimeNumbers(int Arr[100],int Arr2[100],int Size,int Size2){
    int Counter=0;
    for (int i = 0; i < Size; i++)
    {
        if (CheckPrime(Arr[i])==EnPrimeNotPrime::prime)
        {
            Arr2[Counter]=Arr[i];
            Counter++;
        }
        
    }
    return Counter;
}
void CopyArray(int Arr[100],int Arr2[100],int Size){
    for (int  i = 0; i < Size; i++)
    {
       
       Arr2[i]=Arr[i];
    
    
    }

}
int main(){
    srand((unsigned)time(NULL));

    // Seeds the random number generator
    int Arr[100];
    int Arr2[100];
    int Size=ReadPositiveNumber("Please Enter size of array:");
    // Step 1: Fill and Print the first array
    FillArrayWithRandomNumbers(Arr,Size);
    cout<<"\nArray 1 elements:\n";
    PrintArray(Arr,Size);
   

    int Size2=CopyOnlyPrimeNumbers(Arr,Arr2,Size,Size2);
    cout<<"\nPrime Numbers in Array2:";
    PrintArray(Arr2,Size2);
    return 0;

}