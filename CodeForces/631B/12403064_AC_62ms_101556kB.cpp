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
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct node2{
	int kind,las,val,pos;
	node2(){}
	node2(int k,int l,int v,int p){
		kind=k;las=l;
		val=v;pos=p;
	}
}b[maxn];
bool cmp(node2 a,node2 b){
	return a.las<b.las;
}
int mt[5003][5003];
int main(){
	int n,m,k,op;
	while(~iin(n)){
		m=read();k=read();
		int N=0,kind,pos,val;
		rep(i,1,n) b[i].kind=1;
		rep(i,n+1,n+m) b[i].kind=2;
		rep(i,1,n+m) b[i].val=b[i].las=0,b[i].pos=i>n?i-n:i;
		rep(i,1,k){
			kind=read();
			pos=read();
			val=read();
			if(kind==1){
				b[pos]=node2(1,i,val,pos);
			}else{
				b[n+pos]=node2(2,i,val,pos);
			}
		}
		sort(b+1,b+n+m+1,cmp);
		rep(i,1,n+m){
			if(b[i].kind==1){
				rep(j,1,m){
					mt[b[i].pos][j]=b[i].val;
				}
			}else if(b[i].kind==2){
				rep(j,1,n){
					mt[j][b[i].pos]=b[i].val;
				}
			}
		}
		rep(i,1,n) rep(j,1,m){
			if(j==m){
				println(mt[i][j]);
			}else{
				print(mt[i][j]);blank;
			}
		}
	}
	return 0;
} 