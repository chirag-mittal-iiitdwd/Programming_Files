/*
    We need to find the minimum attempts in worst case to find the floor at which the egg breaks
    we will be given with number of eggs and height of the building

    Base case 
    if(e==0 || e==1) return f;
    if(f==0 || f==1) return f;

    for loop starts from k=1;k<=f;k++

*/

#include<bits/stdc++.h>
using namespace std;

int solve(int e,int f){
    if(f==0 || f==1 || e==1){
        return f;
    }

    // Minimum attempts
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int eggBroke=solve(e-1,k-1);
        int eggDidNotBreak=solve(e+1,f-k);
        int attempts=1+max(eggDidNotBreak,eggBroke); // Max is for worst cases, when we start from bottom
        mn=min(mn,attempts); // minimum attempts
    }

    return mn;
}

int t[100][100];
int solveDP(int e,int f){
    if(f==0 || f==1 || e==1){
        return f;
    }
    if(t[e][f]!=-1){
        return t[e][f];
    }
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int eggBroke=solveDP(e-1,k-1);
        int eggDidNotBreak=solveDP(e+1,f-k);
        int attempts=1+max(eggDidNotBreak,eggBroke); // Max is for worst cases
        mn=min(mn,attempts); // minimum attempts
    }
    t[e][f]=mn;
    return t[e][f];
}

int tOpti[100][100];
int solveDPOpti(int e,int f){
    if(f==0 || f==1 || e==1){
        return f;
    }
    if(t[e][f]!=-1){
        return t[e][f];
    }
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int eggBroke,eggDidNotBreak;
        if(t[e-1][k-1]!=-1){
            eggBroke=t[e-1][k-1];
        }
        else{
            eggBroke=solveDPOpti(e-1,k-1);
        }
        
        if(t[e+1][f-k]!=-1){
            eggDidNotBreak=t[e+1][f-k];
        }
        else{
            eggDidNotBreak=solveDPOpti(e+1,f-k);
        }
        int attempts=1+max(eggDidNotBreak,eggBroke); // Max is for worst cases
        mn=min(mn,attempts); // minimum attempts
    }
    t[e][f]=mn;
    return t[e][f];
}