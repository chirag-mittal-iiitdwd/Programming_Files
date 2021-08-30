#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int> ls;

    // Can push at back
    ls.push_back(2);
    ls.emplace_back();

    // Can push at front
    ls.push_front(5);
    ls.emplace_front(100);

    for(auto i:ls){
        cout<<i<<" ";
    }
}