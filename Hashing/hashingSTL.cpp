/*
    Standard template library
    --> Maps
        Insertion : O(log(n))
        Accessing : O(log(n))
        Deletion : O(log(n))
        implemented using red black trees
        Key, value pair
        map<int,int>mp
    
    --> Unordered Maps
        Insertion : O(1)
        Accessing : O(1)
        Deletion : O(n)
        Hash tables (basically array of buckets)
        unorder_map<int,int>mp;
*/

#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int> m;
    m[8]=2;
    cout<<m[8]<<endl;
}