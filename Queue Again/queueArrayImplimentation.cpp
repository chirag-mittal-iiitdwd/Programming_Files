#include<iostream>
#include<climits>
using namespace std;

class queue{
    int front=-1;
    int back=-1;
    int arr[10];
    public:
    void push(int data){
        if(back==9){
            cout<<"NO Space left\n";
            return;
        }
        back++;
        arr[back]=data;
        if(front==-1){
            front++;
        }
    }
    int top(){
        if(front==-1 || front>back){
            cout<<"NO element in queue, no top exeception\n";
            return INT_MIN;
        }
        else{
            return arr[front];
        }
    }

    void pop(){
        if(front==-1 || front>back){
            cout<<"NO element in queue\n";
            return;
        }
        front++;
    }

    bool empty(){
        return (front>back || front==-1);
    }
};

int main(){
    int arr[11]={1,2,3,4,5,6,7,8,9,10,11};
    queue q;
    for(int i=0;i<11;i++){
        q.push(arr[i]);
    }
    cout<<q.empty()<<endl;
    for(int i=0;i<11;i++){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<q.empty()<<endl;
}