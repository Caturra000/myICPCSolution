#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
typedef long long ll;
int buf[100];
int nxt(int n,int k){
	if(!k) return 0;
	ll k2=(ll)k*k;
	int L=0;
	while(k2>0){
		buf[L++]=k2%10;k2/=10;
	}
	n=min(n,L);//length
	int ans=0;
	for(int i = 0; i < n; i++) ans=ans*10+buf[--L];
	return ans;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		set<int> s;
		int ans=k;
		while(!s.count(k)){
			s.insert(k);
			ans=max(ans,k);
			k=nxt(n,k);
		}
		printf("%d\n",ans);
	}
	return 0;
}