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

class queue{
    node* front;
    node* back;
    public:
    queue(){
        front=NULL;
        back=NULL;
    }

    void push(int val){
        node* n=new node(val);
        if(front==NULL){
            back=n;
            front=n;
            return;
        }
        
        back->next=n;
        back=n;
    }

    void pop(){
        if(front==NULL){
            cout<<"QUEUE UNDERFLOW"<<endl;
            return;
        }
        node* toDelete=front;
        front=front->next;
        delete toDelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"QUEUE UNDERFLOW"<<endl;
            return INT_MAX;
        }
        return front->data;
    }

    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++){
        q.push(arr[i]);
    }

    for(int i=0;i<10;i++){
        cout<<q.peek()<<" ";
        q.pop();
        cout<<q.empty()<<endl;
    }
    cout<<q.empty()<<endl;
    cout<<q.peek()<<endl;
    return 0;
}