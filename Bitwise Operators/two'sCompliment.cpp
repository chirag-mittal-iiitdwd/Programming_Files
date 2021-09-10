#include<bits/stdc++.h>
using namespace std;
void twoCompliment(string str){
    int n=str.length();
    string revCompliemt="";
    int count=0;
    int i=0;
    while(i<n){
        if(str[i]=='1'){
            i++;
            count++;
            revCompliemt+="1";
            break;
        }
        else{
            revCompliemt+="0";
            i++;
        }
    }
    cout<<revCompliemt<<endl;
}
int main(){
    string str="00000101";
    twoCompliment(str);
}