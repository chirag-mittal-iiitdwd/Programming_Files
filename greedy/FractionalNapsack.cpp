/*
    We are given 'n' items with {weight,value} of each item and
    the capacity of knapsack (Sack) "W". We need to put these items in 
    knapsack such that final value of items in knapsack is maximum.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    float capacitity;
    cin>>capacitity;
    vector<pair<float,float>>p;
    for(int i=0;i<n;i++){
        float weight,value;
        cin>>weight>>value;
        p.push_back({weight,value});
    }

    vector<pair<float,float>>q;
    for(int i=0;i<n;i++){
        q.push_back({p[i].first,(p[i].second/p[i].first)});
    }
    sort(q.begin(),q.end(),[&](pair<float,float>&a,pair<float,float>&b){
        return a.second>b.second;
    });

    for(auto it:q){
        cout<<it.first<<" "<<it.second<<endl;
    }

    float filledSpace=0;
    float valueTaken=0;
    int i=0;
    while(filledSpace<=capacitity && i<q.size()){
        if(filledSpace+q[i].first<=capacitity){
            filledSpace+=q[i].first;
            valueTaken+=q[i].first*q[i].second;
        }
        else{
            float spaceLEft=capacitity-filledSpace;
            filledSpace+=spaceLEft;
            valueTaken+=spaceLEft*q[i].second;
        }
        i++;
    }

    cout<<"Stolen Weight : "<<filledSpace<<endl;
    cout<<"Stolen value : "<<valueTaken<<endl;
    return 0;
}