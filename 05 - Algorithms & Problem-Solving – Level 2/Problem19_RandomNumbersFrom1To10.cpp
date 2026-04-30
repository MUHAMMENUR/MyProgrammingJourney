#include <iostream>
#include <cstdlib>
using namespace std;




int PrintRandomNumbersFrom1To10(int From,int To){
    int RandNum=rand()%(To-From+1)+From;
    return RandNum;

}

int main(){
    srand((unsigned)time(NULL));
cout<< PrintRandomNumbersFrom1To10(1,21)<<endl;
cout<< PrintRandomNumbersFrom1To10(1,21)<<endl;
cout<< PrintRandomNumbersFrom1To10(1,21)<<endl;
cout<< PrintRandomNumbersFrom1To10(1,21)<<endl;
cout<< PrintRandomNumbersFrom1To10(1,21)<<endl;


}