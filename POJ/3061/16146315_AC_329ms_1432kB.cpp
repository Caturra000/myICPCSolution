//#include<bits/stdc++.h>
//#include<ext/pb_ds/priority_queue.hpp>
//#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define rep(i,j,k) for( int i=j;i<=k;i++)
#define rrep(i,j,k) for( int i=j;i>=k;i--)
#define erep(i,u) for( int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define ll long long
//using namespace __gnu_pbds;
//using ll = long long;
//using P  = pair<ll,ll>;
const int MAXN = 1e5+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
ll a[MAXN];
int main(){
    fastIO;
    int T; cin>>T;
    while(T--){
        int n; ll  s;
        cin>>n>>s;
        rep(i,1,n) cin>>a[i];
        ll ans=INF;
        for(ll l=1,r=0,sum=0;l<=n;l++){
            while(sum<s&&r<n) sum+=a[++r];
            if(sum<s) break;
            ans=min(ans,r-l+1);
            sum-=a[l];
        }
        if(ans==INF) cout<<0<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}