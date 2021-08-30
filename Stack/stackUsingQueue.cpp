#include<iostream>
#include<queue>
using namespace std;
class stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    stack(){
        N=0;
    }

    void push(int val){
        N++;
        q2.push(val);
        while(!q1.empty()){
            
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }

    void pop(){
        q1.pop();
        N--;

    }
    int top(){
        return q1.front();
    }
    int size(){
        if(N<=0){
            return 0;
        }
        return N;
    }
};


int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    for(int i=0;i<4;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}