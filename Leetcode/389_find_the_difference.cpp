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
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        int i=0,j=0,n=s.size(),m=t.size();
        
        while(i<n && j<m){
            if(s[i]!=t[i]){
                return t[i];
            }
            i++;
            j++;
        }
        return t[m-1];
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(auto&it:s){
            mp[it]++;
        }
        
        for(auto&it:t){
            mp[it]--;
            if(mp[it]==-1){
                return it;
            }
        }
        return ' ';
    }
};