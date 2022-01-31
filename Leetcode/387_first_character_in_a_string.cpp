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



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(auto&it:s){
            mp[it]++;
        }
        
        for(int i=0;i<s.length();i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};