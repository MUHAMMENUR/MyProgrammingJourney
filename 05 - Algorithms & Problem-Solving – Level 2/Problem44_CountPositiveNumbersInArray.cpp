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

        Arr[i]=Getrandom(-100,100);

       

    }

    

}



void CountPositiveNumbersInArray(int Arr[100],int Size){



    int Count=0;

    for (int i = 0; i < Size; i++){

    {

        if (Arr[i]>0)

        

            Count++;

        

        }

        

    }

   cout<<Count;

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

  

    int  Length=0; // Initialize empty array

    int Arr[100];

 

    Length=ReadPositiveNumber();

    FillArrayWithRandomNumbers(Arr,Length);







    



// 3. Display Results

cout<<"\nArray 1 elements:\n";

PrintArray(Arr,Length);

cout<<"\nPositive Numbers count is:";

CountPositiveNumbersInArray(Arr,Length);

















 





    return 0;

}