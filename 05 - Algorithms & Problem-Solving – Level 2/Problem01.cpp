#include <iostream>
using namespace std;
void ShowWelcmeMessage(){
    cout<<"\t\t\t\tMultipilication Table From 1 To 10\n"<<endl;
    for (int i = 1; i <=10; i++)
    {
        cout<<"\t"<<i;
    }
    cout<<endl;
    for (int i = 1; i < 85; i++)
    {
        cout<<"_";
    }
    cout<<endl;
    
}
void MublicitonTable(){
    for (int i = 1; i <=10; i++)
    {
    //If the number is a single digit, add an extra space to maintain vertical alignment.
    if (i<10)
    {
        cout<<i<<"   |";
    }else{
        cout<<i<<"  |";
    }
         for (int j = 1; j <= 10; j++)
  {
    cout<<"\t"<<i*j;
  }
 
  cout<<endl;
    
    
    }
   
}

int main(){
    ShowWelcmeMessage();
    MublicitonTable();
}