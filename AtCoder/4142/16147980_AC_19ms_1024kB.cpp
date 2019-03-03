#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#define rep(i,j,k) for( int i=j;i<=k;i++)
#define rrep(i,j,k) for( int i=j;i>=k;i--)
#define erep(i,u) for( int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using P  = pair<ll,ll>;
const int MAXN = 1e6+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
int a[MAXN],n;
int main(){
    fastIO;
    while(cin>>n){
        rep(i,1,n) cin>>a[i];
        ll ans=0;
        for(int l=1,r=0,sum=0;l<=n;l++){
            while(r<n&&(sum^a[r+1])==sum+a[r+1]) sum+=a[++r];
            ans+=r-l+1;
            sum^=a[l];
        }
        cout<<ans<<endl;
    }
    return 0;
}