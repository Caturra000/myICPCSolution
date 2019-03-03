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
int nxt[maxn],f[maxn],ans;
char T[maxn],P[maxn];
void buildNext(){
    int m=strlen(P+1);
    int j=0;
    nxt[1]=0;
    rep(i,2,m){
        while(j>0&&P[i]!=P[j+1]) j=nxt[j];
        if(P[i]==P[j+1])j++;
        nxt[i]=j;
    }
}
int main(){
	int t=read();
	while(t--){
		s1(P);buildNext();
		int m=strlen(P+1);
		int tmp=nxt[m];
		while(3*tmp>m&&tmp>0){
			tmp=nxt[tmp];
//			cout<<"tmp"<<tmp<<endl;
		}
		println(tmp);
	}
    return 0;
}