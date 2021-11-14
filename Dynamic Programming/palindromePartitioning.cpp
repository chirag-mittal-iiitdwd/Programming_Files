/*
    We have to minimize the number of partitions required to divide the string such that every divided part is palindrome
    In worst case we can divide every character  

    Problem is based on MCM because we need to traverse k throught the entire string

    i=0, j=string.length()-1

    if(i>=j && also check if the string is palindrome){
        return 0; ---> base condition
    }

    k=i to k=j-1 ---> i to k , k+1 to j
    temp = solve(arr,i,k)+solve(arr,k+1,j)+1;
    ans=min(ans,temp)
*/

#include<bits/stdc++.h>
using namespace std;

class palindromePart{
    bool isPalindrome(string str,int i,int j){
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public:
    int t[100][100];
    int palindromePartitioning(string str,int i,int j){
        if(i==j || isPalindrome(str,i,j)){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        t[i][j]=INT_MAX;
        for(int k=i;k<j;k++){
            t[i][j]=min(t[i][j],palindromePartitioning(str,i,k)+palindromePartitioning(str,k+1,j)+1);
        }
        return t[i][j];
    }
};

class palindromePartOpti{
    bool isPalindrome(string str,int i,int j){
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public:
    int t[100][100];
    int palindromePartitioning(string str,int i,int j){
        if(i==j || isPalindrome(str,i,j)){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        t[i][j]=INT_MAX;
        for(int k=i;k<j;k++){
            int left,right;
            if(t[i][k]!=-1){
                left=t[i][k];
            }
            else{
                t[i][k]=palindromePartitioning(str,k+1,j);
                left=t[i][k];
            }
            if(t[k+1][j]!=-1){
                right=t[k+1][j];
            }
            else{
                t[k+1][j]=palindromePartitioning(str,k+1,j);
                right=t[k+1][j];
            }
            t[i][j]=min(t[i][j],left+right+1);
        }
        return t[i][j];
    }
};

// bool isPalindrome(string String, int i, int j){
//     while(i < j){
//         if(String[i] != String[j])
//             return false; 
//         i++;
//         j--;
//     }
//     return true;
// }

// int palindromePartitioning(string str,int i,int j){
//     if(i>=j || isPalindrome(str,i,j)){
//         return 0;
//     }
//     int mini=INT_MAX;
//     for(int k=i;k<=j-1;k++){
//         mini=min(mini,palindromePartitioning(str,i,k)+palindromePartitioning(str,k+1,j)+1);
//     }
//     return mini;
// }

int main(){
    string str;
    cin>>str;
    palindromePart obj;
    memset(obj.t,-1,sizeof(obj.t));
    cout<<obj.palindromePartitioning(str,0,str.size()-1)<<endl;
}