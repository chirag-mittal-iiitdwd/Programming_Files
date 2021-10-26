// <operator><operand><operand>
#include<bits/stdc++.h>
using namespace std;

// Start traversing from the end
// Keep pushing the operands
// If we found a opeartor than we pop two elements from stack
// first element (operator) second operator
// and then we again push the calculated value

int prefixExpressEvaluation(string str){
    stack<int>st;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            st.push(str[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch (str[i]){
                case '-':
                    st.push(op1-op2);
                    break;
                case '+':
                    st.push(op1+op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
            }
        }
    }
    return st.top();
}

int main(){
    string str;
    cin>>str;
    cout<<prefixExpressEvaluation(str)<<endl;
    // -+7*45+20 answer = 25
}