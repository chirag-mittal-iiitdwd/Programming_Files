#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int>mpp;

    // Here 1 is the key
    mpp[1]=2;
    mpp[1]++;
    mpp.insert({2,4});
    mpp.emplace(-1,3);
    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    // multimap --> can store {1,2} and {1,3} differently
    // unorderedMap --> Stores in any random order
}