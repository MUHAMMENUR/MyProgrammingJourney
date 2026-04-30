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
void FillArrayWithRandomNumbers(int Arr[100],int Size){
    cout<<"Array Elements:";
    for (int i = 0; i < Size; i++)
    {
        Arr[i]=Getrandom(1,100);
    }
    
}
void PrintArray(int Arr[100],int Size){
    for (int i = 0; i < Size; i++)
    {
        cout<<Arr[i]<<" ";
    }
    
}

int main(){
    int Arr[100];
    srand((unsigned)time(NULL));
    int Size=ReadPositiveNumber("Please Enter size of array");
    FillArrayWithRandomNumbers(Arr,Size);
    PrintArray(Arr,Size);

}
