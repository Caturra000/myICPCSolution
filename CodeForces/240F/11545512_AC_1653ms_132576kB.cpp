#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;

char str[maxn];
int a[26][maxn];
struct ST{
    #define lc o<<1
    #define rc o<<1|1
    int num[maxn<<2],lazy[maxn<<2],lazy2[maxn<<2];
    void pu(int o){
        num[o]=num[lc]+num[rc];
    }
    void pd(int o,int l,int r){
    	if(~lazy[o]){
    		int m = l+r>>1;
			lazy[lc]=lazy[rc]=lazy[o];
    		num[lc]=lazy[o]*(m-l+1);
    		num[rc]=lazy[o]*(r-m);
    		lazy[o]=-1;
		}
	}
    void build(int o,int l,int r,int i){
    	lazy[o]=-1;
        if(l==r){
            num[o]=a[i][l];
            return;
        }
        int m = l+r>>1;
        build(lc,l,m,i);
        build(rc,m+1,r,i);
        pu(o);
    }
    void update(int o,int l,int r,int L,int R,int v){
        if(L<=l&&r<=R){
            lazy[o]=v;
            num[o]=lazy[o]*(r-l+1);
            return;
        }
        pd(o,l,r);
        int m=l+r>>1;
        if(L<=m) update(lc,l,m,L,R,v);
        if(R>m) update(rc,m+1,r,L,R,v);
        pu(o);
    }
    void pd2(int o,int l,int r,int L,int R){
    	lazy[o]=num[lc]=num[rc]=lazy[lc]=lazy[rc]=0;
	}
    inline void clean(int o,int l,int r,int L,int R){
//        if(L<=l&&r<=R){
//        	lazy2[o]=0;
//            num[o]=0;
//            return;
//        }
//        pd(o,l,r);
//        int m = l+r>>1;
//        if(L<=m)clean(lc,l,m,L,R);
//        if(R>m)clean(rc,m+1,r,L,R);
//        pu(o);
		update(o,l,r,L,R,0);
    }
    ll query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return num[o];
        }
        pd(o,l,r);
        int m = l+r>>1;
        ll ans = 0;
        if(L<=m) ans+=query(lc,l,m,L,R);
        if(R>m) ans+=query(rc,m+1,r,L,R);
        return ans;
    }
}st[26]; 
int n,m,li,ri,pos;
int t[26],odd,even;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF){
//    	for(int i = 0; i < 26; i++)st[i].init();
        memset(a,0,sizeof a);
        scanf("%s",str+1);
        for(int i = 1; i <= n; i++){
            a[str[i]-'a'][i]++;
        }
        for(int i = 0; i < 26; i++){
            st[i].build(1,1,n,i);
        } 
        for(int i = 1; i <= m; i++){
            scanf("%d%d",&li,&ri);
            int shift=0;
            odd=even=pos=0;pos--;
            for(int j = 0; j < 26; j++){
                t[j]=st[j].query(1,1,n,li,ri);
                if(t[j]&1){odd++;pos=j;}
                else even++;
            }
//            
            if(odd>1)continue;
            else{
            	int lii=li,rii=ri;
            	if(~pos)t[pos]--; 
            	for(int j = 0; j < 26; j++){
            		if(pos==j)st[j].clean(1,1,n,lii,rii);
            		if(0==t[j])continue;
            		st[j].clean(1,1,n,lii,rii);
            		st[j].update(1,1,n,li,li+(t[j]/2)-1,1);
            		li+=(t[j]/2);
				}
				for(int j = 0; j < 26; j++){
					if(t[j]==0)continue;
					st[j].update(1,1,n,ri-(t[j]/2)+1,ri,1);
					ri-=(t[j]/2);
				}
                if(~pos){
                    if(t[pos]!=-1){
                    	st[pos].update(1,1,n,li,ri,1);
					}
                }
            }
        }
//        
        for(int i = 1; i <= n; i++){ 
            int tmp=-1;
            for(int j = 0; j < 26; j++){
                if(st[j].query(1,1,n,i,i)){tmp=j;break;}
            }
            char opt=tmp+'a';
            if(i==n) printf("%c\n",opt);
            else printf("%c",opt);
        }
    }
    return 0;
}