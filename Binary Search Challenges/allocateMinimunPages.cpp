/*
    n - number of in n different books [ascending ordrer]
    m - number of students
    All the books have to be didided among m students, consequetively.
    Allocate the pages in such a way that maximum pages allocates to a 
    student is minimum

    Example = [ 12, 34, 67, 90]
    Students (m) = 2
    Possible allocations   (max allocated)
    [12][34, 67, 90]   ---->    191
    [12, 34] [67 , 90] ---->    157
    [12, 34, 67] [90]  ---->    113  <--- Minimum allocated
    

    -----> Strategy
    Apply binary search for minimum and maximum values of max pages
    where initially min would be 0
    and max would be sum of all pages
    Now check the feasiblity of this
    Assign pages to each student in a sequential manner, while the current
    number of allocate pages don't exceed the value se by binary search

    If during allocation the number of students dont exceed the limit of 'm'
    then the solution is feasible. Else, it isn't
*/

#include<iostream>
#include<climits>
using namespace std;

bool isFeasible(int arr[],int n,int m,int min){
    int studentsRequired=1;
    // Sum represent the pages which we are giving to current student
    int sum=0;
    for(int i=0;i<n;i++){
        // Check if the page we want to distribute 
        // is grater than minimum possible maximum pages
        if(arr[i]>min){ // Allocation not possible
            return false;
        }
        if(sum+arr[i]>min){
            studentsRequired++;
            sum=arr[i];
            if(studentsRequired>m){
                return false;
            }
        }
        else{
            sum+=arr[i];
            // here we are still giving pages to current student
        }
    }
    return true;
}

int allocateMinimum(int arr[],int n,int m){
    int sum=0;
    if(n<m){
        return -1;
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int start=0;
    int end=sum;
    int ans=INT_MAX;
    while(start<end){
        int mid=(start+end)/2;
        if(isFeasible(arr,n,m,mid)){
            ans=min(ans,mid);
            // Since her we want the minimum so we decrease the mid
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[]={12, 34, 67, 90};
    int n=4;
    int m=2;
    cout<<allocateMinimum(arr,n,m);
}