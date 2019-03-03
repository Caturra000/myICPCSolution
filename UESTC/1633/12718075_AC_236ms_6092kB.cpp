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
const int maxn = 1e6+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
typedef pair<int,int> P;
int dis[maxn],n,a[maxn];
bool vis[maxn];
void dijkstra(int s){
	memset(dis,oo,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<int,vector<int>,greater<int> > que;
	dis[s]=0;
	que.push(s);
	while(!que.empty()){
		int u=que.top(); que.pop();
		if(vis[u%a[1]]) continue;
		vis[u%a[1]]=1;
		rep(i,0,n){
			if(dis[(u+a[i])%a[1]]>u+a[i]){
				dis[(u+a[i])%a[1]]=u+a[i];
				que.push(u+a[i]);
			}
		}
	}
}
int main(){
	while(~iin(n)){
		rep(i,1,n) a[i]=read();
		nth_element(a+1,a+1,a+1+n);
		dijkstra(0);
		int q=read();
		rep(i,1,q){
			int t=read();
//			cout<<dis[t%a[1]]<<endl;
			if(dis[(t%a[1])]<=t) printf("YES\n");
			else printf("NO\n");
		}
	} 
	return 0;
}