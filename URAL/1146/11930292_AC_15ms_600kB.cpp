#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
#define println(a) printf("%lld\n",a)
using namespace std;
const int maxn = 2e2+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
ll mp[maxn][maxn];
int n,t;
int main(){
    while(scan(n)!=EOF){
        rep(i,1,n) rep(j,1,n){
            scan(t);
            mp[i][j]=mp[i][j-1]+t;
        }
        ll ans=-oo;
        rep(i,1,n) rep(j,i,n){
            ll sum=0;
            rep(k,1,n){
                if(sum>0) sum+=mp[k][j]-mp[k][i-1];
                else sum=mp[k][j]-mp[k][i-1];
                ans=max(ans,sum);
            }
        }
        println(ans);
    }
    return 0;
}