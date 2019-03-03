#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1e5+11;
const int INF = 0x3f3f3f3f;
typedef long long ll;
ll a[maxn];
ll n,s;
int C(int len){
    ll sum=0;
    for(int i = 1; i <= len; i++) sum+=a[i];
    if(sum>=s) return 1;
    for(int i = 1; i <= n-len; i++){
        sum-=a[i];sum+=a[i+len];
        if(sum>=s) return 1;
    }
    return 0;
}
int main(){
    while(scanf("%lld%lld",&n,&s)!=EOF){
        for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
        int l=1,r=n,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(C(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",C(r)?r:0);
    }
    return 0;
}