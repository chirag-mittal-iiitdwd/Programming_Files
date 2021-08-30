/* 
    1. MAXHEAP : priority-queue<int,vector<int>>
    2. MINHEAP : priority-queue<int,vector<int>,greater<int>>

    push = O(log(n))
    pop = O(log(n))
    top = O(1)
    size = O(1)
*/

#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);
    cout<<pq.top()<<endl;
}