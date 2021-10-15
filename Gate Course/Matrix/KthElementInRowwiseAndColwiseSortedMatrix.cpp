#include<bits/stdc++.h>
using namespace std;

vector<int> oddNUmbers(int n){
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(((n-1-i)*2)+1);
    }
    return ans;
}

int KthElement(vector<vector<int>>mat,int n,int k){
    vector<int>OddNUmber=oddNUmbers(n);

    // cout<<"Odd Number Array : ";
    // for(auto it:OddNUmber){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    int toBeFound=-1;
    int sum=0;
    int prevSum=-1;
    for(int i=0;i<n;i++){
        sum+=OddNUmber[i];
        if(k<=sum){
            toBeFound=i;
            break;
        }
        prevSum=sum;
    }

    if(toBeFound!=0){
        k-=(prevSum);
    }

    // cout<<"TO be found : "<<toBeFound<<endl;

    vector<int>numbers;
    for(int i=toBeFound;i<n;i++){
        numbers.push_back(mat[toBeFound][i]);
    }

    for(int i=toBeFound+1;i<n;i++){
        numbers.push_back(mat[i][toBeFound]);
    }

    // cout<<"Nubers array : ";
    // for(auto it:numbers){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    sort(numbers.begin(),numbers.end());
    // cout<<"Nubers array : ";
    // for(auto it:numbers){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // cout<<"k : "<<k<<endl;
    return numbers[k-1];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>>mat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    cout<<KthElement(mat,n,k);
}