#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll fpw(ll a,ll n,ll mod){
    ll ans=1;
    while(n){
        if(n&1) ans=(ans*a)%mod;
        n>>=1;a=(a*a)%mod;
    }
    return ans;
}
int main(){
    ll a,m,n,k,T; cin>>T;
    while(T--){
        cin>>a>>m>>n>>k;
        cout<<(fpw(a,gcd(m,n),k)-1+k)%k<<endl;
    }
    return 0;
}