// 01 0011 01 01

#include<bits/stdc++.h>
using namespace std;

int substringsWithEqual1and0(string str){
    int count0=0,count1=0,count=0,n=str.length();
    for(int i=0;i<n;i++){
        if(str[i]=='0'){
            count0++;
        }
        else{
            count1;
        }
        if(count0==count1){
            count++;
        }
    }
    if(count==0){
        return -1;
    }
    return count;
}

int main(){
        
}