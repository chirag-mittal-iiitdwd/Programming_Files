#include<iostream>
#include<climits>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

class stack{
    node* front;
    public:
    stack(){
        front=NULL;
    }
    void push(int val){
        node* temp=new node(val);
        temp->next=front;
        front=temp;
    }

    void pop(){
        if(front==NULL){
            cout<<"Stack Underflow\n";
            return;
        }
        node*temp=front;
        front=front->next;
        delete(temp);
    }

    int top(){
        if(front==NULL){
            cout<<"Nothing in the stack\n";
            return INT_MAX;
        }
        return front->data;
    }

    bool empty(){
        return front==NULL;
    }
};

int main(){
    stack q;
    int arr[10]={1,2,3,4};
    for(int i=0;i<4;i++){
        q.push(arr[i]);
    }

    for(int i=0;i<4;i++){
        cout<<q.top()<<" ";
        q.pop();
        cout<<q.empty()<<endl;
    }
    cout<<q.empty()<<endl;
    cout<<q.top()<<endl;
    return 0;
}