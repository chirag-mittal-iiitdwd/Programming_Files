#include<bits/stdc++.h>
using namespace std;

void printDuplicates(string str){
    unordered_map<char,int>mp;
    int n=str.length();
    for(int i=0;i<n;i++){
        mp[str[i]]++;
    }

    for(auto it:mp){
        if(it.second>1){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}

int main(){
    string str;
    getline(cin,str);
    printDuplicates(str);
}