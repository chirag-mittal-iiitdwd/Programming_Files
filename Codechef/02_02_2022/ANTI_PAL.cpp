#include<bits/stdc++.h>
/*
    Soring
    Stack
    Queue
    Dynamic Programming
    Backtracking
    Linked List
    Sliding Window
    Tree
    Two Pointer
    Binary Search
    Maths
    Graph
    Greedy
    Heaps
    Hashing
*/
using namespace std;
#define int long long int
#define mod 1000000007

void makeAntiPalindrome(string&str){
    int i=0;
    int n=str.length();
    int j=n/2;
    int x=n/2;

    for(i=0;i<x;i++){
        if(str[i]==str[n-1-i]){
            char temp=str[i];
            str[i]=str[j+i];
            str[j+i]=temp;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;

        if(n&1){
            cout<<"NO"<<endl;
        }
        else{
            bool flag=true;
            unordered_map<char,int>mp;
            for(auto&it:str){
                mp[it]++;
            }
            int x=n/2;
            for(auto&it:mp){
                if(it.second>x){
                    flag=false;
                }
            }
            if(flag){
                cout<<str<<endl;
                makeAntiPalindrome(str);
                cout<<"YES\n";
                cout<<str<<endl;
            }
            else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}