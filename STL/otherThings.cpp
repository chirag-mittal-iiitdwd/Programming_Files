#include<bits/stdc++.h>
using namespace std;
int main(){
    // Checking the number of set bits in any number
    int num=7;
    int cnt=__builtin_popcount(num);
    cout<<cnt<<endl;

    long long int num1=2758435354;
    int cnt1=__builtin_popcountll(num1);
    cout<<cnt1<<endl;

    string s="123";
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
    cout<<endl;

    int arr[]={1,2,5,-3,9,7,100,57};
    int maxi=*max_element(arr,arr+8);
    cout<<maxi<<endl;
}