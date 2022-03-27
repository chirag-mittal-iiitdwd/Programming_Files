#include<bits/stdc++.h>
using namespace std;

class FreqStack {
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>m;
public:
int maxFreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq=max(maxFreq,freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        int val=m[maxFreq].top();
        m[maxFreq].pop();
        freq[val]--;
        if(m[maxFreq].empty()){
            maxFreq--;
        }
        return val;        
    }
};