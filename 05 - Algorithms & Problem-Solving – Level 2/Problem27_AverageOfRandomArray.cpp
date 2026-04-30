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
// Function to calculate the sum of all elements in the array
int SumOfRandomArray(int Arr[100],int Size){
    int Sum=0;
    for (int i = 0; i < Size; i++)
    {
        Sum+=Arr[i];// Adding each element to the total sum
    }

    return Sum;
}

// Function to calculate the average of all elements in the array
float AverageOfRandomArray(int Arr[100],int Size){

// We use (float) casting to ensure precision in division
float Average=(float)SumOfRandomArray(Arr, Size) /Size;
    return Average;
}

int main(){
    srand((unsigned)time(NULL));

    // Seeds the random number generator
    int Arr[100];
    int Size=ReadPositiveNumber("Please Enter size of array:");
    FillArrayWithRandomNumbers(Arr,Size);
    PrintArray(Arr,Size);
    
    cout<<"\nAverage all number is:";
   cout<<AverageOfRandomArray(Arr,Size);


   

    return 0;
    


}
