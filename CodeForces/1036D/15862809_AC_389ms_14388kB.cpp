#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 3e5+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
const int MOD = 1000000007;
ll read(){
   ll x=0,f=1;register char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
ll a[MAXN],b[MAXN],n,m;
ll sum1[MAXN],sum2[MAXN];
ll c[MAXN],d[MAXN]; 
int main(){
    while(cin>>n){
        rep(i,1,n) a[i]=read();
        m=read();
        rep(i,1,m) b[i]=read();
        int cur1=1,cur2=1;
        int lo=1;
        rep(i,1,n) sum1[i]=sum1[i-1]+a[i];
        rep(i,1,m) sum2[i]=sum2[i-1]+b[i];
        cur2=lower_bound(sum2+1,sum2+1+m,a[1])-sum2;
        int ans=0;
        if(sum2[cur2]==a[1]) lo++,cur1++,cur2++,ans++;
        while(cur1<=n&&cur2<=m){
            ll tmp=sum1[cur1]-sum1[lo-1];
            ll tmp2=sum2[cur2-1];
            int pos=lower_bound(sum2+1,sum2+m+1,tmp2+tmp)-sum2;
            if(sum2[pos]==tmp2+tmp){
                cur1++;
                ans++;
                cur2=pos+1;
                lo=cur1;
            }else{
                cur1++;
            }
        }
        int mx=-1;
        if(cur1==n+1&&cur2==m+1&&sum1[n]==sum2[m]){
            mx=max(mx,ans); 
        }
        
        rep(i,1,n) c[i]=a[i];
        rep(i,1,m) d[i]=b[i];
        rep(i,1,n) swap(b[i],c[i]);
        rep(i,1,m) swap(d[i],a[i]); 
        swap(n,m);
        
        cur1=1,cur2=1;
        lo=1;
        rep(i,1,n) sum1[i]=sum1[i-1]+a[i];
        rep(i,1,m) sum2[i]=sum2[i-1]+b[i];
        cur2=lower_bound(sum2+1,sum2+1+m,a[1])-sum2;
        ans=0;
        if(sum2[cur2]==a[1]) lo++,cur1++,cur2++,ans++;
        while(cur1<=n&&cur2<=m){
            ll tmp=sum1[cur1]-sum1[lo-1];
            ll tmp2=sum2[cur2-1];
            int pos=lower_bound(sum2+1,sum2+m+1,tmp2+tmp)-sum2;
            if(sum2[pos]==tmp2+tmp){
                cur1++;
                ans++;
                cur2=pos+1;
                lo=cur1;
            }else{
                cur1++;
            }
        }
        if(cur1==n+1&&cur2==m+1&&sum1[n]==sum2[m]){
            mx=max(mx,ans);
        }
        println(mx);
    }
    return 0; 
}