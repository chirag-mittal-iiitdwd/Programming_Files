/*
    Connected Problems
    1.  Subset Sum
    2.  Equal sum partition
    3.  Count of subset sum
    4.  Minimum subset sum diff
    5.  Target sum
    6.  # of subset and give diff


    Here we have choice which means either we can take it or not
    Also we have to find the maximum profit
    Both conditions satisfied so it is DP problem

    Choice Diagram
            Item 1
            /   \
           /     \
       w1<=w      w1>w
        / \        \
    inc  not inc   not inc
*/

/*
    return_type function(arguments){
        Base Condition

        Choice Diagram
    }
*/

/*
    Base Condition check : Think of the smallest vaild input
    Smallest possible thing here will be if the size of the arrays 
    is zero and if the capacity is equal to zero

    if(n==0 || w==0){
        return 0;
    }
*/

#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int val[],int w,int n){
    if(n==0||w==0){
        return 0;
    }
    if(wt[n-1]<=w){
        // Finding the maximum out of if we selected the value and if we not
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else{
        return knapsack(wt,val,w,n-1);
    }
}

/*
    The DP matrix will be created for the changing values only 
    in this case only W and n is changing

    Matrix of size t[n+1][w+1]
    initialize everything with -1
    memset(t,-1,size of(t))
    Now before going into recursion we will check into the matrix and take if 
    value is not equal to -1 there

    if(t[n][w]!=-1)[
        return t[n][w]
    ]
*/

int t[102][1002];

int knapsackMemo(int wt[],int val[],int w,int n){
    if(n==0||w==0){
        return 0;
    }
    if(t[n][w]!=-1){
        return t[n][w];
    }
    if(wt[n-1]<=w){
        // Finding the maximum out of if we selected the value and if we not
        return t[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else{
        return t[n][w]=knapsack(wt,val,w,n-1);
    }
}

// Sometimes the stack might get full with huge number of recursive calls
// In order to prevent this we use something called as top down method


/*
    We have to follow two steps
    Step 1: Initialize
    Step 2: Change recursive code to iterative

    The base condition of the recursive function is changed into
    the initialization of top down

    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=w){
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][w];
*/

int knapsack01DP(int wt[],int val[],int n,int w){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=w){
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][w];
}

int main(){
    memset(t,-1,sizeof(t));
}