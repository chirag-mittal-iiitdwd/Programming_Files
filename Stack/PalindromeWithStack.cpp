#include<iostream>
#include<climits>
using namespace std;
#define n 20
class stack{
    int *arr;
    int topEle;
    public:
    stack(){
        arr=new int[n];
        topEle=-1;
    }

    void pop(){
        if(topEle==-1){
            cout<<"Stack Underflow, No element to pop"<<endl;
            return;
        }
        topEle--;
    }

    int top(){
        if(topEle==-1){
            cout<<"Nothing in the stack"<<endl;
            return INT_MIN;
        }
        return arr[topEle];
    }

    void push(int x){
        if(topEle==n-1){
            cout<<"Stack OverFlow, Space FULL"<<endl;
            return;
        }
        topEle++;
        arr[topEle]=x;
    }

    bool empty(){
        return topEle==-1;
    }

    int size(){
        return topEle+1;
    }
};

void printFunction(stack st){
    int sizeOfStack=st.size();
    int arrDup[sizeOfStack];
    for(int i=0;i<sizeOfStack;i++){
        arrDup[i]=st.top();
        st.pop();
    }
    for(int i=0;i<sizeOfStack;i++){
        cout<<arrDup[i]<<" ";
    }
    cout<<endl;
}

bool checkPalindome(stack st){
    bool ans=true;
    int sizeOfStack=st.size();
    int arrDup[sizeOfStack];
    int arrDupRev[sizeOfStack];
    for(int i=0;i<sizeOfStack;i++){
        arrDup[i]=st.top();
        st.pop();
    }
    for(int i=(sizeOfStack-1);i>=0;i--){
        arrDupRev[i]=arrDup[sizeOfStack-1-i];
    }
    for(int i=0;i<sizeOfStack;i++){
        if(arrDupRev[i]!=arrDup[i]){
            ans=false;
            break;
        }
    }

    return ans;
}

int main(){
    int choice;
    while(1){
        cout<<"Enter 1 for Pushing an Element on to Stack"<<endl;
        cout<<"Enter 2 for Poping an element from the Stack"<<endl;
        cout<<"Enter 3 for checking palindrome"<<endl;
        cout<<"Enter 4 for checking the status of the Stack"<<endl;
        cout<<"Enter 5 for status"<<endl;
        cout<<"Enter 6 for Exit"<<endl;
        stack st;
        cin>>choice;
        int sizeStack=st.size();
        switch (choice)
        {
        case 1:
            int num; 
            cout<<"Enter the number which you want to push into the stack: ";
            cin>>num;
            st.push(num);
            break;
        case 2:
            cout<<"You have poped out "<<st.top()<<" Entry from the stack"<<endl;
            st.pop();
            break;
        case 3:
            if(checkPalindome(st)){
                cout<<"The numbers in the stack are PALINDROME"<<endl;
            }
            else{
                cout<<"The numbers in the stack are not PALINDROME"<<endl;
            }
            break;
        case 4:
            sizeStack=st.size();
            if(sizeStack==0){
                cout<<"Currently the stack has no elements, UNDERFLOW"<<endl;
            }
            else{
                cout<<"The stack is not in Underflow Condition"<<endl;
            }

            if(sizeStack==20){
                cout<<"No elements could be added into the stack, OVERFLOW"<<endl;
            }
            else{
                cout<<"Stack not in Overflow condition"<<endl;
            }
            break;
        
        case 5:
            sizeStack=st.size();
            cout<<"The status of stack"<<endl;
            // if(sizeStack==0){
            //     cout<<"Currently the stack has no elements, UNDERFLOW"<<endl;
            // }
            // else if(st.size()==20){
            //     cout<<"No elements could be added into the stack, OVERFLOW"<<endl;
            // }
            // else{
            printFunction(st);
            // }
            break;
        case 6:
            exit(1);
            break;
        default:
            cout<<"Invalid Input, Please try again"<<endl;
            break;
        }
    }
    return 0;
}