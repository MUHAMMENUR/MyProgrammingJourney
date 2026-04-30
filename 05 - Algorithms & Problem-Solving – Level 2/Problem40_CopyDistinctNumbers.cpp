#include <iostream>
#include <string>
#include <cstdlib>// Required for rand() and srand() functions
#include <ctime>   // Required for time() function to get system time
using namespace std;



void FillArray(int Arr[100], int &arrLength)
{
    arrLength = 10;  // Set the array length to 10 elements.
    
    // Manually assign values to the array elements.
    Arr[0] = 10;
    Arr[1] = 10;
    Arr[2] = 10;
    Arr[3] = 50;
    Arr[4] = 50;
    Arr[5] = 70;
    Arr[6] = 70;
    Arr[7] = 70;
    Arr[8] = 70;
    Arr[9] = 90;
}

void PrintArray(int Arr[100],int Size){
    for (int i = 0; i < Size; i++)
    {
       
        cout<<Arr[i]<<" ";
        
    }
   
    
}

int FindNumberIndex(int Arr[100],int Size,int NumberToSearch){
   
    for (int i = 0; i < Size; i++)
    {
        if (Arr[i]==NumberToSearch)
        {
            return i; // Found: Return the index immediately

            
        }
          
        
        
    }
    return -1; // Not Found: After checking all elements
}


// Function: IsNumberInArray
// Purpose: Determines if a given number exists in the array.
// Parameters:
//   - Number: The number to search for.
//   - arr: The array to search in.
//   - arrLength: The number of elements in the array.
// Returns: true if the number is found; false otherwise.
bool IsNumberInArray(int Arr[100],int Size,int NumberToSearch){

    // Use FindNumberPositionInArray and check if the result is not -1.

    return FindNumberIndex(Arr,Size,NumberToSearch)!=-1;
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


void CopyDistinctNumbersToArray(int Arr[100],int Arr2[100],int& Length,int& Length2){
    for (int i = 0; i < Length; i++)
    {
        if (!IsNumberInArray(Arr2, Length2, Arr[i]))
        {
            AddArrayElements(Arr[i],Arr2,Length2);
        }
        
    }
    
}








int main(){
    // Seeds the random number generator with current system time
    srand((unsigned)time(NULL));
    // Input: How many keys to generate

    int Arr[100];
    int Arr2[100];
    
    int Size=0;
    int Size2=0;

    // Step 1: Initialize the array with random data
    
    cout<<"Array 1 elements: "<<endl;
    FillArray(Arr,Size);
    PrintArray(Arr,Size);


    CopyDistinctNumbersToArray(Arr,Arr2,Size,Size2);

    cout<<"\nArray 2 ditinct elements:\n";
    PrintArray(Arr2,Size2);
   
    
    
    
    return 0;
}