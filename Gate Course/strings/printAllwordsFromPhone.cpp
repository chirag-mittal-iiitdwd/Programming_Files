#include<bits\stdc++.h>
using namespace std;

void printPhoneDigitCombinations(string digit1,string digit2){
    if(digit1.length()==0){
        return;
    }
    char ch=digit1[0];
    string ros=digit1.substr(1);
    for(int i=0;i<digit2.length();i++){
        cout<<ch<<digit2[i]<<endl;
    }
    printPhoneDigitCombinations(ros,digit2);
}

// second function not working
void printPhoneDigitCombinations1(string digit1,string digit2){
    if(digit1.length()==0){
        return;
    }
    string ros=digit1.substr(1);
    for(int i=0;i<digit2.length();i++){
        cout<<to_string(digit1[0])+to_string(digit2[i])<<endl;
    }
    printPhoneDigitCombinations(ros,digit2);
}

int main(){
    vector<string>digit={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n,m;
    cin>>n>>m;
    printPhoneDigitCombinations(digit[n],digit[m]);
    cout<<endl;
    printPhoneDigitCombinations1(digit[n],digit[m]);
}