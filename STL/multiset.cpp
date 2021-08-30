#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(1);
    auto it=ms.begin();
    for(it;it!=ms.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    int n=ms.count(1);
    cout<<n<<endl;

    ms.erase(1);
    cout<<ms.size()<<endl;
}