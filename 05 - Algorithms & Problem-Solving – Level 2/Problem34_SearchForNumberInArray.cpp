#include <iostream>
#include <string>
#include <cstdlib>// Required for rand() and srand() functions
#include <ctime>   // Required for time() function to get system time
using namespace std;

//Function to Read Positive Number
int ReadPositiveNumber(string Message){
    int Number=0;
    do
    {
        cout<<Message;
        cin>>Number;


        
    } while (Number<0);// Repeat if the number is negative
    
return Number;

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
/**
 * Linear Search Algorithm:
 * Checks each element one by one to find the target number.
 * Returns the index (position) if found, otherwise returns -1.
 */
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
    
    int Size=ReadPositiveNumber("Please Enter the size of array:");

    // Step 1: Initialize the array with random data
    FillArrayWithRandomNumbers(Arr, Size);
    cout<<"Array 1 elements: "<<endl;
    PrintArray(Arr,Size);
    // Step 2: Input the number to search for
    int NumberToSearch;
    cout<<"\nplease Enter a number to search for: ";
    cin>>NumberToSearch;

    // Step 3: Execute the search function
    int index=FindNumberIndex(Arr,Size,NumberToSearch);

    cout << "Number you are looking for is: " << NumberToSearch << endl;


    // Step 4: Handle search results
    if (index == -1) {
        cout << "The number is not found :-(\n";
    } 
    // Display both Zero-based Index and Human-readable Position (Order)
    else {
        cout << "The number is found at position: " << index << endl;
        cout << "The number is found at order: " << index + 1 << endl;
    }
   
    
    
    return 0;
}