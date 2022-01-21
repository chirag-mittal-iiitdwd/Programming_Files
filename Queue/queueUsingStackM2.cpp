// Everything else remains the same just
/* for dequeue operation we :
Recursively pop everything from the stack1, store the
poped items in a variable , than push at stack1 and return */

#include<iostream>
#include<stack>
#include<climits>
using namespace std;

class queue{
    stack<int> s1;
    public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        int x=s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item=pop();
        s1.push(x);
        return item;
    }

    bool empty(){
        return s1.empty()==true;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;
}