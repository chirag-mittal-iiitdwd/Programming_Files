#include<iostream>
#include<climits>
using namespace std;
#define n 2
class stack2{
    int *arr;
    int *top;
    public:
    stack2(){
        arr=new int[n];
        top=new int[2];
        top[0]=-1;
        top[1]=((n/2));
    }

    void push(int x){
        int choice;
        cout<<"Push stack number : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            if(top[0]==(n/2)){
                cout<<"The stack1 Overflow"<<endl;
                return;
            }
            top[0]++;
            arr[top[0]]=x;
            break;
        case 2:
            if(top[1]==n){
                cout<<"The stack2 Overflow"<<endl;
                return;
            }
            top[1]++;
            arr[top[1]]=x;
            break;
        default:
            cout<<"Invalid Input"<<endl;
            break;
        }
    }

    void pop(){
        int choice;
        cout<<"Pop stack number : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            if(top[0]==-1){
                cout<<"Stack1 UnderFlow"<<endl;
                return;
            }
            top[0]--;
            break;
        case 2:
            if(top[1]==-1){
                cout<<"Stack2 UnderFlow"<<endl;
                return;
            }
            top[1]--;
            break;
        default:
            cout<<"Invalid Input"<<endl;
            break;
        }
    }

    int TOP(){
        int choice;
        cout<<"Top stack number : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            if(top[0]==-1){
                cout<<"Stack1 UnderFlow ,Garbage value ";
                return INT_MAX;
            }
            return arr[top[0]];
            break;
        case 2:
            if(top[1]==-1){
                cout<<"Stack2 UnderFlow ,Garbage value ";
                return INT_MAX;
            }
            return arr[top[1]];
            break;
        default:
            cout<<"INVALID INPUT"<<endl;
            break;
        }
        return INT_MAX;
    }
};
int main(){
    stack2 st;
    st.push(1);
    st.push(2);

    cout<<st.TOP()<<endl;
    st.pop();
    cout<<st.TOP()<<endl;
    st.pop();
}