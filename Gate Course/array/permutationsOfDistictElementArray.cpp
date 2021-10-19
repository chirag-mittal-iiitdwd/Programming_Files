#include<bits/stdc++.h>
using namespace std;

void printPermuations(vector<int>input){
    sort(input.begin(),input.end());
    do{
        for(auto it:input){
            cout<<it<<" ";
        }
        cout<<endl;
    } while (next_permutation(input.begin(),input.end()));
    
}

void storePermuataions(vector<int>input,int idx,vector<vector<int>>&permutations){
    if(idx==input.size()){
        permutations.push_back(input);
        return;
    }
    for(int i=idx;i<input.size();i++){
        swap(input[i],input[idx]);
        storePermuataions(input,idx+1,permutations);
        swap(input[i],input[idx]);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int>input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    vector<vector<int>>permutations;
    printPermuations(input);

    storePermuataions(input,0,permutations);
    for(auto it:permutations){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}