// Numbers are coming and we have to tell median after each input
/*
    arr = [10, 15 , 21 , 30 , 18 , 19]
    After first input :
        Sorted : 10
        Median : 10

    Second input :
        Sorted : 10 , 15
        Median : (10 + 15)/2
    
    Third input :
        Sorted : 10 ,15 , 21
        Median : 15
    
    Fourth Input :
        Sorted : 10 ,15 , 21 , 30
        Median : (15 + 21)/2
    
    Fifth input :
        Sorted : 10 , 15 , 18 , 21 , 30
        Median : 18
    
    Sixth Input :
        Sorted : 10 , 15 , 18 , 19 , 21 , 30
        Median : (18 + 19)/2


    --> Optimal approach : Using Heaps
        1. Keep one maxHeap and one MinHeap
        2. Partition the array into two parts 
        3. During insertion if(sizeof(maxHead)==sizeof(minHeap)),
           then add into maxHeap otherwise minHeap and always maintain
           sizeof | MaxHeap - MinHeap | = 1
        4. For median if(sizeof(maxHead)==sizeof(minHeap)), then average 
           of top of minHead + MaxHeap else top of maxHeap
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pqmin;
priority_queue<int,vector<int>> pqmax;

void insert(int x){
    if(pqmin.size()==pqmax.size()){
        if(pqmax.size()==0){
            pqmax.push(x);
            return;
        }
        // Because Max Heap contains all the first smaller elements
        if(x<pqmax.top()){
            pqmax.push(x);
        }
        else{
            pqmin.push(x);
        }
    }
    else{
        if(pqmax.size()>pqmin.size()){
            if(x>=pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp=pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else{
            if(x<pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp=pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
        
    }
}

double findMedian(){
    if(pqmin.size()==pqmax.size()){
        return (pqmax.top()+pqmin.top())/2.0;
    }
    else if(pqmax.size()>pqmin.size()){
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }
}

int main(){
    int arr[]={10, 15 , 21 , 30 , 18 , 19};
    for(int i=0;i<6;i++){
        insert(arr[i]);
        cout<<findMedian()<<" ";
    }
    cout<<endl;
}