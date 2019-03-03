#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int maxn = 1e5+11;
const double eps = 1e-7;
typedef long long ll;
const int oo = 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct A{
    int id,st,ed;
}a[maxn];
bool cmp(A a,A b){
    if(a.st!=b.st) return a.st<b.st;
    return a.ed<b.ed;
}
struct B{
    int id,st,ed;
    bool operator < (const B &rhs)const{
        return ed>rhs.ed;
    }
}b[maxn];
int main(){
    int n,ans[maxn];
    while(~iin(n)){
        priority_queue<B> que;
        while(!que.empty())que.pop();
        rep(i,1,n){
            a[i].id=i;
            a[i].st=read();
            a[i].ed=read();
        }
        sort(a+1,a+1+n,cmp);
        int cnt=0;
        rep(i,1,n){
            bool flag=0;
            // rep(j,1,now){
            //     if(a[i].st>b[j].ed||a[i].ed<b[j].st){
            //         flag=1;
            //         b[j].ed=max(a[i].ed,b[j].ed);
            //         b[j].st=min(a[i].st,b[j].st);
            //         // cout<<j<<" "<<b[j].st<<" "<<b[j].ed<<endl;
            //         ans[a[i].id]=j;
            //         break;
            //     }
            // }
            // if(flag==0){
            //     now++;
            //     b[now].st=a[i].st;
            //     b[now].ed=a[i].ed;
            //     // cout<<now<<" "<<b[now].st<<" "<<b[now].ed<<endl;
            //     ans[a[i].id]=now;
            // }
            if(que.empty()||que.top().ed>=a[i].st){
                B tmp;
                tmp.st=a[i].st;
                tmp.ed=a[i].ed;
                tmp.id=++cnt;
                que.push(tmp);
                ans[a[i].id]=cnt;
                continue;
            }
            B tmp=que.top();que.pop();
            tmp.ed=max(tmp.ed,a[i].ed);
            tmp.st=min(tmp.st,a[i].st);
            ans[a[i].id]=tmp.id;
            que.push(tmp);
        }
        println(cnt);
        rep(i,1,n){
            println(ans[i]);
        }
    }
    return 0;
}