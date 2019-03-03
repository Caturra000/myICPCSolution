#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 4e6+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[MAXN],biao[MAXN],n,sum[MAXN];
int main(){
    while(cin>>n){
        rep(i,1,n) a[i]=read();
        int mx=-1;
        rep(i,1,n) mx=max(a[i],mx);
        sort(a+1,a+1+n);
        memset(biao,0,sizeof biao);
        rep(i,1,n) biao[a[i]]++;
        rep(i,1,MAXN-1) sum[i]=sum[i-1]+biao[i];
        ll ans=0;
        rep(i,1,mx){
            if(biao[i]==0) continue;
            ll t=0;
            int Limit=MAXN>>1;
            for(int j=i;j<=Limit;j+=i){
                int cnt=sum[j+i-1]-sum[j-1];
                t+=(ll)cnt*j;
            }
            ans=max(t,ans);
        }
        println(ans);
    }
    return 0;
}