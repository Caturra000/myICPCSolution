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
char str[4][MAXN];
int ans[4],len[4];
int cnt[555],n;
int main(){
    while(cin>>n){
        rep(i,1,3) scanf("%s",str[i]+1);
        rep(i,1,3) len[i]=strlen(str[i]+1);
        rep(i,1,3) ans[i]=0;
        rep(i,1,3){
            memset(cnt,0,sizeof cnt);
            rep(j,1,len[i]) cnt[str[i][j]]++;
            int mx=0;
            rep(j,1,554) mx=max(mx,cnt[j]);
            if(mx==len[i]){
                if(n==1){
                    if(len[i]==1) ans[i]=1;
                    else ans[i]=len[i]-1;
                }else ans[i]=len[i];
            }else{
                if(mx+n<=len[i]) ans[i]=mx+n;
                else{
                    int t=len[i]-(mx+n);
                    if(t==1) ans[i]=len[i]-1;
                    else ans[i]=len[i];
                }
            }
        }
        if(ans[1]>ans[2]&&ans[1]>ans[3]) printf("Kuro\n");
        else if(ans[2]>ans[1]&&ans[2]>ans[3]) printf("Shiro\n");
        else if(ans[3]>ans[1]&&ans[3]>ans[2]) printf("Katie\n");
        else printf("Draw\n");
    }
    return 0;
} 