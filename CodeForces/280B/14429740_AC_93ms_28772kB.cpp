#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 3e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
stack<int> stk;
int pre[MAXN],succ[MAXN];
int mx[MAXN][21],a[MAXN];
int rmq(int l,int r){
    int k=log2(r-l+1);
    return max(mx[l][k],mx[r-(1<<k-1)+1][k]);
}
int main(){
    int n;
    while(cin>>n){
        rep(i,1,n) a[i]=read();
        while(!stk.empty()) stk.pop();
//        rep(i,1,n){
//            while(!stk.empty()&&a[stk.top()]<a[i]){
//                succ[stk.top()]=i-1;
//                stk.pop();
//            }
//            if(!stk.empty())pre[i]=stk.top()+1;
//            else pre[i]=1;
//            stk.push(i); 
//        }
        int ans=0;
        rep(i,1,n){
            while(!stk.empty()&&a[stk.top()]<a[i]){
                stk.pop();
            }
            if(!stk.empty()) ans=max(ans,a[i]^a[stk.top()]);
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        rrep(i,n,1){
            while(!stk.empty()&&a[stk.top()]<a[i]){
                stk.pop();
            }
            if(!stk.empty()) ans=max(ans,a[i]^a[stk.top()]);
            stk.push(i);
        }
        println(ans);
    }
    return 0;
}