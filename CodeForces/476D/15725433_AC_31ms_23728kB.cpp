#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 1e6+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int rec[MAXN][6];
void init(){
    int mx=0;
    rep(i,1,100000){
        int t=mx+1&1;
        if(t){
            rep(j,1,4) rec[i][j]=mx+j+(j==4);
            mx+=5;
        }else{
            rep(j,1,4) rec[i][j]=mx+j+1+(j==4);
            mx+=6;
        }
    }
}
int n,k;
int main(){
    init();
    while(cin>>n>>k){
        int mx=rec[n][4]*k;
        println(mx);
        rep(i,1,n){
            rep(j,1,4){
                if(j==4) println(k*rec[i][j]);
                else printbk(k*rec[i][j]);
            }
        }
    }
    return 0;
} 