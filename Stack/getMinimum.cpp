#include<iostream>
#include<climits>
using namespace std;
#define n 20
class stack{
    int *arr;
    int top;
    int minimum;
    int size;
    public:
    stack(){
        arr=new int[n];
        top=-1;
        minimum=INT_MAX;
        size=0;
    }

    void push(int val){
        if(top==n-1){
            cout<<"Stack Overflow\n";
            return;
        }
        top++;
        arr[top]=val;
        minimum=min(minimum,arr[top]);
        size++;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack Underflow\n";
            return;
        }
        if(arr[top]==minimum){
        }
        top--;
        size--;
        minimum=INT_MAX;
        for(int i=0;i<size;i++){
            minimum=min(minimum,arr[i]);
        }
    }

    int Top(){
        if(top==-1){
            return INT_MAX;
        }
        return arr[top];
    }

    bool empty(){
        return top==-1;
    }

    int getMinimun(){
        if(top==-1){
            cout<<"Stack Underflow, Printing garbage value\n";
            return INT_MIN;
        }
        return minimum;
    }
};


int main(){
    stack st;
    int arr[5]={-2,5,-1,3,-3};
    for(int i=0;i<5;i++){
        st.push(arr[i]);
    }
    cout<<st.getMinimun()<<endl;
    st.pop();
    cout<<st.getMinimun()<<endl;
}