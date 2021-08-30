#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int>st;
    // stores in descending order by default but using greater<int>
    // make it to store at front and unique elements
    st.insert(1);
    st.insert(2);
    st.insert(-2);
    for(auto it:st){
        cout<<it<<" ";
    }
    cout<<endl;

    auto it=st.lower_bound(2);
    cout<<*(it)<<endl;
}