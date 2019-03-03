#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[MAXN],n;
long double sum[MAXN];
map<int,int> mp;
int main(){
    while(cin>>n){
        rep(i,1,n) a[i]=read();
        rep(i,1,n) sum[i]=sum[i-1]+a[i];
        mp.clear();
        long double res=0;
        rep(j,1,n){
            mp[a[j]]++;
            res+=(long double)a[j]*j-sum[j];
            if(mp[a[j]-1]) res-=mp[a[j]-1];
            if(mp[a[j]+1]) res+=mp[a[j]+1];
        }
        printf("%.0Lf",res+1e-5);
    }
    return 0;
} 