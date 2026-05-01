#include <iostream>
#include <string>
using namespace std;

//Function to Read Text From User
string ReadText(string Message){
    string Text="";
    cout<<Message;
    getline(cin,Text);
    return Text;

}
//Function to Encrypt Text
// It shifts each character's ASCII value by +2
string AfterEncryption(string Text){

    for (int i = 0; i <=Text.length()-1; i++)
    
    {
       Text[i]=Text[i]+10;
    }
    
     return Text;

}
//Function to Decrypt Text
// It reverses the encryption by shifting back -2
string BeforeEncryption(string Text){
    for (int i = 0; i <=Text.length()-1; i++)
    {
        Text[i]=Text[i]-10;
    }
    
    return Text;
}

int main(){
    // Reading original data
    string UserName=ReadText("Please Enter your name to Encyption:");
    string After=AfterEncryption(UserName);
    string Decryption=BeforeEncryption(After);

    cout<<"Text Before Encryption: "<<UserName<<endl;
    cout<<"Text After Encryption: "<<After<<endl;
    cout<<"Text After Decryption: "<<Decryption;
}