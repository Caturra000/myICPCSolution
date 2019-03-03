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
const int MAXN = 2e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7; 
unsigned int SEED = 19260817;
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
    #define lc son[o][0]
    #define rc son[o][1]
    void init(){
        root=0;
        son[0][0]=son[0][1]=0;
        val[0]=fix[0]=size[0]=0;
        tot=1;
    }
    int node(int v){
        son[tot][0]=son[tot][1]=0;
        val[tot]=v; fix[tot]=Rand();
        size[tot]=1;
        return tot++;
    }
    void pu(int o){
        size[o]=size[lc]+size[rc]+1;
    }
    void split(int o,int pivot,int &a,int &b){
        if(!o){
            a=b=0;
            return;
        }else if(val[o]>pivot){
            b=o;
            split(lc,pivot,a,lc);
            pu(o);
        }else{
            a=o;
            split(rc,pivot,rc,b);
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
	void insert(int v){
		int a,b,t=node(v);
		split(root,v,a,b);
		root=merge(merge(a,t),b);
	}
	void del(int x){
		int a,b,c,d;
		split(root,x,a,b);
		split(a,x-1,c,d);
		d=merge(son[d][0],son[d][1]);//d的根不要了
		root=merge(merge(c,d),b);
	}
	int krank(int k){
		int a,b;
		split(root,k-1,a,b);
		int res=size[a]+1; //最小的相同数必然是恰比k-1子树规模大 
		root=merge(a,b);
		return res;
	}
	int kth(int k,int o=0){
		if(!o) o=root;
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
	int pre(int x){
		int a,b;
		split(root,x-1,a,b);
		int t=kth(size[a],a);
		root=merge(a,b);
		return t;
	}
	int succ(int x){
		int a,b;
		split(root,x,a,b);
		int t=kth(1,b);
		root=merge(a,b);
		return t;
	}
}tp;
int n,m,a[MAXN];
int main(){
    while(cin>>n){
    	tp.init();
    	rep(i,1,n){
    		int op=read();
			int x=read();
    		switch(op){
    			case 1:tp.insert(x);break;
    			case 2:tp.del(x);break;
    			case 3:println(tp.krank(x));break;
    			case 4:println(tp.val[tp.kth(x)]);break;
    			case 5:println(tp.val[tp.pre(x)]);break;
    			case 6:println(tp.val[tp.succ(x)]);break;
			}
		}
	}
    return 0;
}