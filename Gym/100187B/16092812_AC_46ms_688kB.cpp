#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#define rep(i,j,k) for( int i=j;i<=k;i++)
#define rrep(i,j,k) for( int i=j;i>=k;i--)
#define erep(i,u) for( int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
const int MAXN = 4e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
using ll = long long;
using P  = pair<ll,ll>;
set<P> vis;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int n,m,r,k;
ll cover(int x,int y){return (ll)(min(n,x+r-1)-max(x,r)+1)*(min(m,y+r-1)-max(y,r)+1);}
struct QAQ{
    int x,y;
    ll val;
    QAQ(int xx=0,int yy=0){x=xx,y=yy,val=cover(xx,yy);}
    bool operator < (const QAQ &orz) const{return val<orz.val;}
};
char str[MAXN];
int cnt[27];
int main(){
    fastIO; 
    while(cin>>str+1){
        memset(cnt,0,sizeof cnt);
        int len=0;
        for(int i=1;str[i];i++) cnt[str[i]-'a']++,++len;
        double ans=0;
        for(int i=0;i<26;i++) ans+=(double)cnt[i]*cnt[i]/len;
        cout<<fixed<<setprecision(12)<<ans<<endl;
    }
    return 0;
}
