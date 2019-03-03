#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x7fffffff;
typedef long long ll;
ll to[maxn<<1],nxt[maxn<<1],cap[maxn<<1],flow[maxn<<1];
ll head[maxn],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(ll u,ll v,ll w){
    to[tot]=v;
    nxt[tot]=head[u];
    cap[tot]=w;
    flow[tot]=0;
    head[u]=tot++;
    swap(u,v);
    to[tot]=v;
    nxt[tot]=head[u];
    cap[tot]=0;
    flow[tot]=0;
    head[u]=tot++;
}
ll n,m,s,t;
ll dis[maxn],pre[maxn],cur[maxn],gap[maxn];
bool vis[maxn];
struct QUEUE{
    ll que[maxn];
    ll front,rear;
    void init(){front=rear=0;}
    void push(ll u){que[rear++]=u;}
    ll pop(){return que[front++];}
    bool empty(){return front==rear;}
}que;
void bfs(){
    memset(vis,0,sizeof vis);
    que.init();
    que.push(t);
    vis[t]=1;dis[t]=0;
    while(que.empty()^1){
        ll u = que.pop();
        for(ll i = head[u]; ~i; i = nxt[i]){
            register ll v=to[i],c=cap[i^1],f=flow[i^1];
            if(!vis[v]&&c>f){
                vis[v]=1;
                dis[v]=dis[u]+1;
                que.push(v);
            }
        }
    }
}
ll aug(){
    ll u=t,ans=oo;
    while(u!=s){
        ans=min(ans,cap[pre[u]]-flow[pre[u]]);
        u=to[pre[u]^1];
    }
    u=t;
    while(u!=s){
        flow[pre[u]]+=ans;
        flow[pre[u]^1]-=ans;
        u=to[pre[u]^1];
    }
    return ans;
}
ll isap(){
    ll ans=0;
    bfs();
    memset(gap,0,sizeof gap);
    memcpy(cur,head,sizeof head);
    for(ll i = 1; i <= n; i++) gap[dis[i]]++;
    ll u = s;
    while(dis[s]<n){
        if(u==t){
            ans+=aug();
            u=s;
        }
        bool ok=0;
        for(ll i = cur[u]; ~i; i = nxt[i]){
            ll v=to[i],c=cap[i],f=flow[i];
            if(c>f&&dis[u]==dis[v]+1){
                ok=1;
                pre[v]=i;
                cur[u]=i;
                u=v;
                break;
            }
        }
        if(!ok){
            ll mn=n-1;
            for(ll i = head[u]; ~i; i = nxt[i]){
                ll v=to[i],c=cap[i],f=flow[i];
                if(c>f) mn=min(mn,dis[v]);
            }
            if(--gap[dis[u]]==0) break;
            dis[u]=mn+1;gap[dis[u]]++;cur[u]=head[u];
            if(u!=s) u=to[pre[u]^1];
        }
    }
    return ans;
}
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//const int maxn = 1e5+11;
//const int oo = 0x7fffffff;
//typedef long long ll;
//ll to[maxn<<1],nxt[maxn<<1];
//ll cap[maxn<<1];
//ll flow[maxn<<1];
//ll head[maxn],tot;
//void init(){
//    memset(head,-1,sizeof head);
//    tot=0;
//}
//void add(ll u,ll v,ll w){
//    to[tot]=v;
//    nxt[tot]=head[u];
//    cap[tot]=w;
//    flow[tot]=0;
//    head[u]=tot++;
//    swap(u,v);
//    to[tot]=v;
//    nxt[tot]=head[u];
//    cap[tot]=w;
//    flow[tot]=0;
//    head[u]=tot++;
//}
//ll n,m,s,t;
//ll gap[maxn],dep[maxn],que[maxn];
//ll cur[maxn],stk[maxn];
//void bfs(){
//    memset(dep,-1,sizeof dep);
//    memset(gap,0,sizeof gap);
//    gap[0]=1;
//    ll front=0,rear=0;
//    que[rear++]=t;dep[t]=0;
//    while(front^rear){
//        ll u = que[front++];
//        for(ll i = head[u]; ~i; i = nxt[i]){
//            ll v=to[i];
//            if(~dep[v])continue;
//            que[rear++]=v;
//            dep[v]=dep[u]+1;
//            gap[dep[v]]++;
//        }
//    }   
//}
//ll isap(){
//    bfs();
//    memcpy(cur,head,sizeof head);
//    ll ans=0;ll top=0,u=s;
//    while(dep[s]<n){
//        if(u==t){
//            ll mn=oo;
//            ll inser;
//            for(ll i = 0; i < top; i++){
//                if(mn>cap[stk[i]]-flow[stk[i]]){
//                    mn=cap[stk[i]]-flow[stk[i]];
//                    inser=i;
//                }
//            }
//            for(ll i = 0; i < top; i++){
//                flow[stk[i]]+=mn;
//                flow[stk[i]^1]-=mn;
//            }
//            ans+=mn;
//            top=inser;
//            u=to[stk[top]^1];
//            continue;
//        }
//        bool flag=0;
//        ll v;
//        for(ll i = cur[u]; ~i; i = nxt[i]){
//            v=to[i];
//            if(cap[i]-flow[i]&&dep[v]+1==dep[u]){
//                flag=1;
//                cur[u]=i;
//                break;
//            }
//        }
//        if(flag){
//            stk[top++]=cur[u];
//            u=v;
//            continue;
//        }
//        ll mn=n;
//        for(ll i = head[u]; ~i; i = nxt[i]){
//            if(cap[i]-flow[i]&&dep[to[i]]<mn){
//                mn=dep[to[i]];
//                cur[u]=i;
//            }
//        }
//        gap[dep[u]]--;
//        if(!gap[dep[u]])return ans;
//        dep[u]=mn+1;
//        gap[dep[u]]++;
//        if(u!=s)u=to[stk[--top]^1];
//    }
//    return ans;
//}
ll a[maxn],b[maxn],c[maxn];
ll n1,m1,x,u,v,w;
bool C(double mid){//承受熊num 
	mid/=x;
	init();s=n1+1;t=s+1;n=t;
	for(ll i = 1; i <= m1; i++){
		add(a[i],b[i],(ll)c[i]/mid);
	}
	add(s,1,x);add(n1,t,oo);
	return isap()>=x;
}
//bool C(double mid){
//	double per=mid/x;
//	init();s=n1+1;t=s+1;n=t;
//	for(ll i = 1; i <= m1; i++){
//		add(a[i],b[i],(ll)c[i]/per);
//	}
//	add(s,1,mid);add(n1,t,oo);
//	return isap()>=x;
//}
int main(){
	while(scanf("%lld%lld%d",&n1,&m1,&x)!=EOF){
		for(ll i = 1; i <= m1; i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		}
		double l=0,r=1e12,mid;
		for(ll k = 1; k <= 200; k++){
			mid=(l+r)/2.0;
			if(C(mid)) l=mid;//一只熊带mid单位 
			else r=mid;
		}
		printf("%.10lf\n",(double)mid);
	}
	return 0;
} 