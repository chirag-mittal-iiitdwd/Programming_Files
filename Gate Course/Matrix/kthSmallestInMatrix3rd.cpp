#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>> arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            pq.push(arr[i][j]);
        }
    }
    while (k > 1){
        pq.pop();
        k--;
    }
    return pq.top();
}