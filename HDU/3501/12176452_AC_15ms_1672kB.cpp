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
    ll t;
    while(scanf("%d",&t)!=EOF){
        if(t==0)break;
        printf("%lld\n",(t*(t-1)/2-euler(t)*t/2)%1000000007);
    }
    return 0;
}