#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={1,4,5,8,9};
    bool res=binary_search(a,a+5,3);
    bool res1=binary_search(a,a+5,4);
    cout<<res<<" "<<res1<<endl;
}