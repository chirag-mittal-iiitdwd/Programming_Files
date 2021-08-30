/* 
    Brute force : Take 2 arrays and merge until only one array is left
    --> Efficient solution : 
    1. Create a mini heap of pairs.
        Pair --> {value , array nunmber}
    2. Insert (first element ,array number) of all the sorted
       array into minHeap.
    3. Main Idea : We will pop element from the Min Heap and store
       into the answer array. Insert the next element of the Sorted
       Array into MinHeap.
    4. We also need to keep track of the indices of the elements
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    vector<vector<int>>a(k);
    for(int i=0;i<k;i++){
        int size;
        cin>>size;
        a[i]=vector<int> (size);
        for(int j=0;j<size;j++){
            cin>>a[i][j];
        }
    }
    // vector of size k and initialised with 0
    // This will contain first element of each array
    vector<int> idx(k,0);

    // Creating Min Heap of pairs {value,array number}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i=0;i<k;i++){
        pq.push({a[i][0],i});
    }
    vector<int> ans;
    while(!pq.empty()){
        pair<int,int> x=pq.top();
        pq.pop();
        ans.push_back(x.first);

        // Checking if the current array became empty or not
        if(idx[x.second]+1<a[x.second].size()){
            pq.push({a[x.second][idx[x.second]+1],x.second});
        }
        idx[x.second]+=1;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}