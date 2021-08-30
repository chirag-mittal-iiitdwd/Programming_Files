/* 
    Given an array : 1, 2, 2, 2, 3, 4
    and k=2;
    We have to output elements in decreasing frequency till we reach 
    (K+1)th distinct elements.

    Approach (Hashing)
    1.  Create a map
    2.  While travelling, keep trach of elements and when we find 
        (K+1)th without element = break
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=6;
    int k=2;
    int a[n]={1,2,2,2,3,4};
    map<int,int> freq;
    for(int i=0;i<n;i++){
        int currentSize=freq.size();
        if(freq[a[i]]==0 && currentSize==k){
            break;
        }
        freq[a[i]]++;
    }

    vector<pair<int,int>> ans;
    map<int,int>::iterator it;
    for(it=freq.begin();it!=freq.end();it++){
        
        // This next condition is important because when we checked if
        // freq[a[i]]==0 && currentSize==k than we increased the size by one
        // In order to prevent that from inserting we put this if condition
        if(it->second!=0){
            pair<int,int> p;
            // interchanged the first and second 
            // because we want to sort on the basis of frequency
            p.first=it->second;
            p.second=it->first;
            ans.push_back(p);
        }
    }

    // descending sort
    sort(ans.begin(),ans.end(),greater<pair<int,int>>());
    vector<pair<int,int>> ::iterator it1;
    for(it1=ans.begin();it1!=ans.end();it1++){
        cout<<it1->second<<" "<<it1->first<<endl;
    }

    return 0;
}