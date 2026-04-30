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
void SumOfArrays(int Arr[100],int Arr2[100],int Arr3[100],int Size){
    for (int i = 0; i < Size; i++)
    {
        Arr3[i]=Arr[i]+Arr2[i];
    }
    
}




int main(){
    srand((unsigned)time(NULL));

    // Seeds the random number generator
    int Arr[100];
    int Arr2[100];
    int Arr3[100];
    int Size=ReadPositiveNumber("Please Enter size of array:");
    // Step 1: Fill and Print the first array
    FillArrayWithRandomNumbers(Arr,Size);
    cout<<"\nArray 1 elements:\n";
    PrintArray(Arr,Size);
   
    cout<<"\n\nArray 2 elements:\n";
    FillArrayWithRandomNumbers(Arr2,Size);
    PrintArray(Arr2,Size);

    SumOfArrays(Arr,Arr2,Arr3,Size);
    cout<<"\nSum of Array1 and Array2 elements:";
    PrintArray(Arr3,Size);


    return 0;
}