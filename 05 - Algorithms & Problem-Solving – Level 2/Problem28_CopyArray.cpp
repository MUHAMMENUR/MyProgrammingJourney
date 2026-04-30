#include <iostream>
#include <string>
#include <cstdlib>// Required for rand() and srand() functions
#include <ctime>   // Required for time() function to get system time
using namespace std;

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
// Function to copy elements from Source array to Destination array
// Note: Arrays are passed by reference, so changes here affect the original arrays in main
void CopyArray(int Arr[100],int Arr2[100],int Size){
    for (int i = 0; i < Size; i++)
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
    
    // Step 2: Copy Arr1 to Arr2 (Process happens in memory)
    CopyArray(Arr,Arr2,Size);
    // Step 3: Print the second array to verify the copy process
    cout<<"\n\nArray 2 elements:\n";
    PrintArray(Arr2,Size);


    return 0;
}