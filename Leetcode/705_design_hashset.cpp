#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
vector<bool>v;
    MyHashSet() {
        v.resize(10001);
    }
    
    void add(int key) {
        v[key]=true;
        cout<<"after add : "<<key<<" now : "<<v[key]<<endl;
    }
    
    void remove(int key) {
        v[key]=false;
        cout<<"after remove : "<<key<<" now : "<<v[key]<<endl;
    }
    
    bool contains(int key) {
        cout<<"after contains : "<<key<<" now : "<<v[key]<<endl;
        return v[key]!=false;
    }
};


class MyHashSet {
public:
    vector<vector<int>>v ;
    MyHashSet() {
        v = vector<vector<int>>(1024, vector<int>());
    }
    
    void add(int key) {
        v[key%1024].push_back(key);
        return;
    }
    
    void remove(int key) {
        v[key%1024].erase(std::remove(v[key%1024].begin(), v[key%1024].end(), key), v[key%1024].end());
        return;
    }
    
    bool contains(int key) {
        auto p = find(v[key%1024].begin(), v[key%1024].end(), key);
        if(p!= v[key%1024].end()) return true;
        return false;
    }
};