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
int main(){
    fastIO; 
    while(cin>>n>>m>>r>>k){
        vis.clear();
        __gnu_pbds::priority_queue<QAQ> que; que.push(QAQ(r,r));
        vis.insert(P(r,r));
        ll ans=0,cnt=0;
        while(!que.empty()){
            QAQ u=que.top();
            ans+=u.val;
            if(++cnt>=k)break;
            que.pop();
            rep(i,0,3){
                int x=dx[i]+u.x,y=dy[i]+u.y;
                if(x>=1&&x<=n&&y>=1&&y<=m&&vis.count(P(x,y))==0){
                    vis.insert(P(x,y));
                    que.push(QAQ(x,y));
                }
            }
        }
        cout<<fixed<<setprecision(12)<<(double)ans/(n-r+1)/(m-r+1)<<endl; 
    }
    return 0;
}