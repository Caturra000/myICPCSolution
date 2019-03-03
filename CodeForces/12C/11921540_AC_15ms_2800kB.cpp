#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <=k; i++)
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;	
map<string,int> ID;
int a[maxn],b[maxn],n,m;
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n>>m){
		memset(b,0,sizeof b);
		ID.clear();
		int cnt=0;
		string str;
		rep(i,1,n) cin>>a[i];
		rep(i,1,m){
			cin>>str;
			if(ID.count(str)==0) ID[str]=++cnt;
			b[ID[str]]++;
		}
		sort(b+1,b+1+cnt,greater<int>());
		sort(a+1,a+1+n);
		ll ans1=0;
		rep(i,1,cnt) ans1+=1ll*b[i]*a[i];
		ll ans2=0;
		sort(a+1,a+1+n,greater<int>());
		rep(i,1,cnt) ans2+=1ll*b[i]*a[i];
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}