#include <iostream>
#include <string>
using namespace std;



// Function to read and fill the array from the user
// Note: 'size' is passed by reference (&) to update the original value in main()
void ReadArray(int Arr[100],int& size){
    cout<<"Enter array elements:";
    cin>>size;

    cout<<"\nEnter array elements array:\n";
    for (int i = 0; i <size; i++)
    {
        cout<<"Element["<<i+1<<"]:";
        cin>>Arr[i];
    }
    

}
// Function to count how many times a specific number appears in the array
// Returns the count as an integer for reusability
int CountNumberFrequency(int Arr[100],int size,int NumberToCheck){
    int Counter=0;

    for (int i = 0; i < size; i++)
    {
        if (Arr[i]==NumberToCheck)
        {
            Counter++;
        }
        
    }
    return Counter;
}
void PrintArr(int Arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<Arr[i]<<" ";
    }
    
}
int main(){
    int Arr[100];
    int arraysize=0;
    // 1. Read the array from the user
    ReadArray( Arr,arraysize);
    // 2. Ask for the number to search for
    int NumbrToCheck=0;

    // 3. Print the final result using the returned value
    cout<<"\nEnter The Number you want to check:";
    cin>>NumbrToCheck;

    PrintArr(Arr,arraysize);
    cout<<"\nNumber "<<NumbrToCheck<<" is reapeted ";
    cout<<CountNumberFrequency(Arr,arraysize,NumbrToCheck)<<" time(s)";

    return 0;
    
}