#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define clr(a,b) memset(a,b,sizeof a)
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 2e6+5e5+11;
const int oo = 0x3f3f3f3f;
int T[70];
struct ST{
	int L[maxn<<2],R[maxn<<2],minx[maxn<<2];
	int tot;
	void init(){
		clr(T,0);
		tot=0;
		L[0]=R[0]=0;
		minx[0]=oo;
	}
	void pu(int o){
		minx[o]=min(minx[L[o]],minx[R[o]]); 
	}
// 	void pd(int o){
// 		if(clear[o]){
// 			if(!L[o]){
// 				L[o]=++tot;
// 				L[L[o]]=R[L[o]]=0;
// 			}
// 			if(!R[o]){
// 				R[o]=++tot;
// 				L[R[o]]=R[R[o]]=0;
// 			}
// 			clear[L[o]]=clear[R[o]]=clear[o];
// 			minx[L[o]]=minx[R[o]]=oo;
// 			clear[o]=0;
// 		}
// 	}
	void update(int &o,int l,int r,int y,int x){
		if(!o){
			o=++tot;
			L[o]=R[o]=0;
			minx[o]=x;
// 			clear[o]=0;
		}
		if(l==r){
			minx[o]=min(minx[o],x);
			return ;
		}
// 		pd(o);
		int m=l+r>>1;
		if(y<=m) update(L[o],l,m,y,x);
		else update(R[o],m+1,r,y,x);
		pu(o);
	}
	int query(int &o,int l,int r,int LL,int RR){
		if(!o){
		    return oo;
// 			o=++tot;
// 			L[o]=R[o]=0;
// 			minx[o]=oo;

// 			clear[o]=0;
		}
		if(LL<=l&&r<=RR){
			return minx[o];
		}
// 		pd(o);
		int m=l+r>>1;
		int ans=oo;
		if(LL<=m) ans=min(ans,query(L[o],l,m,LL,RR));
		if(RR>m) ans=min(ans,query(R[o],m+1,r,LL,RR));
		return ans;
	}
}st; 
const int n = 1e6;
int main(){
	int op,x,y,yy1,yy2,c;
	st.init();
	while(scanf("%d",&op)!=EOF){
		if(op==3)break;
		else if(op==0) st.init();
		else if(op==1){
			scanf("%d%d%d",&x,&y,&c);
			st.update(T[c],1,n,y,x);
		}
		else if(op==2){
			scanf("%d%d%d",&x,&yy1,&yy2);
			int ans=0,tmp;
			rep(i,0,50){
				tmp=st.query(T[i],1,n,yy1,yy2);
				if(tmp<=x) ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}