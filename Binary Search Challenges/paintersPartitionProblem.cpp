/*
    n = length of n different boards
    m = painters available

    A painter paints 1 unit of borad in 1 unit of time and each painter will paint consecutive boards. Find the minimum time that will be required to paint all the boards

    example : borads = [10, 20, 30, 40]
            painters (m) = 2
            possible partitions
                [10][20,30,40]
                [10,20][30,40]
                [10,20,30][40]  <---- minimum (60)
    ---> Strategy :
        Apply binary search for minimum and maximum values of 'min' length of boards to be painted

        Check the feasiblity of this chosen value.
        Checking Feasibility : ASsign borads to each painter in a sequential manner, while the current length of assigned boards don't exceed the valuew set by binary search

        if during allocation the number of painters don't exceed the limit of 'm' then the solution is feasible. Else, it isn't
*/
#include<iostream>
using namespace std;

int findFeasible(int boards[],int n,int limit){
    int sum=0,painters=1;
    for(int i=0;i<n;i++){
        sum+=boards[i];
        if(sum>limit){
            sum=boards[i];
            painters++;
        }
    }
    return painters;
}

int paintersPartition(int boards[],int n,int m){
    int totalLength=0;
    int k=0; // Represent largest board size
    for(int i=0;i<n;i++){
        k=max(k,boards[i]);
        totalLength+=boards[i];
    }
    // k=40;
    // totalLength = 100;
    int low = k;
    int high=totalLength;
    while(low<high){
        int mid=(low+high)/2;
        int painter=findFeasible(boards,n,mid);
        if(painter<=m){
            high=mid;
        }
        else{
            low=mid-1;
            // cout<<low<<endl;
        }
    } 
    return low;      
}

int main(){
    int arr[]={10,20,30,40};
    int n=4;
    int m=2;
    cout<<paintersPartition(arr,n,m);
}