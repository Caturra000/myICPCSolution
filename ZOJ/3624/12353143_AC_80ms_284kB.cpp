#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int mod = 100000007;
typedef long long ll;
ll egcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    ll gcd=egcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-a/b*x;
    return gcd;
}
ll inv(ll m){
    ll x,y;
    egcd(m,mod,x,y);
    return (x%mod+mod)%mod;
}
ll C(ll n,ll m){
    ll up=1,down=1;
    if(m>n-m) m=n-m;
    rep(i,0,m-1){
        up=(up*(n-i))%mod;
        down=(down*(i+1))%mod;
    }
    return (up*inv(down))%mod;
}
int main(){
    ll n,m,p,q;
    while(cin>>m>>n>>p>>q){
        ll t1=C(m-p+q,q)%mod;
        ll t2=C(m+n,m)%mod;
        ll t3=C(m-p+n,n)%mod;
        ll t4=C(m+q,m)%mod;
        ll ans1=(t1*t2)%mod;
        ll ans2=(t3*t4)%mod;
        ll ans=((ans1-ans2)%mod+mod)%mod;
        cout<<ans<<endl;
    }
    return 0;
}
