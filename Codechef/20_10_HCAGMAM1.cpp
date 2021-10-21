/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        string history;
        cin>>history;
        int countOfOne=0;
        int maxStreak=INT_MIN;
        int currentStreak=0;
        for(int i=0;i<30;i++){
            if(history[i]=='1'){
                countOfOne++;
                currentStreak++;
            }
            else{
                maxStreak=max(maxStreak,currentStreak);
                // cout<<i<<" "<<maxStreak<<endl;
                currentStreak=0;
            }
        }
        maxStreak=max(maxStreak,currentStreak);
        int baseSal=(countOfOne*x);
        int bonus=(maxStreak*y);
        // cout<<baseSal<<" "<<bonus<<endl;
        cout<<baseSal+bonus<<endl;
    }
    return 0;
}