#include<bits/stdc++.h>
using namespace std;


int Knapsack01(vector<int>wt,vector<int>val,int w,int n){
    if(n==0 || w==0){
        return 0;
    }
    
    if(wt[n-1]<=w){
        return max(val[n-1]+Knapsack01(wt,val,w-wt[n-1],n-1),Knapsack01(wt,val,w,n-1));
    }
    else{
        return Knapsack01(wt,val,w,n-1);
    }
}

int main(){
    vector<int>wt={10,20,30};
    vector<int>val={60,100,120};
    int w=50;

    cout<<Knapsack01(wt,val,w,wt.size());
}