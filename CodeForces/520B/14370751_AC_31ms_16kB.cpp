#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 4e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
    int n,m;
    while(cin>>n>>m){
        if(n>m){
            println(n-m);
        }else{
            int res=0;
            while(m>n){
                if(m&1){
                    m++;
                    res++;
                }else{
                    m>>=1;
                    res++;
                }
            }
            println(res+n-m);
        }
    }
    return 0;
}