#include<bits/stdc++.h>
using namespace std;
int main(){
    // vectors are better than lists

    // By default initialised by 0
    // Initialising the vector with a particular value
    vector<int> v={1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    v.push_back(200);
    for(int i=0;i<6;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    vector<int>::iterator it=v.begin();
    for(it;it!=v.end();it++){
        // cout<<typeid(it).name()<<endl;
        cout<<*(it)<<" ";
    }
    cout<<endl;

    for(auto it:v){
        // cout<<typeid(it).name()<<endl;
        cout<<it<<" ";
    }
    cout<<endl;

    v.erase(v.begin()+1);
    for(auto it:v){
        // cout<<typeid(it).name()<<endl;
        cout<<it<<" ";
    }
    cout<<endl;

    /* 
    erasing a range
    v.erase(v.begin()+1,v.end()-1);
    for(auto it:v){
        // cout<<typeid(it).name()<<endl;
        cout<<it<<" ";
    }
    cout<<endl; */

    v.insert(v.begin(),1000);
    // v.insert(v.begin()+2,2,10);
    for(auto it:v){
        // cout<<typeid(it).name()<<endl;
        cout<<it<<" ";
    }
    cout<<endl;

    v.insert(v.begin()+2,2,10);
    for(auto it:v){
        // cout<<typeid(it).name()<<endl;
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int> cpy(2,50);
    v.insert(v.begin(),cpy.begin(),cpy.end());
    for(auto it:v){
        // cout<<typeid(it).name()<<endl;
        cout<<it<<" ";
    }
    cout<<endl;
    v.swap(cpy);
    for(auto it:v){
        // cout<<typeid(it).name()<<endl;
        cout<<it<<" ";
    }
    cout<<endl;

    for(auto it:cpy){
        // cout<<typeid(it).name()<<endl;
        cout<<it<<" ";
    }
    cout<<endl;

    cpy.clear();
    cout<<v.empty()<<endl;
    cout<<cpy.empty()<<endl;
}