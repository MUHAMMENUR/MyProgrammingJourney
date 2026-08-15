#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
string NumberToText(long long number) {
    if (number == 0)
        return " ";
    if (number >= 1 && number <= 19) {
        string Numberfrom1to19[] = { " ","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
        return Numberfrom1to19[number] + " ";
    }
    if (number >= 20 && number <= 99) {
        string Numberfrom20to90[] = { " "," ","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
        return Numberfrom20to90[number / 10] + " " + NumberToText(number % 10);
    }
    if (number >= 100 && number <= 999) {
        return NumberToText(number / 100) + "hundreds " + NumberToText(number % 100);
    }if (number >= 1000 && number <= 999999) {
        return NumberToText(number / 1000) + "thousands " + NumberToText(number % 1000);
    }if(number>=1000000 && number<=999999999) {
        return NumberToText(number / 1000000) + "millions " + NumberToText(number % 1000000);
    }if (number >= 1000000000 && number <= 999999999999) {
        return NumberToText(number / 1000000000) + "billions " + NumberToText(number % 1000000000);
    }
}


int main() {

    cout << "Enter a number: ";
    long long number;
    cin >> number;

    cout << NumberToText(number) << endl;

    return 0;
}