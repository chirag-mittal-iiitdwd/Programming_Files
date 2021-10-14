#include<bits\stdc++.h>


using namespace std;

void printPernutations(string str){
    cout<<str<<endl;
    while(next_permutation(str.begin(),str.end())){
        for(int i=0;i<str.length();i++){
            cout<<str[i];
        }
        cout<<endl;
    }
}

void printPermuatationsRec(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        string ros=str.substr(0,i)+str.substr(i+1);
        printPermuatationsRec(ros,ans+ch);
    }
}

int main(){
    string str="ABC";
    printPermuatationsRec(str,"");
}