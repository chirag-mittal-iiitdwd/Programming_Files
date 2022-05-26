#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(auto&it:stones){
            q.push(it);
        }

        int lastStone=0;
        while(!q.empty()){
            if(q.size()==1){
                return q.top();
            }
            int f=q.top();
            q.pop();
            int s=q.top();
            q.pop();

            int diff=abs(f-s);
            if(diff!=0){
                lastStone=diff;
                q.push(diff);
            }
        }
        return lastStone;
    }
};