#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0,totalCost=0,n=gas.size();
        for(int i=0;i<n;i++){
            totalCost+=cost[i];
            totalGas+=gas[i];
        }
        if(totalCost>totalGas){
            return -1;
        }

        int gasInTank=0,start=0;
        for(int i=0;i<n;i++){
            gasInTank+=gas[i];
            gasInTank-=cost[i];
            if(gasInTank<0){
                start++;
                gasInTank=0;
            }
        }
        return start;
    }
};