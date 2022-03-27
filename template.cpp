#include "bits/stdc++.h"
using namespace std;

#define int 			  long long int
#define mod 			  1000000007
#define endl 			  "\n"
#define ceild(a, b) 	  ((a) / (b) + ((a) % (b) != 0))
#define all(v) 			  v.begin(),v.end()
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define ff 				  first
#define ss 				  second
#define pii               pair<int,int>
#define mii				  map<int,int>
#define vi                vector<int> 
#define si                set<int> 
#define pq                priority_queue<int>
#define rpq               priority_queue<int, vector<int>, greater<int> >
#define mmap              multimap 
#define uset              unordered_set
#define mset              multiset
#define umap              unordered_map
#define array(a,n)        int a[n]; f(i,n) cin>>a[i];
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

void solve(){
    int n,x;
	cin>>n>>x;

	// i -> size 
	// (x/i) -> mini ele
	for(int i=1;i<=n;i++){
		if((x%i)==0 && (n-i+1)>=(x/i)){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}