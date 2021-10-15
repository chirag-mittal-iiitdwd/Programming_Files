#include<bits/stdc++.h>
using namespace std;

vector<int> oddNUmbers(int n){
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(((n-1-i)*2)+1);
    }
    return ans;
}

int kthSmallestElement(vector<vector<int>>mat,int n,int k){
    vector<int> elemntsInThatIteration=oddNUmbers(n);
    int iterationNumber=-1;
    int prevSum=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=elemntsInThatIteration[i];
        if(k<=sum){
            iterationNumber=i;
            break;
        }
        prevSum+=elemntsInThatIteration[i];
    }

    k-=prevSum;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=iterationNumber;i<n;i++){
        q.push(mat[iterationNumber][i]);
    }
    for(int i=iterationNumber+1;i<n;i++){
        q.push(mat[i][iterationNumber]);
    }
    for(int i=0;i<k-1;i++){
        q.pop();
    }
    return q.top();
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
    cout<<kthSmallestElement(mat,n,k);
}