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

#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;

// If sizes are not equal than top of larger size of heap
// If equal than average of the top of both heaps
void insertEle(int x){
    if (pqmin.size() == pqmax.size()){
        // base case if no element is inserted
        if (pqmax.size() == 0){
            pqmax.push(x);
            return;
        }

        // If incoming element is smaller than top of pqmax than push to pqmax
        // because maxheap stores all smaller elements
        if (x < pqmax.top()){
            pqmax.push(x);
        }
        else{
            pqmin.push(x);
        }
    }
    else{
        // Size of maxheap is greater than minheap
        // than if incoming element is greater than pqmax.top than push to pqmin
        // else swap pqmax.top and the incoming and push the swapped x to pqmin
        if(pqmax.size()>pqmin.size()){
            if(x>=pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp=pqmax.top();
                pqmax.pop();
                pqmax.push(x);
                pqmin.push(temp);
            }
        }

        // if size of minheap is greater
        // if x<pqmin.top() than push to pqmax
        // else swap with pqmax.top and x and push x to pqmin
        else{
            if(x<pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp=pqmin.top();
                pqmin.pop();
                pqmin.push(x);
                pqmax.push(temp);
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
        insertEle(arr[i]);
        cout<<findMedian()<<" ";
    }
    cout<<endl;
}