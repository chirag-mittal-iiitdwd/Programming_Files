#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class stack{
    int n;
    queue<int>q1;
    queue<int>q2;
    public:
    stack(){
        n=0;
    }
    void push(int data){
        q1.push(data);
        n++;
    }
    void pop(){
        if(q1.empty()){
            cout<<"NO element in stack\n";
            return;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;
        swap(q1,q2);
    }
    int top(){
        if(q1.empty()){
            cout<<"Stack empty\n";
            return INT_MAX;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int val=q1.front();
        q2.push(val);
        swap(q1,q2);
        return val;
    }
    int size(){
        return n;
    }
};