#include<iostream>
#include<climits>
using namespace std;
class stack{
    int arr[5];
    int Top=-1;
    public:
    void push(int data){
        Top++;
        if(Top<5){
            arr[Top]=data;
        }
        else{
            cout<<"stack overflow\n";
        }
    }

    void pop(){
        Top--;
    }

    int top(){
        if(Top>=0){
            return arr[Top];
        }
        else{
            cout<<"stack underflow\n";
            return INT_MIN;
        }
    }

    bool empty(){
        return Top==-1;
    }    
};

int main(){

}