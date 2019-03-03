#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iter(i,j) for(int i=0;i<(j).size();i++)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 1e5+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[MAXN];
ll m,sum[MAXN],dp[MAXN];
int main(){
    while(cin>>n>>m){
        bool flag=0;
        rep(i,1,n){
            a[i]=read();
            sum[i]=sum[i-1]+a[i];
            if(a[i]>m) flag=1;
        }
        if(flag){
            println(-1);
            continue;
        }
        memset(dp,0,sizeof dp);
        deque<int> que;
        multiset<ll> s;
        int k=0;
        rep(i,1,n){
            while(sum[i]-sum[k]>m) k++;
            while(!que.empty()&&que.front()<k){
                if(que.size()>1){
                    int t=que.front(); que.pop_front();
                    int tt=que.front();
                    s.erase(dp[t]+a[tt]);
                }else{
                    que.pop_front();
                }
            }
            while(!que.empty()&&a[que.back()]<=a[i]){
                if(que.size()>1){
                    int t=que.back(); que.pop_back();
                    int tt=que.back();
                    s.erase(dp[tt]+a[t]);
                }else{
                    que.pop_back();
                }
            }
            if(!que.empty()){
                int t=que.back();
                s.insert(a[i]+dp[t]);
            }
            que.push_back(i);
            dp[i]=dp[k]+a[que.front()];
            if(que.size()>1) dp[i]=min(dp[i],*s.begin());
        }
        println(dp[n]);
    }
    return 0;
}