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
const int maxn = 1e4+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char str[maxn];
int h[maxn],h2[maxn],st[maxn],dp[maxn];
bool ok[1111][1111]; 
int main(){
	int T=read();
	while(T--){
		s1(str);
		int n=strlen(str+1);
		memset(ok,0,sizeof ok);
		rep(i,1,n)st[i]=0;
		rep(i,1,n){
			h[i]=1;
			st[i-h[i]/2]=max(st[i-h[i]/2],h[i]);
			ok[i-h[i]/2][i-h[i]/2+h[i]-1]=1;
			int left=i-1,right=i+1;
			bool flag=0;
			while(!flag&&left>0&&right<n+1){
				if(str[left]==str[right]){
					h[i]=max(h[i],right-left+1);
					left--,right++;
					st[i-h[i]/2]=max(st[i-h[i]/2],h[i]);
					ok[i-h[i]/2][i-h[i]/2+h[i]-1]=1;
				}else{
					flag=1; 
				}
			}
			
		}
		rep(i,1,n){//中点为第i条缝 
			h2[i]=0;
			int left=i-1,right=i;
			bool flag=0;
			while(!flag&&left>0&&right<n+1){
				if(str[left]==str[right]){
					h2[i]=max(h2[i],right-left+1);
					left--,right++;
					st[i-h2[i]/2]=max(st[i-h2[i]/2],h2[i]);
					ok[i-h2[i]/2][i-h2[i]/2+h2[i]-1]=1;
				}else{
					flag=1;
				}
				
			}
			
		}
		memset(dp,0x3f,sizeof dp);
		dp[1]=1;dp[0]=0;
		rep(i,2,n){
			dp[i]=dp[i-1]+1;
			if(ok[1][i]){
				dp[i]=1;
				continue;
			}
			rep(j,1,i){
				if(ok[j][i]){//不能用起点最长回文串DP 
					dp[i]=min(dp[i],dp[j-1]+1);
				}
			}
		}
		println(dp[n]);
	}
	return 0;
}
