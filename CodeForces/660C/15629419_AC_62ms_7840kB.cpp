#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
using namespace std;
const int MAXN = 1e6 + 11;
const int MOD = 1ll<<30;
typedef long long ll;
const ll INF = 1ll<<62;
ll read(){
    ll x = 0, f = 1; register char ch = getchar();
    while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x*f;
}
int sum[MAXN],a[MAXN];
int n,k; 
int main(){
    while(cin>>n>>k){
        rep(i,1,n){
            a[i]=read();
            sum[i]=sum[i-1]+bool(a[i]==0);
        }
        int best=0,l=0,r=0;
        rep(i,1,n){
            int t=sum[i];
            int lo=i,hi=n,mid;
            while(lo<hi){
                mid=lo+(hi-lo+1)/2;
                if(sum[mid]<=sum[i]+k-(1-a[i])) lo=mid;
                else hi=mid-1;
            }
            int pos=lo;
            if(sum[pos]<=(sum[i]+k-(1-a[i]))&&best<pos-i+1){
                best=pos-i+1;
                l=i;
                r=pos;
            }
        }
        println(best);
        rep(i,1,n-1){
            if(i>=l&&i<=r) printbk(1);
            else printbk(a[i]);
        }
        if(n<=r) println(1);
        else println(a[n]);
    }
    return 0;
}