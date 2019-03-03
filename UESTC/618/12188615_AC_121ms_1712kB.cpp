#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
const int N = 1e6;
typedef long long ll;
bitset<maxn> isnprime;
ll prime2[maxn>>2];
int sai(){
    isnprime[0]=isnprime[1]=1;
    for(int i = 2; i*i < maxn; i++){
        if(!isnprime[i]){
            for(int j = 2*i; j < maxn; j += i){
                isnprime[j]=1;
            }
        }
    }
    int cnt=0;
    for(int i = 2; i < N; i++) if(!isnprime[i]) prime2[cnt++]=1ll*i*i;
    return cnt;
}
ll dfs(ll k,ll n,ll cnt){
    ll ans=0;
    for(ll i = k; i < cnt && prime2[i] <= n; i++){
        ans += n/prime2[i] - dfs(i+1,n/prime2[i],cnt);
    }
    return ans;
}
int main(){
    int cnt=sai();
    int T; scanf("%d",&T);
    while(T--){
        ll n; scanf("%lld",&n);
        ll ans = n - dfs(0,n,cnt);
        printf("%lld\n",ans);
    }
    return 0;
}