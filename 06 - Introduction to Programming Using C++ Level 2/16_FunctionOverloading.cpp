#include <iostream>
#include <string>

using namespace std;

// --- Summation Functions (Overloaded by number and type of parameters) ---

// Sum of two double precision numbers
double MySum(double a, double b) {
    return (a + b);
}

// Sum of two integers
int MySum(int a, int b) {
    return (a + b);
}

// Sum of three integers
int MySum(int a, int b, int c) {
    return (a + b + c);
}

// Sum of four integers
int MySum(int a, int b, int c, int d) {
    return (a + b + c + d);
}

// --- Area Calculation Functions ---

// Calculate Circle Area: PI * r^2
double CalculateArea(double r) {
    return (3.14 * r * r);
}

// Calculate Rectangle Area: Length * Width
double CalculateArea(double L, double W) {
    return (L * W);
}

// --- Max Value Functions (Comparison Logic) ---

// Returns the greater of two integers
int GetMax(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the greater of two double numbers
double GetMax(double a, double b) {
    return (a > b) ? a : b;
}

// Returns the greatest among three integers using nested ternary operators
int GetMax(int a, int b, int c) {
    return (a > b && a > c) ? a : (b > c) ? b : c;
}

// --- Information Printing Functions (Overloaded by data type) ---

// Returns Name as a string
string PrintInfo(string Name) {
    return Name;
}

// Returns Age as an integer
int PrintInfo(int Age) {
    return Age;
}

// Returns Academic Grade as a character
char PrintInfo(char Degree) {
    return Degree;
}

int main() {
    // Testing Summation Overloading
    cout << "--- Summation Tests ---" << endl;
    cout << "Sum (int, int): " << MySum(10, 20) << endl;
    cout << "Sum (double, double): " << MySum(10.1, 20.1) << endl;
    cout << "Sum (3 ints): " << MySum(10, 20, 30) << endl;
    cout << "Sum (4 ints): " << MySum(10, 20, 30, 40) << endl;

    cout << endl;

    // Testing Area Overloading
    cout << "--- Area Tests ---" << endl;
    cout << "Circle Area (r=2.0): " << CalculateArea(2.0) << endl;
    cout << "Rectangle Area (12.12x12.12): " << CalculateArea(12.12, 12.12) << endl;

    cout << endl;

    // Testing Max Value Overloading
    cout << "--- Max Value Tests ---" << endl;
    cout << "Max of (90, 98): " << GetMax(90, 98) << endl;
    cout << "Max of (80.32, 78.43): " << GetMax(80.32, 78.43) << endl;
    cout << "Max of (12, 87, 90): " << GetMax(12, 87, 90) << endl;

    cout << endl;

    // Testing PrintInfo Overloading
    cout << "--- Info Printing Tests ---" << endl;
    cout << "Student Name: " << PrintInfo("Muhammed") << endl;
    cout << "Student Age: " << PrintInfo(12) << endl;
    cout << "Current Grade: " << PrintInfo('A') << endl;

    return 0;
}