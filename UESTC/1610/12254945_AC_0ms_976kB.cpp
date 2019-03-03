#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn  = 100;
typedef long long ll;
const ll mod = 1e9+9;
int b[6][6]={
    {0,0,0,0,0,0},
    {0,1,0,0,1,0},
    {0,3,0,0,3,0},
    {0,0,1,1,0,1},
    {0,0,1,1,0,1},
    {0,0,2,2,0,1},
};
ll c[6]={0,4,12,12,12,24};
struct Mat{
    ll m[7][7],r,c;
    void node(int rr,int cc,bool unit=0){
        r=rr;c=cc;
        memset(m,0,sizeof m);
        if(unit) rep(i,1,rr) m[i][i]=1;
    }
};
Mat operator * (Mat a,Mat b){
    Mat ans;ans.node(a.r,b.c);
    rep(i,1,a.r){
        rep(j,1,b.c){
            // int t=max(a.r,b.c);
            rep(k,1,5){
                ans.m[i][j]+=(a.m[i][k]*b.m[k][j])%mod;
                ans.m[i][j]%=mod;
            }
        }
    }
    return ans;
}
Mat qmod(Mat a,ll n){
    Mat ans;ans.node(5,5,1);
    while(n){
        if(n&1) ans=ans*a;
        n>>=1;
        a=a*a;
    }
    return ans;
}
ll qmod(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1) ans=(ans%mod*a%mod)%mod;
        n>>=1;
        a=(a%mod*a%mod)%mod;
    }
    return ans%mod;
}
int main(){
    ll n;
    Mat base,base2; base.node(5,5); base2.node(5,1);
    rep(i,1,5) rep(j,1,5) base.m[i][j]=b[i][j];
    rep(i,1,5) base2.m[i][1]=c[i];
    while(scanf("%lld",&n)!=EOF){
        Mat tmp=qmod(base,n-3);
        Mat res=tmp*base2;
        // rep(i,1,5) rep(j,1,5) if(j==5) cout<<res.m[i][j]<<endl;else cout<<res.m[i][j]<<" ";
        ll ans=0;
        rep(i,1,5) {ans+=res.m[i][1]%mod;ans%=mod;}
        ans=(qmod(4,n)%mod-ans%mod+mod)%mod;
        if(ans<0) ans+=mod;
        printf("%lld\n",ans);
    }
    return 0;
}