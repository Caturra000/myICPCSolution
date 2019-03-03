#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
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
char str[MAXN];
char ans[MAXN];
int res[MAXN];
int suf[MAXN];
int main(){
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        memset(ans,0,sizeof ans);
        memset(res,0,sizeof res);
        scanf("%s",str+1);
        bool fflag=0;
        rep(i,1,n) res[i]+=max((int)str[i]-'a',(int)'z'-str[i]);
        suf[n+1]=0;
        rrep(i,n,1) suf[i]=suf[i+1]+res[i];
        rep(i,1,n){
            bool flag=0;
            rep(j,'a','z'){
                int t=abs((int)str[i]-j);
                if(i==n&&k-t==0){
                    k-=t;
                    flag=1;
                    ans[i]=j;
                    break;
                }
                else if(i!=n&&k-t>=0&&k-t<=suf[i+1]){
                    k-=t;
                    flag=1;
                    ans[i]=j;
                    break;
                }
            }
            if(flag==0){
                fflag=1;
                break;
            }
        }
        if(fflag==1){
            println(-1);
        }else{
            printf("%s\n",ans+1);
        }
    } 
    return 0;
}