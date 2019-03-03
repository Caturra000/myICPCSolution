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
int nxt[maxn],head[maxn],id1[maxn],id2[maxn],tot;
int a[1003];
inline int Hash(int x){
	return (((x<<1)+(x>>1))&0x7f7f7f7f)%maxn;
}
void init(){
	memset(head,-1,sizeof head);
	tot=0;
}
void add(int i,int j){
	int val=Hash(a[i]+a[j]);
	id1[tot]=i;id2[tot]=j;
	nxt[tot]=head[val];
	head[val]=tot++;
}
bool get(int ii,int jj,int cha){
	int val=Hash(cha);
	for(int i=head[val];~i;i=nxt[i]){
		int x=id1[i],y=id2[i];
		if(cha==a[x]+a[y]&&x!=ii&&y!=jj&&x!=jj&&y!=ii) return 1;
	}
	return 0;
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		init();
		rep(i,1,n) scanf("%d",&a[i]);
		rep(i,1,n) rep(j,i+1,n) add(i,j);
		int mx=-oo;
		rep(i,1,n) rep(j,i+1,n){
			int cha=a[i]-a[j];
			if(get(i,j,cha)){
				mx=max(a[i],mx);
			}
			int cha2=a[j]-a[i];
			if(get(j,i,cha2)){
				mx=max(a[j],mx);
			}
		}
		if(mx==-oo) printf("no solution\n");
		else println(mx);
	}
	return 0;
}