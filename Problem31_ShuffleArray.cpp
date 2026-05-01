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
/**
 * Standard Swap function using a reference and a temporary variable
 * This is the engine of the shuffle process
 */
void Swap(int& Num,int& Num2){
    int Temp;
    Temp=Num;
    Num=Num2;
    Num2=Temp;

}
//Function to Generate a Random Number within a Range
int Getrandom(int From,int To){
    // Standard Formula: Generates a random number between (From) and (To)
    // rand() % (Range) + Offset
    int RandNum=rand()%(To-From+1)+From;
    return RandNum;

}

/**
 * Fills the array with an ordered sequence from 1 to N
 * For example: if Size = 5, Array will be [1, 2, 3, 4, 5]
 */
void FillArrayWith1ToN(int Arr[100],int Size){
    for (int i = 0; i < Size; i++)
    {
        Arr[i]=i+1;
    }
    
}

/**
 * CORE LOGIC: Shuffles the array elements randomly
 * Process: For each element, pick two random positions and swap their values
 * This mimics the "shuffling a deck of cards" effect
 */
void SheffleArray(int Arr[100],int Size){
    for (int i = 0; i < Size; i++)
    {
        int index1=Getrandom(1,Size)-1;
        int index2=Getrandom(1,Size)-1;
       // Swap elements at the generated random positions
        Swap(Arr[index1],Arr[index2]);
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

    // Seeds the random number generator
    int Arr[100];
    
    int Size=ReadPositiveNumber("Please Enter size of array:");
   // Step 1: Initialize the array with ordered numbers
    FillArrayWith1ToN(Arr,Size);
    cout<<"\nArray 1 elements:\n";
    PrintArray(Arr,Size);
    

    // Step 2: Apply the shuffle logic
    SheffleArray(Arr,Size);


    // Step 3: Display the shuffled array
    cout<<"\nArray elements after shuffle:\n";
    PrintArray(Arr,Size);
   
    

   

  


    return 0;
}