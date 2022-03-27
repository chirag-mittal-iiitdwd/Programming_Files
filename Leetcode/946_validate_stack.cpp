#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0;

        for(auto it:pushed){
            st.push(it);
            while(!st.empty() && st.top()==popped[i]){
                st.pop();
                i++;
            }
        }

        return st.empty();
    }
};

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;

        for(auto&it:pushed){
            pushed[i]=it;
            i++;
            while(i>0 && pushed[i-1]==popped[j]){
                i--;
                j++;
            }
        }

        return i==0;
    }
};