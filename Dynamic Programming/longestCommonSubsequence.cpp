/*
    Firstly in the recursive code we must make two things
    1.  The Base Condition
    2.  Choice Diagram
    3.  The string must get smaller and smaller as the function progresses

    How to choose any element should be included or not?
    For this we need to go from the last element to the first and choose whether
    the last element should be included or not and forget it based on the choice diagram
    this way input gets smaller as function progresses

    Now base condition ?
    The base condition will be hit when the length of first string is zero or the length
    of second string is zero, in this case the length of longest common subsequence is zero

    if(n==0 || m==0){
        return 0;
    }

    Choice Diagram

    if(string1[n-1]==string2[m-1]){
        If the last element of both the strings match, then decrease the size 
        of both the arrays
        n=n-1;
        m=m-1;
    }
    else{
        Option 1. Take First string as it is and include the second string by
                  removing the last element
        Option 2. Take first string by removing the last element and second
                  as it is
        At last taking the maximum of both the options
    }

                                     Two strings are given
                                   /                       \
                            if the last              max(if they are not)
                          element are same                  same
                                 |                     /            \
                        decrease the size of    include first       include second
                            both by one          as it is and       as it is and remove
                                               remove one from     one from first sstring
                                                other string 
    
    int lowestCommonSubsequence(string x,string y,int n,int m){
        if(n==0 || m==0){
            return 0;
        }
        if(x[n-1]==y[m-1]){
            // Adding one because the element was found common and desired for answer
            return 1+lowestCommonSubsequence(x,y,n-1,m-1);
        }
        else{
            return max(lowestCommonSubsequence(x,y,n,m-1),lowestCommonSubsequence(x,y,n-1,m));
        }
    }
*/

#include<bits/stdc++.h>
using namespace std;

int lowestCommonSubsequenceRec(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(x[n-1]==y[m-1]){
        // Adding one because the element was found common and desired for answer
        return 1+lowestCommonSubsequenceRec(x,y,n-1,m-1);
    }
    else{
        return max(lowestCommonSubsequenceRec(x,y,n,m-1),lowestCommonSubsequenceRec(x,y,n-1,m));
    }
}

int main(){
    string x="abcdef";
    string y="azbcdefgh";
    cout<<lowestCommonSubsequenceRec(x,y,x.length(),y.length())<<endl;
}