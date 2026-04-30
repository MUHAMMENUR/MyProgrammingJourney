#include <iostream>
#include <string>
using namespace std;

//Function to Read Password from User
string ReadPassowrd(string Message){
    string OrginalPassowrd="";
   
        cout<<Message;
        getline(cin,OrginalPassowrd);
        return OrginalPassowrd;

};
//Function to Guess the Password (Brute Force)
void PrintWordsFromAAAtoZZZ(string OrginalPassowrd){
    // Counter is outside to accumulate trials across all loops
    int Counter=0;
// Outer Loop: Represents the first character
    for (char i ='A' ; i <='Z'; i++)
    {
        // Middle Loop: Controls the second character
        for (char j = 'A';  j<='Z'; j++)

        {
            // Inner Loop: Controls the third character (Fastest)
            // This loop completes 26 rotations for every single step of the middle loop.
            for (char k= 'A' ;k <='Z'; k++)
            {
                Counter++;// Increment trials count
                // Reset CurrentPassword inside the inner loop to start fresh every trial
                string CurrentPassowrd="";
                CurrentPassowrd=CurrentPassowrd+i+j+k;
                cout<<"Trial ["<<Counter<<"]:"<<CurrentPassowrd<<endl;

                // Check if the guessed word matches the original password
                if (CurrentPassowrd==OrginalPassowrd)
                {
                    cout <<endl<<"Password is " << CurrentPassowrd << endl;
                    cout << "Found after " << Counter << " Trial(s)" << endl;
                    // Exit the entire function immediately upon finding the password
                    return;
                }
                
                
                
            }
            
        }
                   

    }
}
int main(){
    // 1. Read input
    string UserPassowrd=ReadPassowrd("Please Enter Passowrd:");

    // 2. Start the guessing engine
    PrintWordsFromAAAtoZZZ(UserPassowrd);
    
    return 0;
}