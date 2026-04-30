#include <iostream>

using namespace std;


void PrintWordsFromAAAtoZZZ(){
    // Outer Loop: Controls the first character (Slowest)
    for (char i ='A' ; i <='Z'; i++)
    {
        // Middle Loop: Controls the second character
        for (char j = 'A';  j<='Z'; j++)

        {
            // Inner Loop: Controls the third character (Fastest)
            // This loop completes 26 rotations for every single step of the middle loop.
            for (char k= 'A' ;k <='Z'; k++)
            {
                cout<<i<<j<<k<<endl;
                
            }
            
        }
                   

    }
    
}
int main(){
    PrintWordsFromAAAtoZZZ();
}