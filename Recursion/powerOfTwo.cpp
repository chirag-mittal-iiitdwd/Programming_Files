/*
    Time Complexity : O(N)
    Space Complexity : O(N) --> including stack
*/
#include<bits/stdc++.h>
using namespace std;
int powerOfTwo(int n){
    if(n==0){
        return 1;
    }
    return 2*powerOfTwo(n-1);

}
/*
    Time Complexity = O(Log N)
    Space Complexity = O(Log N) --> Including stack
*/
int powerOfTwoOpti(int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        int ans=powerOfTwoOpti(n/2);
        return ans*ans;
    }
    else{
        int ans=powerOfTwoOpti(n/2);
        return 2*ans*ans;
    }
}

int main(){
    int n=4;
    cout<<powerOfTwo(n)<<endl;
    cout<<powerOfTwoOpti(n)<<endl;
    return 0;
}