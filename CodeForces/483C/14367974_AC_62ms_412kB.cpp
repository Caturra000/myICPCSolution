#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int a[MAXN];
int main(){
    int n,k;
    while(cin>>n>>k){
        int cur1=1,cur2=n;
        rep(i,1,n){
            if(i&1) a[i]=cur1++;
            else a[i]=cur2--;
        }
        if(k&1) sort(a+k,a+1+n);
        else sort(a+k,a+1+n,greater<int>());
        rep(i,1,n){
            if(i==n) cout<<a[i]<<endl;
            else cout<<a[i]<<" ";
        }
        
    }
    return 0;
}