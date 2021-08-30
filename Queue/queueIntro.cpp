// Same as stack just the pop will delete first element
#include<iostream>
#include<climits>
using namespace std;
#define n 15
class queue{
    int* arr;
    int front;
    int back;
    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }

    void push(int x){
        if(back==n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(front==-1 || front>back){
            cout<<"No element in the Queue"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            cout<<"No element in the queue"<<endl;
            return INT_MAX;
        }
        return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back){
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
    
    return 0;
}