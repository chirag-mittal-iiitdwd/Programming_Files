#include<bits/stdc++.h>
using namespace std;
string twoCompliment(string str){
    int n=str.length();
    string revCompliemt="";
    int count=0;
    int i=n-1;
    while(i>=0){
        if(str[i]=='1'){
            i--;
            count++;
            revCompliemt+="1";
            break;
        }
        else{
            revCompliemt+="0";
            i--;
        }
    }
    while(i>=0){
        if(str[i]=='0'){
            revCompliemt+="1";
        }
        else{
            revCompliemt+="0";
        }
        i--;
    }
    reverse(revCompliemt.begin(),revCompliemt.end());
    return revCompliemt;
}
int main(){
    string str="00000101";
    cout<<twoCompliment(str);
}