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
#include<bitset>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 1e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Node{
    int l,r,id; 
}Q[MAXN];
int a[MAXN],pos[MAXN],ans[MAXN];
int cntVal[MAXN],cntNum[MAXN];//缁熻璇ュ€煎嚭鐜扮殑娆℃暟 / 璇ユ鏁板嚭鐜扮殑娆℃暟
int L,R,ANS,SIZE,n,m,k;
bool cmp(Node a,Node b){
    if(pos[a.l]!=pos[b.l]) return pos[a.l]<pos[b.l];
    return a.r<b.r;
}
inline void add(int cur){
    int f=cntVal[a[cur]];
    if(f==ANS) ANS++;
    cntVal[a[cur]]++;
    cntNum[f]--;
    cntNum[f+1]++;
}
inline void del(int cur){
    int f=cntVal[a[cur]];
    if(f==ANS&&cntNum[f]==1) ANS--;
    cntVal[a[cur]]--;
    cntNum[f]--;
    cntNum[f-1]++;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(cntNum,0,sizeof cntNum);
        memset(cntVal,0,sizeof cntVal);
        SIZE=sqrt(n);
        rep(i,1,n){
            a[i]=read();
            pos[i]=i/SIZE;
        }
        rep(i,1,m){
            Q[i].l=read()+1;
            Q[i].r=read()+1;
            Q[i].id=i;
            if(Q[i].l>Q[i].r) swap(Q[i].l,Q[i].r);
        }
        sort(Q+1,Q+1+m,cmp);
        cntNum[0]=n;
        L=1; R=0; ANS=0;
        rep(i,1,m){ //娉ㄦ剰椤哄簭!鍚﹀垯RTE!
            while(L>Q[i].l){
                L--;
                add(L);
            }
            while(R<Q[i].r){
                R++;
                add(R);
            }
            while(L<Q[i].l){
                del(L);
                L++;
            }
            while(R>Q[i].r){
                del(R);
                R--;
            }
            ans[Q[i].id]=ANS;
        }
        rep(i,1,m) println(ans[i]);
    }
    return 0;
}