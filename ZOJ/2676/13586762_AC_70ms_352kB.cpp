#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define repp(i,j,k) for(int i = j; i < k; i++)
#define rrep(i,j,k) for(int i = j; i >= k; i--)
#define erep(i,u) for(int i = head[u]; ~i; i = nxt[i])
#define scan(a) scanf("%d",&a)
#define scann(a,b) scanf("%d%d",&a,&b)
#define scannn(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define println(a) printf("%d\n",a)
#define printbk(a) printf("%d ",a)
#define print(a) printf("%d",a)
using namespace std;
const int maxn = 1e3+11;
const double oo = 1e12;
const double eps = 1e-7;
typedef long long ll;
int to[maxn<<1],nxt[maxn<<1];
double cap[maxn<<1];
int head[maxn],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,double w){
    to[tot]=v;
    nxt[tot]=head[u];
    cap[tot]=w;
//    flow[tot]=0;
    head[u]=tot++;
    swap(u,v);
    to[tot]=v;
    nxt[tot]=head[u];
    cap[tot]=w;
//    flow[tot]=0;
    head[u]=tot++;
}
//int n,m,s,t;
//int dis[maxn],pre[maxn],cur[maxn],gap[maxn];
//bool vis[maxn];
//struct QUEUE{
//    int que[maxn]; 
//    int front,rear;
//    void init(){front=rear=0;}
//    void push(int u){que[rear++]=u;}
//    int pop(){return que[front++];}
//    bool empty(){return front==rear;}
//}que;
//void bfs(){
//    memset(vis,0,sizeof vis);
//    que.init();
//    que.push(t);
//    vis[t]=1;dis[t]=0;
//    while(que.empty()^1){
//        int u = que.pop();
//        for(int i = head[u]; ~i; i = nxt[i]){
//            register int v=to[i];
//            double c=cap[i^1],f=flow[i^1];
//            if(!vis[v]&&fabs(c-f)>eps){
//                vis[v]=1;
//                dis[v]=dis[u]+1;
//                que.push(v);
//            }
//        }
//    }
//}
//double aug(){
//    int u=t; double ans=oo;
//    while(u!=s){
//        ans=min(ans,cap[pre[u]]-flow[pre[u]]);
//        u=to[pre[u]^1];
//    }
//    u=t;
//    while(u!=s){
//        flow[pre[u]]+=ans; 
//        flow[pre[u]^1]-=ans;
//        u=to[pre[u]^1];
//    }
//    return ans;
//}
int h[maxn],num[maxn],vis[maxn];
int s,t,n,m;
double aug(int u,double flow){  //   double!!!
	if(u==t) return flow;
	double l=flow;
	int tmp=n-1;
	erep(i,u){
		int v=to[i];
		if(h[u]==h[v]+1&&cap[i]>eps){
			double f=aug(v,min(l,cap[i]));
			l-=f;cap[i]-=f;cap[i^1]+=f;
			if(l<eps||h[s]==n) return flow-l;
		}
		if(cap[i]>eps&&h[v]<tmp) tmp=h[v];
	}
	if(l==flow){
		num[h[u]]--;
		if(num[h[u]]==0) h[s]=n;
		else{
			h[u]=tmp+1;
			num[h[u]]++;
		}
	}
	return flow-l;
}
double isap(){
	double ans=0;
	memset(h,0,sizeof h);
	memset(num,0,sizeof num);
	num[0]=n;
	while(h[s]<n) ans+=aug(s,oo);
	return ans;
}
//double isap(){
//    double ans=0;
//    bfs();
//    memset(gap,0,sizeof gap);
//    memcpy(cur,head,sizeof head);
//    memset(dis,0,sizeof dis);
//    for(int i = 1; i <= n; i++) gap[dis[i]]++;
//    int u = s;
//    while(dis[s]<n){
//        if(u==t){
//            ans+=aug();
//            u=s;
//        }
//        bool ok=0;
//        for(int i = cur[u]; ~i; i = nxt[i]){
//            int v=to[i];
//			double c=cap[i],f=flow[i];
//            if(fabs(c-f)>eps&&dis[u]==dis[v]+1){
//                ok=1;
//                pre[v]=i;
//                cur[u]=i;
//                u=v;
//                break;
//            }
//        }
//        if(!ok){
//            int mn=n-1;
//            for(int i = head[u]; ~i; i = nxt[i]){
//                int v=to[i];
//				double c=cap[i],f=flow[i];
//                if(fabs(c-f)>eps) mn=min(mn,dis[v]);
//            }
//            if(--gap[dis[u]]==0) break;
//            dis[u]=mn+1;gap[dis[u]]++;cur[u]=head[u];
//            if(u!=s) u=to[pre[u]^1];
//        }
//    }
//    return ans;
//}
void dfs(int u){
	erep(i,u){
		int v=to[i];
		if(cap[i]>eps&&!vis[v]){
			vis[v]=1;
			dfs(v);
		}
	}
}
int a[maxn],b[maxn];
double c[maxn];
bool C(double lambda){
	init();
	double ans=0;
	rep(i,1,m){
		if(c[i]-lambda<0){
			ans+=c[i]-lambda; 
		}else{
			add(a[i],b[i],c[i]-lambda);
		}
	}
	ans+=isap();
	return ans>eps;
}
int main(){
    while(cin>>n>>m){
        rep(i,1,m) cin>>a[i]>>b[i]>>c[i];
        s=1;t=n;
        double lo=0,hi=1e8,mid;
        rep(i,1,50){
        	mid=(hi+lo)/2.0;
        	if(C(mid)) lo=mid;
        	else hi=mid;
		}
		double lambda=mid;
		memset(vis,0,sizeof vis);
		vis[s]=1; dfs(s);
		int ans=0; vector<int> vec;
		rep(i,1,m){
			if(vis[a[i]]+vis[b[i]]==1||c[i]+eps<lambda){
				ans++;
				vec.push_back(i); 
			}
		}
		println(ans);
		for(int i=0;i<vec.size();i++){
			if(i==vec.size()-1)println(vec[i]);
			else printf("%d ",vec[i]);
		}
    }
    return 0;
}