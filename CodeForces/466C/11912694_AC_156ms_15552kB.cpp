#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+11;
typedef long long ll;
int a[maxn],n;
ll sumL[maxn],sumR[maxn];
int s1[maxn],s2[maxn];
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		sumL[0]=sumR[n+1]=0;
		for(int i = 1; i <= n; i++) sumL[i]=sumL[i-1]+a[i];
		for(int i = n; i >= 1; i--) sumR[i]=sumR[i+1]+a[i];
		if(sumL[n]%3!=0){
			printf("0\n");
			continue;
		}
		int lft1=1e7,rgt1=0,lft2=1e7,rgt2=0;
		int cnt1=0,cnt2=0;
		ll ans=0;
		for(int i = 1; i <= n; i++) if(sumL[i]==sumL[n]/3) s1[++cnt1]=i;
		for(int i = 1; i <= n; i++) if(sumR[i]==sumL[n]/3) s2[++cnt2]=i;
		for(int i = 1; i <= cnt1; i++){
			int j = lower_bound(s2+1,s2+cnt2+1,s1[i]+2)-s2;
			int d = cnt2-j+1;
			ans+=d;
		}
		printf("%lld\n",ans);
	}
	return 0;
}