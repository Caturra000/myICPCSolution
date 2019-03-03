#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2;
typedef long long ll;
const ll oo = 0x3f3f3f3f3f3f3f3f;
ll coin[]={1,5,10,20,50,100,200,500,1000,2000};
ll num[maxn],c[maxn];
ll ans;
void dfs(int i,ll cnt,ll t){//t
	if(cnt==0){
		ans=min(ans,t);
		return;
	}
	if(i<0){
		return;
	}
	c[i]=min(cnt/coin[i],num[i]);//当前硬币做多能取的数目 
	dfs(i-1,cnt-coin[i]*c[i],t+c[i]);
	if(c[i]>0){
		c[i]--;//少拿一个 
		dfs(i-1,cnt-coin[i]*c[i],t+c[i]);
	} 
}
int main(){
	ios::sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		ll p,tot,sum;tot=sum=0;
		cin>>p;
		for(int i = 0; i < 10; i++){
			cin>>num[i];
			sum+=coin[i]*num[i];
			tot+=num[i];
		}
		ll cnt=sum-p;
		if(cnt<0){
			cout<<-1<<endl;
			continue;
		}
		ans=oo;
		dfs(9,cnt,0);
		if(ans==oo) cout<<-1<<endl;
		else cout<<tot-ans<<endl;
	}
	return 0;
}