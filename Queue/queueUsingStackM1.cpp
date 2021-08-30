// For pusing an element into the queue we simply push element
// For poping operation ---->
/* if both stacks are empty then print error
    if stack2 is empty
        while stack1 is not empty, push everything from stack1 to stack2
    Pop the element from stack2 and return it
*/

// Here the Dequeue operation is costly
#include<iostream>
#include<stack>
#include<climits>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x){
        s1.push(x);
        // The time complexity is O(1)
    }

    int pop(){
        if(s1.empty() && s2.empty()){
            cout<<"QUEUE UNDERFLOW, PRINTING GARBAGE VALUE\n";
            return INT_MAX;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topVal=s2.top();
        s2.pop();
        return topVal;
        // Worst case complexity O(n)
    }

    bool empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.pop()<<endl;

    return 0;
}