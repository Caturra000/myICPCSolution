#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 1e5+11;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7; 
unsigned int SEED = 19260817;
const ll INF = 1ll<<60;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline int Rand(){
    SEED=SEED*1103515245+12345;
    return SEED/65536;
}
struct Treap{
    int son[MAXN][2],root,tot;
    int val[MAXN],fix[MAXN],size[MAXN];
    ll mx[MAXN];
    int que[MAXN];
    #define lc son[o][0]
    #define rc son[o][1]
    void init(){
        root=0;
        son[0][0]=son[0][1]=0;
        val[0]=fix[0]=size[0]=0;
        mx[0]=-INF;
        tot=1;
    }
    int node(int v,int q){
        son[tot][0]=son[tot][1]=0;
        val[tot]=v; fix[tot]=Rand();
        size[tot]=1;mx[tot]=v;que[tot]=q;
        return tot++;
    }
    void pu(int o){
        size[o]=size[lc]+size[rc]+1;
        mx[o]=max((ll)val[o],mx[lc]);
        mx[o]=max(mx[o],mx[rc]);
    }
    void split(int o,int k,int &a,int &b){
        if(!o){
            a=b=0;
            return;
        }else if(k<=size[lc]){
            b=o;
            split(lc,k,a,lc);
            pu(o);
        }else{
            a=o;
            split(rc,k-size[lc]-1,rc,b);
            pu(o);
        }
    }
    int merge(int a,int b){
        if(!a) return b;
        if(!b) return a;
        if(fix[a]<fix[b]){
            son[a][1]=merge(son[a][1],b);
            pu(a);
            return a;
        }else{
            son[b][0]=merge(a,son[b][0]);
            pu(b);
            return b;
        }
    }
    void insert(int pos,int v,int q){
        int a,b,t=node(v,q);
        split(root,pos,a,b);
        root=merge(merge(a,t),b);
    }
    int kth(int k){
        int o=root;
        while(1){
            if(k<=size[lc]){
                o=lc;
            }else if(k==size[lc]+1){
                return o;
            }else{
                k-=size[lc]+1;
                o=rc;
            }
        } 
    }
    int get(int pos){
    	int a,b,x,y;
    	split(root,pos-1,a,b);
    	split(b,1,x,y);
    	int t=x;
    	root=merge(a,merge(x,y));
    	return t;
	}
	int get(int pos,int len){//[pos,pos+len-1]
		int a,b,x,y;
		split(root,pos-1,a,b);
		split(b,len,x,y);
		int t=x;
		root=merge(a,merge(x,y));
		return t;
	}
	ll getmx(int pos,int len){//[pos,pos+len-1]
		int a,b,x,y;
		split(root,pos-1,a,b);
		split(b,len,x,y);
		ll t=mx[x];
		root=merge(a,merge(x,y));
		return t;
	}
}tp;
int n,p[MAXN],c[MAXN];
bool C(int st,int len){
	if(len==0)return 1;
//	int pos=tp.get(st-len+1,len);
//	ll tmp=tp.mx[pos]; //Wrong Answer
	ll tmp=tp.getmx(st-len+1,len);
	return p[st+1]>tmp;
}
int main(){
	while(cin>>n){
		rep(i,1,n){
			p[i]=read();
			c[i]=read();
		}
		tp.init(); tp.insert(1,p[1],1);
		rep(i,2,n){
			if(c[i]==0){
				tp.insert(i-1,p[i],i);
				continue;
			}
			// 枚举len
			int l=0,r=min(i-1,c[i]),mid;
			while(l<r){
				mid=l+(r-l+1)/2;
				if(C(i-1,mid)) l=mid;
				else r=mid-1;
			}
			if(C(i-1,l)) tp.insert(i-l-1,p[i],i);
			else tp.insert(i-1,p[i],i);
		}
		rep(i,1,n){
			int pos=tp.get(i);
			printf("%d%c",tp.que[pos],i==n?'\n':' ');	
		}
	}
	return 0;
}