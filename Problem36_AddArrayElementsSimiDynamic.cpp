#include <iostream>
#include <string>
#include <cstdlib>// Required for rand() and srand() functions
#include <ctime>   // Required for time() function to get system time
using namespace std;


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
 * InputUserNumberInArrays:
 * Orchestrates the process of adding elements until the user stops.
 */
void InputUserNumberInArrays(int Arr[100],int& Length){
    bool Addmore=0;

    do
    {
        // We pass the result of ReadNumber directly to AddArrayElement
        AddArrayElements(ReadPositiveNumber(),Arr,Length);
     cout<<"Do you want to add number [0]NO,[1] YES? ";
     cin>>Addmore;
     
     

    } while (Addmore);
    
}



void PrintArray(int Arr[100],int Size){
    for (int i = 0; i < Size; i++)
    {
       
        cout<<Arr[i]<<" ";
        
    }
   
    
}



int main(){
    // Seeds the random number generator with current system time
    srand((unsigned)time(NULL));
    // Input: How many keys to generate

    int Arr[100];
    
   
    int Length=0; // Initialize empty array

    // Call the master function to handle inputs
    InputUserNumberInArrays(Arr,Length);

    cout<<"\nArray Length: "<<Length<<endl;
    cout<<"Array Elemetns: ";
    PrintArray(Arr,Length);
    
    

    
    
    return 0;
}