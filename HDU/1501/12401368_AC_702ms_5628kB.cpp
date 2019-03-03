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
char str1[maxn],str2[maxn],str3[maxn];
int dp[1003][1003];
int main(){
	int T=read(),kase=0;
	while(T--){
		s1(str1);s1(str2);s1(str3);
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		dp[1][0]=(str1[1]==str3[1]);
		dp[0][1]=(str2[1]==str3[1]);
		int len1=strlen(str1+1),len2=strlen(str2+1);
		rep(i,0,len1){
			rep(j,0,len2){
				if(i-1>=0&&dp[i-1][j]&&str1[i]==str3[i+j]) dp[i][j]=1;
				if(j-1>=0&&dp[i][j-1]&&str2[j]==str3[i+j]) dp[i][j]=1;
			}
		}
		if(dp[len1][len2]) printf("Data set %d: yes\n",++kase);
		else printf("Data set %d: no\n",++kase);
	} 
	return 0;
} 