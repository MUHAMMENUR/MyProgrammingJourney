#include <iostream>
#include <string>
#include <cstdlib>// Required for rand() and srand() functions
#include <ctime>   // Required for time() function to get system time
using namespace std;



void FillArray(int Arr[100], int &arrLength)
{
   arrLength = 6; 
    Arr[0] = 10;
    Arr[1] = 20;
    Arr[2] = 30;
    Arr[3] = 30;
    Arr[4] = 20;
    Arr[5] = 10;
}

void PrintArray(int Arr[100],int Size){
    for (int i = 0; i < Size; i++)
    {
       
        cout<<Arr[i]<<" ";
        
    }
   
    
}





bool IsPalindromeArray(int Arr[100],int Length  ){
    for (int i = 0; i < Length; i++)
    {
        if (Arr[i]!=Arr[(Length-i-1)])
        {
            return false;
        }
        
    }
    return true;
    

}



int main(){
    // Seeds the random number generator with current system time
    srand((unsigned)time(NULL));
    // Input: How many keys to generate

    int Arr[100];
   
    
    int Size=0;
    

    // Step 1: Initialize the array with random data
    
    cout<<"Array 1 elements: "<<endl;
    FillArray(Arr,Size);
    PrintArray(Arr,Size);

if (IsPalindromeArray(Arr,Size))
{
    cout<<"\nYes it is a palindrome Array."<<endl;
}else{
    cout<<"\nNo it is not a palindrome Array."<<endl;
}



    return 0;

}