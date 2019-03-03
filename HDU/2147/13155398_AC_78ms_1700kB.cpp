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
const int maxn = 2e3+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,r,c;
// int dp[maxn][maxn][2];//
// const int dx[]={0,1,1};
// const int dy[]={-1,0,-1};
// int dfs(int x,int y,int who){
//     if(x==r||y==1) return dp[x][y]=who;
//     if(~dp[x][y][who]) return dp[x][y][who];
//     int ans=0;
//     rep(i,0,2){
//         int xx=x+dx[i],yy=y+dy[i];
//         ans^=dfs(xx,yy,who^1);
//     }
//     return dp[x][y]=ans;
// }
int main(){
    while(cin>>r>>c){
        if(r==0&&c==0)break;
        if(min(r%2,c%2)==0) cout<<"Wonderful!"<<endl;
        else cout<<"What a pity!"<<endl;
    }
    return 0;
}
