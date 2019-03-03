#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
const int Limit = 1e6;
typedef unsigned long long ll;
ll phi[maxn];
void euler(int n){
    for(int i = 1; i <= n; i++){
        phi[i]=i;
    }
    for(int i = 2; i <= n; i++){
        if(phi[i]==i){
            for(int j = i; j <= n; j+=i){
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
vector<int> P;
void chai(int n){
    P.clear();
    for(ll i = 1; i*i <= n; i++){
        if(n%i==0){
            P.push_back(i);
            if(n/i!=i) P.push_back(n/i);
        }
    }
}
int n;
ll f[maxn],g[maxn];
bool vis[maxn];
int main(){
    euler(maxn-11);
    ll ans=0;
    // for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    // for(int i = 1; i <= 1000000; i++){
    //     if(vis[i]) continue;
    //     chai(i); vis[i]=1;
    //     for(int j = 0; j < P.size(); j++){
    //         ans+=phi[i/P[j]]*P[j];
    //     }
    //     ans-=i; f[i]=ans;
    //     // for(ll j = 1ll*i*i; j <= maxn-11; j*=i){
    //     //     if(j>=maxn||vis[j]) break;
    //     //     vis[j]=1; sum[j]=ans+i-j;
    //     // }
    // }

    for(int i = 1; i+i <= Limit; i++){
        for(int j = i<<1; j <= Limit; j+=i){
            f[j]+=phi[j/i]*i;
        }
    }
    for(int i = 1; i <= Limit; i++) g[i]=g[i-1]+f[i];
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%llu\n",g[n]);
    }
    return 0;
}