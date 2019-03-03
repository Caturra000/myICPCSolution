#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 1e6+11;
typedef long long ll;
int heap[maxn],sz;
void down(int rt){
    int lc,rc;
    while(rt<sz){
        lc=rt<<1,rc=rt<<1|1;
        if(rc<=sz) lc=heap[lc]>heap[rc]?rc:lc;
        if(lc<=sz&&heap[rt]>heap[lc]){
            heap[rt]^=heap[lc];
            heap[lc]^=heap[rt];
            heap[rt]^=heap[lc];
        }
        else return;
        rt=lc;
    }
}
void up(int rt){
    while(rt!=1&&heap[rt]<heap[rt/2]){
        heap[rt]^=heap[rt/2];
        heap[rt/2]^=heap[rt];
        heap[rt]^=heap[rt/2];
        rt>>=1;
    }
}
void push(int k){
    heap[++sz]=k;
    up(sz);
}
void pop(){
    heap[1]=heap[sz--];
    down(1);
}
int top(){
	return heap[1];
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