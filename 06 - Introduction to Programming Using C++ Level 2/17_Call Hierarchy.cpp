#include <iostream>
using namespace std;

// --- Call Stack Demonstration ---

// This function will be at the TOP of the Stack
void Function4()
{
    cout << "Hi I'm function4 " << endl;
}

// Function3 calls Function4 (Function4 is pushed onto the stack)
void Function3()
{
    Function4();
}

// Function2 calls Function3 (Function3 is pushed onto the stack)
void Function2()
{
    Function3();
}

// Function1 calls Function2 (Function2 is pushed onto the stack)
void Function1()
{
    Function2();
}

// The execution starts here. main() is the BOTTOM of the stack
int main() {
    
    // Starting the chain of calls
    Function1();

    /* 
       How the Call Stack looks when Function4 is executing:
       1. Function4() <- (Current Top)
       2. Function3()
       3. Function2()
       4. Function1()
       5. main()      <- (Bottom)
    */

    return 0;
}