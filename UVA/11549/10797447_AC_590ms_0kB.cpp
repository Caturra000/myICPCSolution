#include<bits/stdc++.h>
using namespace std;
int T,n,k,ans,k1,k2;
char buf[100];
int nxt(int k){
	long long tmp=1ll*k*k;
	sprintf(buf,"%lld",tmp);
	memset(buf+n,0,sizeof(buf+n));
	return atoi(buf);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		ans=k1=k2=k;
		do{
			k1=nxt(k1);ans=max(ans,k1);
			k2=nxt(k2);ans=max(ans,k2);
			k2=nxt(k2);ans=max(ans,k2);
		}while(k1!=k2);
		printf("%d\n",ans);
	}
	return 0;
} 