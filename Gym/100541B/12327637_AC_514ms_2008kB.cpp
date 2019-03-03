#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
const int MOD = 1e6;
typedef long long ll;
ll H(ll n,ll j){
    ll ans=0;
    for(int i = 1; i <= j; i++) ans+=n/i;
    return ans;
}
ll C(ll n,ll gongxian){
    return gongxian*(n/gongxian-n/(gongxian+1));
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        ll n; scanf("%lld",&n);
        if(n<=20){
            printf("%lld\n",(H(n,n))%MOD);
            continue;
        }
        ll gen = sqrt(n);
        ll ans1 = H(n,gen);
        ll tmp = n/gen;
        ll cnt=gen;
        while(1){
            if(n/gen==n/(cnt+1)){
                ans1+=n/gen;
                cnt++;
            }
            else{
                cnt++;//start
                break;
            }
        }
        ll gongxian = n/cnt;
        ll ans2=0;
        while(gongxian){
            ans2+=C(n,gongxian);
            gongxian--;
        }
        printf("%lld\n",(ans1+ans2)%MOD);
    }
    return 0;
}