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
#include<ctime>
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
const int MAXN = 4e5+11;
const double EPS = 1e-7;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7; 
unsigned int SEED = 17;
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
ull p[MAXN];
int curlen;
struct Treap{
    int son[MAXN][2],root,tot;
    int val[MAXN],fix[MAXN],size[MAXN];
    bool flip[MAXN];
    ull Hash[MAXN][2];
    int stk[MAXN];
    #define lc son[o][0]
    #define rc son[o][1]
    void init(){
        root=0;
        son[0][0]=son[0][1]=0;
        val[0]=fix[0]=size[0]=0;
        flip[0]=0;
        Hash[0][0]=Hash[0][1]=0;
        tot=1;
    }
    int node(int v){
        son[tot][0]=son[tot][1]=0;
        val[tot]=v; fix[tot]=Rand();
        size[tot]=1;flip[tot]=0;
        Hash[tot][0]=Hash[tot][1]=v;
        return tot++;
    }
    void pu(int o){
        size[o]=size[lc]+size[rc]+1;
        Hash[o][0]=Hash[rc][0]+val[o]*p[size[rc]]+Hash[lc][0]*p[size[rc]+1];
        Hash[o][1]=Hash[lc][1]+val[o]*p[size[lc]]+Hash[rc][1]*p[size[lc]+1];
    }
    void rev(int o){
        swap(Hash[o][0],Hash[o][1]);
        swap(lc,rc);
        flip[o]^=1;
    }
    void pd(int o){
        if(flip[o]){
            if(lc) rev(lc);
            if(rc) rev(rc);
            flip[o]=0;
        }
    }
    void split(int o,int k,int &a,int &b){
        if(!o){
            a=b=0;
            return;
        }else if(k<=size[lc]){
            pd(o);
            b=o;
            split(lc,k,a,lc);
            pu(o);
        }else{
            pd(o);
            a=o;
            split(rc,k-size[lc]-1,rc,b);
            pu(o);
        }
    }
    int merge(int a,int b){
        if(!a) return b;
        if(!b) return a;
        if(a) pd(a); if(b) pd(b);
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
    void insert(int pos,int v){
        int a,b,t=node(v);
        split(root,pos,a,b);
        root=merge(merge(a,t),b);
    }
    int get(int pos){
        int a,b,x,y;
        split(root,pos-1,a,b);
        split(b,1,x,y);
        int t=x;
        root=merge(a,merge(x,y));
        return t;
    }
    void del(int pos){
        int a,b,x,y;
        split(root,pos-1,a,b);
        split(b,1,x,y);
        root=merge(a,y);
    }
    void revv(int pos,int len){//[pos,pos+len-1]
        int a,b,x,y;
        split(root,pos-1,a,b);
        split(b,len,x,y);
        rev(x);
        root=merge(a,merge(x,y));
    }
    ull get(int pos,int len){
        int a,b,x,y;
        split(root,pos-1,a,b);
        split(b,len,x,y);
        ull ans=Hash[x][0];
        root=merge(a,merge(x,y));
        return ans;
    }
    bool C(int mid,int st1,int st2){
    	if(mid==0)return 0;
    	if(st1==0||st2==0)return 0;
        return get(st1/*-mid+1*/,mid)==get(st2/*-mid+1*/,mid);
    }
    ll LCP(int a,int b){
        if(a==b)return a;
        int l=1,r=curlen-b+1,mid;
        while(l<r){
            mid=l+(r-l+1)/2;
            if(C(mid,a,b))l=mid;
            else r=mid-1;
        }
        return C(l,a,b)?l:0;
    }
    int build(char str[],int n){
    	int x,last=0,top=0;
    	rep(i,1,n){
    		x=node((int)str[i]),last=0;
    		while(top&&fix[stk[top]]>stk[x]){
    			pu(stk[top]),last=stk[top];
    			stk[top--]=0;
			}
			if(top) son[stk[top]][1]=x;
			son[x][0]=last;
			stk[++top]=x; 
		}
		while(top){
			pu(stk[top--]);
		}
		return stk[1];
	} 
}tp;
char str[MAXN];
int main(){
    p[0]=1;
    rep(i,1,MAXN-1) p[i]=p[i-1]*233;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        s1(str);
        curlen=n;
        tp.init();
        rep(i,1,n){
            tp.insert(i,(int)str[i]);
        }
        rep(i,1,m){
            int op=read();
            int a,b;
            switch(op){
                case 1:
                    a=read();
                    b=read();
                    tp.insert(a,b+'0');
                    curlen++;
                    break;
                case 2:
                    a=read();
                    tp.del(a);
                    curlen--;
                    break;
                case 3:
                    a=read();
                    b=read();
                    tp.revv(a,b-a+1);
                    break;
                case 4:
                    a=read();
                    b=read();
                    println(tp.LCP(a,b));
                    break;
            }
        }
    }
    return 0;
}