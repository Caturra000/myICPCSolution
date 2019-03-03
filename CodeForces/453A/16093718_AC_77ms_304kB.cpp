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
int main(){
    fastIO;
    int n,m;
    while(cin>>m>>n){
        double ans=0;
        for(int i=1;i<=m;i++) ans+=(double)i*(pow((double)i/m,n)-pow((double)(i-1)/m,n));
        cout<<fixed<<setprecision(12)<<ans<<endl;
    }
    return 0;
}