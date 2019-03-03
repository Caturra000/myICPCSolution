#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
#define rep(i,j,k) for(int i=j;i<=k;i++)
int n,k;
int num[maxn];
bool used[maxn];
int a[maxn];
int flag;
bool cmp(int a,int b){
	return abs(a-flag)<abs(b-flag);
}
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n>>k){
		memset(used,0,sizeof used);
		int now=1,cnt=1;
		while(1){
			if(now>k) break;
			used[cnt]=1;
			num[now]=cnt++;
			now+=2;
		}
		now=2,cnt=n;
		while(1){
			if(now>k) break;
			used[cnt]=1;
			num[now]=cnt--;
			now+=2;
		}
		flag=num[k];
		cnt=0;
		rep(i,1,n) if(!used[i]) a[++cnt]=i;
		sort(a+1,a+1+cnt,cmp);
//		if(last+(n-k)>=n) flag=-1;
//		else flag=1;
		rep(i,k+1,n){
//			num[i]=num[i-1]+flag;
			num[i]=a[i-k];
		}
		rep(i,1,n){
			if(i==n) cout<<num[i]<<endl;
			else cout<<num[i]<<" ";
		}
	}
	return 0;
}