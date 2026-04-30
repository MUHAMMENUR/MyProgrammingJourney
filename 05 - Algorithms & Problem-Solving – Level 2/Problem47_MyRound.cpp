#include <iostream>
#include <cmath>
using namespace std;



float getfractionpart(float Number){
    return Number-int(Number);
}
float MyRound(float Number){
int Inpart;
Inpart=int(Number);

float franctionpart=getfractionpart(Number);

if (abs(franctionpart)>=0.5)
{
    if (Number>0)
    
        return Inpart+1;
    else
        return Inpart-1;

   
    
}else{
    return Inpart;
}
}

float ReadNumber(){
    float Number=0;
    cout<<"Please Enter Number: ";
    cin>>Number;
    return Number;
}

int main(){
    float Number=ReadNumber();
    cout<<"My round is: "<<MyRound(Number)<<endl;
    cout<<"C++ round is: "<<round(Number);
}

