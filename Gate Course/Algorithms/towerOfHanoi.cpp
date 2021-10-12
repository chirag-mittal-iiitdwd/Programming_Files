#include<bits/stdc++.h>
using namespace std;

// First simply move n-1 pegs from src to help then last peg from src to dest
// Now the n-1 pegs from help to dest

void towerOfhanoi(int n,char source,char helper,char destination){
    if(n==0){
        return;
    }
    towerOfhanoi(n-1,source,destination,helper);
    cout<<"Move from "<<source<<" to "<<destination<<endl;
    towerOfhanoi(n-1,helper,source,destination);
}

int main(){
    towerOfhanoi(3,'A','B','C');
}