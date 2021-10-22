// Time Compleity : O(max(maximumElement,N))
// Space Complexity : O(maxelement+1) + O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> countSort(int arr[],int n){

    // finding the maximum element
    int x=*max_element(arr,arr+n);

    // count array of size maxElement+1 because 0 will be there
    // string the count of evebry number in the array
    vector<int>countArr(x+1,0);
    for(int i=0;i<n;i++){
        countArr[arr[i]]++;
    }

    // finding the cummulative sum of counts of integers in array
    int prevSum=countArr[0];
    for(int i=1;i<x+1;i++){
        countArr[i]+=prevSum;
        prevSum=countArr[i];
    }

    // Creating the answer array to be returned
    vector<int>ansArr(n);
    for(int i=n-1;i>=0;i--){
        // Decrementing the count of current element starting from last
        countArr[arr[i]]--;
        // putting the currentElement to the decremented countArray position
        ansArr[countArr[arr[i]]]=arr[i];
    }
    return ansArr;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans=countSort(arr,n);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}