// It is based on LIFO mechanism Last In First Out
// Push ---> Instering an element at the top of the stack
// Pop ---> Removing the topmost element of the stack
// Top ---> Returns the topmost value in the stack
// empty ---> Returns true if the stack is empty

// Array Implimentaion
/* Initially we mak ean array of a particular size

Top ----->
The top wiil be pointing to -1 index
For insterting top++ and than arr[top]=newVal
if top==last index than we cannot insert any element into the stack

Pop ----->
Top-- until we get index as -1. In case we get index equal to -1 that mean our stack is empty

Top ---->
return top value until and unless top!=-1

empty --->
if top==-1 return true

*/
#include<iostream>
#include<climits>
using namespace std;
#define n 10
class stack{
    int* arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }

    void push( int x){
        if(top==n-1){
            cout<<"Stack Overflow\n";
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop(){
        if(top==-1){
            cout<<"No element in Stack\n";
            return;
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"No element in stack\n";
            return INT_MIN;
        }
        return arr[top];
    }

    bool empty(){
        return top==-1;
    }
};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();

    cout<<st.empty()<<endl;
    st.pop();
    cout<<st.empty()<<endl;
}