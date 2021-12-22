#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int category(char a){
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
        return 0;
    }
    return 1;
}

void markQuestionMarks(string s,string p,vector<pair<int,char>>&pQ,vector<pair<int,char>>&qQ,int n){
    map<char,int>mp;
    for(int i=0;i<n;i++){
        if(s[i]=='?' && p[i]=='?'){
            continue;
        }
        else if(s[i]=='?'){
            mp[p[i]]++;
        }
        else if(p[i]=='?'){
            mp[s[i]]++;
        }
    }

    int volvel=0;
    int consonant=0;
    for(auto &it:mp){
        if(category(it.first)==0){
            volvel+=it.second;  // Total vovels
        }
        if(category(it.first)==1){
            consonant+=it.second; // Total consonants
        }
    }

    pair<int,char>ans;
    if(volvel>consonant){
        ans.first=0;
    }
    else{
        ans.first=1;
    }

    char gratest;
    int cur=0;
    int maxi=INT_MIN;
    for(auto &it:mp){
        if(category(it.first)==ans.first){
            if(it.second>maxi){
                gratest=it.first;
                maxi=it.second;     // maximum number of same characters
            }
        }
    }

    ans.second=gratest;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,p;
        cin>>s>>p;

        vector<pair<int,char>>pQ;
        vector<pair<int,char>>qQ;
        markQuestionMarks(s,p,pQ,qQ,n);
    }
    return 0;
}