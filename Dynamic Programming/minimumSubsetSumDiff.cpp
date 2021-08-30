/*
    Absolute Difference of two sets must be the minimum
    https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12
*/
#include<bits/stdc++.h>
using namespace std;

int minimumDifference(int n,int arr[]){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    bool t[n+1][sum+1];
    for(int i=0;i<sum+1;i++){
        t[0][i]=false;
    }
    for(int i=0;i<n+1;i++){
        t[i][0]=true;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=((t[i-1][j])||(t[i-1][j-arr[i-1]]));
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    vector<int>trueCan;  
    for(int i=0;i<sum/2;i++){
        if(t[n][i]==true){
            trueCan.push_back(i);
        }
    }

    for(auto it:trueCan){
        cout<<it<<" ";
    }
    cout<<endl;

    int minim=INT_MAX;
    for(int i=0;i<trueCan.size();i++){
        minim=min(minim,sum-(2*trueCan[i]));
    }

    return minim;
}

int main(){
    int n=3;
    int arr[n]={1,2,7};
    cout<<minimumDifference(n,arr);
}