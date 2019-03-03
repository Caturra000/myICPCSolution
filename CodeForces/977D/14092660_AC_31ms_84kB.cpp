#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e4+11;
const int INF = 0x3f3f3f3f;
typedef long long ll;
ll a[MAXN];
ll cnt(ll t){
    ll res=0;
    while(t%3==0){
        res++;
        t/=3;
    }
    return res;
}
bool cmp(ll a,ll b){
	ll ta=cnt(a),tb=cnt(b);
    if(ta==tb) return a<b;
    return ta>tb;
}
int main(){
    int n;
    while(cin>>n){
        rep(i,1,n) cin>>a[i];
        sort(a+1,a+1+n,cmp);
        rep(i,1,n) printf("%lld%c",a[i],i==n?'\n':' ');
    }
    return 0;
}