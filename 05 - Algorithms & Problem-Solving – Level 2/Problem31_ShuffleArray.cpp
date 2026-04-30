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

void FillArrayWith1ToN(int Arr[100],int Size){
    for (int i = 0; i < Size; i++)
    {
        Arr[i]=i+1;
    }
    
}
void SheffleArray(int Arr[100],int Size){
    for (int i = 0; i < Size; i++)
    {
        int index1=Getrandom(1,Size)-1;
        int index2=Getrandom(1,Size)-1;

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
    int Arr2[100];
    int Arr3[100];
    int Size=ReadPositiveNumber("Please Enter size of array:");
    // Step 1: Generate and Display Array 1
    FillArrayWith1ToN(Arr,Size);
    cout<<"\nArray 1 elements:\n";
    PrintArray(Arr,Size);
    cout<<"\nArray elements after shuffle:\n";
    SheffleArray(Arr,Size);
    PrintArray(Arr,Size);
   
    

   

  


    return 0;
}