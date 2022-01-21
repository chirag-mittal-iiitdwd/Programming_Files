#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q2.swap(q1);
    }
    
    int pop() {
        int top=q1.front();
        q1.pop();
        return top;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};