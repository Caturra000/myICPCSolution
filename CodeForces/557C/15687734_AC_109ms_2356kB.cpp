#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 1e5 + 11;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0, f=1; register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct QAQ{
    int d,l;
    bool operator<(const QAQ&orz)const{
        return l<orz.l;
    }
}a[MAXN];
int n;
int num[MAXN];
ll sum[MAXN];
int cnt[MAXN];
int main(){
    while(cin>>n){
        rep(i,1,n) a[i].l=read();
        rep(i,1,n) a[i].d=read();
        sort(a+1,a+1+n);
        memset(num,0,sizeof num);
        memset(sum,0,sizeof sum);
        memset(cnt,0,sizeof cnt);
        int maxlen=0;
        rep(i,1,n){
            maxlen=max(maxlen,a[i].l);
            num[a[i].l]++;
            sum[a[i].l]+=a[i].d;
        }
        rep(i,1,maxlen) sum[i]=sum[i-1]+sum[i];
        ll res=1ll<<60;
        int curlen=1,curpos=1;
        while(curlen<=maxlen&&curpos<=n){
            ll tmp=sum[maxlen]-sum[curlen];
            int save=num[curlen]-1;
            ll all=0,d=0;
            rrep(i,200,1){
                all=all+cnt[i]*i;
                if(cnt[i]>0&&save>0){
                    if(save>=cnt[i]){
                        save-=cnt[i];
                        d=d+cnt[i]*i;
                    }else{
                        d=d+save*i;
                        save=0;
                    }
                }
            }
            tmp=tmp+max(0ll,all-d);
            while(curpos<=n&&a[curpos].l<=curlen){
                cnt[a[curpos].d]++;
                curpos++;
            }
            res=min(res,tmp);
            curlen++;
        }
        println(res);
    }
    return 0;
}