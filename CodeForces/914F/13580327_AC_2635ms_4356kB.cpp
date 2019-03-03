#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<bitset>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 1e5+30;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7; 
unsigned int SEED = 19260817;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
bitset<MAXN> bs,cc[32];
char tmp[MAXN],str[MAXN];
int main(){
    while(~scanf("%s",str+1)){
        int len=strlen(str+1);
        rep(i,0,26) cc[i].reset();
        rep(i,1,len) cc[str[i]-'a'][i]=1;
        int m=read();
        while(m--){
            int op=read(),t;
            if(op==1){
                scanf("%d%s",&t,tmp+1);
                cc[str[t]-'a'][t]=0;
                cc[tmp[1]-'a'][t]=1;
                str[t]=tmp[1];
            }else{
                int l=read();
                int r=read();
                scanf("%s",tmp+1);
                int len2=strlen(tmp+1);
                if(r-l+1<len2){
                    println(0);
                }else{
                    bs.set();
                    rep(i,1,len2) bs&=(cc[tmp[i]-'a']>>(i-1));
                    int ans=(bs>>(l)).count()-(bs>>(r-len2+2)).count();
                    println(ans);
                }
            }
        }
    }
    return 0;
}