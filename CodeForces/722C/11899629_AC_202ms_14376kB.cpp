#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
const ll oo = 1ll*100000*(2e9+2e8);
typedef long long BIG;
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
#define scanL(a) scanf("%lld",&a)
#define scann(a,b) scanf("%d%d",&a,&b)
#define scannn(a,b,c) scanf("%d%d%d",&a,&b,&c)
struct ST{
	BIG maxS[maxn<<2],sum[maxn<<2],maxL[maxn<<2],maxR[maxn<<2];
	#define lc o<<1
	#define rc o<<1|1
	inline BIG max(BIG a,BIG b){
		return a>b?a:b;
	}
	void pu(int o){
		sum[o]=sum[lc]+sum[rc];
		maxL[o]=max(maxL[lc],sum[lc]+maxL[rc]);
		maxR[o]=max(maxR[rc],sum[rc]+maxR[lc]);
		maxS[o]=max(maxS[lc],maxS[rc]);
		maxS[o]=max(maxS[o],max(maxL[lc],maxR[rc]));
		maxS[o]=max(maxS[o],maxR[lc]+maxL[rc]);
	}
	void build(int o,int l,int r){
		if(l==r){
			int t;
			scan(t);
			maxS[o]=sum[o]=maxL[o]=maxR[o]=t;
			return;
		}
		int m=l+r>>1;
		build(lc,l,m);
		build(rc,m+1,r);
		pu(o);
	}
	void update(int o,int l,int r,int k){
		if(l==r){
			maxS[o]=sum[o]=maxL[o]=maxR[o]=-oo;
			return;
		}
		int m = l+r >> 1;
		if(k<=m) update(lc,l,m,k);
		else update(rc,m+1,r,k);
		pu(o);
	}
	ll query(int o,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			return maxS[o];
		}
		int m=l+r>>1;
		BIG ans=-oo;
		if(L<=m) ans=max(ans,query(lc,l,m,L,R));
		if(R>m) ans=max(ans,query(rc,m+1,r,L,R));
		return ans;
	}
}st;
stack<int> s;
void out(BIG a){
	if(a==0){
		printf("0");
		return;
	}
	while(a){
		int b=a%10;
		s.push(b);
		a/=10;
	}
	while(!s.empty()){
		printf("%d",s.top());
		s.pop();
	}
}
int main(){
	int n,x; 
	while(scan(n)!=EOF){
		st.build(1,1,n);
		rep(i,1,n){
			scan(x);
			st.update(1,1,n,x);
			if(i==n) printf("0");
			else out(st.query(1,1,n,1,n));
			printf("\n");
		}
	}
	return 0; 
}