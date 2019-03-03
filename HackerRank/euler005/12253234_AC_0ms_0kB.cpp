#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn  = 100;
typedef long long ll;
ll ans[maxn];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int main(){
    ll last=ans[1]=1;ans[0]=0;
    for(int i = 2; i <= 40; i++){
        ans[i]=lcm(last,i);
        last=ans[i];
    }
    int T,n; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}