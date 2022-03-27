#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
list<int>lst;
    MyHashSet() {
    }
    
    void add(int key) {
        lst.push_back(key);
    }
    
    void remove(int key) {
        lst.remove(key);
    }
    
    bool contains(int key) {
        if(find(lst.begin(),lst.end(),key)!=lst.end()){
            return true;
        }
        return false;
    }
};

