#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 1e6+11;
typedef long long ll;
int pq[maxn],sz;
void down(int rt){
    int lc,rc;
    while(rt<sz){
        lc=rt<<1,rc=rt<<1|1;
        if(rc<=sz) lc=pq[lc]>pq[rc]?rc:lc;
        if(lc<=sz&&pq[rt]>pq[lc]){
            pq[rt]^=pq[lc];
            pq[lc]^=pq[rt];
            pq[rt]^=pq[lc];
        }
        else return;
        rt=lc;
    }
}
void up(int rt){
    while(rt!=1&&pq[rt]<pq[rt/2]){
        pq[rt]^=pq[rt/2];
        pq[rt/2]^=pq[rt];
        pq[rt]^=pq[rt/2];
        rt>>=1;
    }
}
void push(int k){
    pq[++sz]=k;
    up(sz);
}
void pop(){
    pq[1]=pq[sz--];
    down(1);
}
int top(){
	return pq[1];
}
int n,t;
int main(){
	while(scanf("%d",&n)!=EOF){
		sz=0;
		for(int i = 0; i < n; i++){
			scanf("%d",&t);
			push(t);
		}
		if(sz==1){
			printf("0\n");
			continue;
		}
		ll ans=0;
		while(sz!=1){
			int a=top();pop();
			int b=top();pop();
			ans+=a+b;
			push(a+b);
		}
		printf("%lld\n",ans);
	}
	return 0;
}