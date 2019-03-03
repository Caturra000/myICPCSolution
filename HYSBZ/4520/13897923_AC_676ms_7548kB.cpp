#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
const int INF = 0x7fffffff;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int D;
struct point{
    int x[2];
    bool operator < (const point &rhs) const{
        return x[D]<rhs.x[D];
    }
};
struct KD{
    int son[MAXN][2];
    point p[MAXN],mn[MAXN],mx[MAXN];
    int root,ans,tot,n;
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    void init(int t){
        ans=INF; tot=D=0; n=t;
    }
    void pu(int o){
        rep(i,0,1){
            if(son[o][i]) rep(j,0,1){
                if(mn[son[o][i]].x[j]<mn[o].x[j]) mn[o].x[j]=mn[son[o][i]].x[j];
                if(mx[son[o][i]].x[j]>mx[o].x[j]) mx[o].x[j]=mx[son[o][i]].x[j];
            }
        }
    }
    int build(int now,int l,int r){
        int mid=l+r>>1;
        tot++; son[mid][0]=son[mid][1]=0;
        D=now;nth_element(p+l,p+mid,p+r+1);//[l,r+1)
        mn[mid].x[0]=mx[mid].x[0]=p[mid].x[0];
        mn[mid].x[1]=mx[mid].x[1]=p[mid].x[1];
        if(l<mid) son[mid][0]=build(now^1,l,mid-1);
        if(r>mid) son[mid][1]=build(now^1,mid+1,r);
        pu(mid);
        return mid;
    }
    void insert(int &o,int now,point v){
        if(!o){
            o=++tot;
            p[o].x[0]=mn[o].x[0]=mx[o].x[0]=v.x[0];
            p[o].x[1]=mn[o].x[1]=mx[o].x[1]=v.x[1];
        }else{
            insert(son[o][p[o].x[now]<v.x[now]],now^1,v);
            pu(o);
        }
    }
    inline ll dis(point a,point b){
        return (ll)(a.x[0]-b.x[0])*(a.x[0]-b.x[0])+1ll*(a.x[1]-b.x[1])*(a.x[1]-b.x[1]);
    }
    inline point mp(int x,int y){
    	point t;t.x[0]=x;t.x[1]=y;return t;
	}
    inline ll eva(int o,point &v){
    	if(!o) return -6666;
        ll t1=max(abs(mn[o].x[0]-v.x[0]),abs(mx[o].x[0]-v.x[0]));
		ll t2=max(abs(mn[o].x[1]-v.x[1]),abs(mx[o].x[1]-v.x[1]));
    	return t1*t1+t2*t2;
    }
	void query(int o,point &v){
		if(!o)return;
		while(pq.size()>2*n) pq.pop(); 
		ll d1=dis(p[o],v),d2=-6666,d3=-6666;
        if(pq.top()<d1){
        	pq.pop();
        	pq.push(d1);
		}
		if(son[o][0]) d2=eva(son[o][0],v);
		if(son[o][1]) d3=eva(son[o][1],v);
		if(d2>d3){
			if(d2>pq.top()) query(son[o][0],v);
			if(d3>pq.top()) query(son[o][1],v);
		}else{
			if(d3>pq.top()) query(son[o][1],v);
			if(d2>pq.top()) query(son[o][0],v);
		}
	}
}kd;
int main(){
    int n,k;
    while(cin>>n>>k){
        kd.init(k);
        rep(i,1,n){
            kd.p[i].x[0]=read();
            kd.p[i].x[1]=read();
        }
        kd.root=kd.build(0,1,n);
        while(!kd.pq.empty()) kd.pq.pop();
        rep(i,1,2*k) kd.pq.push(-666);
        rep(i,1,n){
            kd.query(kd.root,kd.p[i]);
        }
        println(kd.pq.top());
    }
    return 0;
}