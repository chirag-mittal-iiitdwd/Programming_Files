
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
    while(t--){
        int numberOfQ,correctQ,passingMarks;
        cin>>numberOfQ>>correctQ>>passingMarks;
        int incorrect=(numberOfQ-correctQ);
        int obtained=(correctQ*3)-(incorrect);
        if(obtained>=passingMarks){
            cout<<"PASS"<<endl;
        }
        else{
            cout<<"FAIL"<<endl;
        }
    }
	
	return 0;
}