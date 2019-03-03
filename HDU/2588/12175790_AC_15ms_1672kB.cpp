#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
ll euler(int n){
    ll ans=n;
    for(ll i = 2; i*i <= n; i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans=ans/n*(n-1);//note
    return ans;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,m; ll ans=0;
        scanf("%d%d",&n,&m);
        for(ll i = 1; i*i<=n; i++){
            if(n%i==0){
                if(i>=m) ans+=euler(n/i);
                if(n/i>=m&&i*i!=n) ans+=euler(i);
            }
        }
        printf("%lld\n",ans);
    }
}