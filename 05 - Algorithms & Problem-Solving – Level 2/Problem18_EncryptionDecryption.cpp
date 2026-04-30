#include <iostream>
#include <string>
using namespace std;

string ReadText(string Message){
    string Text="";
    cout<<Message;
    getline(cin,Text);
    return Text;

}

string AfterEncryption(string Text){

    for (int i = 0; i <=Text.length()-1; i++)
    {
       Text[i]=Text[i]+2;
    }
    
     return Text;

}
string BeforeEncryption(string Text){
    for (int i = 0; i <=Text.length()-1; i++)
    {
        Text[i]=Text[i]-2;
    }
    
    return Text;
}

int main(){
    string UserName=ReadText("Please Enter your name to Encyption:");
    string After=AfterEncryption(UserName);
    string Decryption=BeforeEncryption(After);

    cout<<"Text Before Encryption: "<<UserName<<endl;
    cout<<"Text After Encryption: "<<After<<endl;
    cout<<"Text After Decryption: "<<Decryption;
}