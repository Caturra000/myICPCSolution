#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
bitset<maxn> isnprime;
int prime[maxn];
int sai(int n){
    isnprime[0]=isnprime[1]=1;
    for(int i = 2; i*i <= n; i++){
        if(!isnprime[i]){
            for(int j = 2*i; j <= n; j+=i){
                isnprime[j]=1;
            }
        }
    }
    int cnt=0;
    for(int i = 1; i <= n; i++) if(!isnprime[i]) prime[cnt++]=i;
    return cnt;
}
bitset<maxn> vis;
int main(){
	int cntt=sai(maxn-1);
	int T,kase=0; scanf("%d",&T);
	while(T--){
		int a,b; scanf("%d%d",&a,&b);
		int cnt=0;
		if(b<maxn) for(int i = a; i <= b; i++){
			cnt+=1-isnprime[i];
		}
		else{
			for(int i = 0; i <= b-a; i++) vis[i]=0;
			for(int i = 0; i < cntt && prime[i]*prime[i]<=b; i++){
				ll k = a/prime[i];
				if(k*prime[i]<a) k++;//internal 
				for(ll j = k*prime[i]; j <= b; j+=prime[i]) vis[j-a]=1;
			}
			for(ll i = a; i <= b; i++) cnt+=1-vis[i-a];
		}
		printf("Case %d: %d\n",++kase,cnt);
	}
	return 0;
} 