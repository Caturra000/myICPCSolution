#include<bits/stdc++.h>
#include<unordered_map>
#include<ext/pb_ds/priority_queue.hpp>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define println(x) print(x),print('\n')
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pr = pair<ll,ll>;
const int MAXN = 1e6+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
int a[MAXN],n,l[MAXN],r[MAXN];
int main(){
    fastIO;
    while(cin>>n){
        rep(i,1,n) cin>>a[i];
        stack<int> stk;
        rep(i,1,n){//ALL a[j]>a[i],j<i
            while(!stk.empty()&&a[stk.top()]>a[i]) stk.pop();
            if(!stk.empty()) l[i]=stk.top()+1;//第一个小于等于a[i]的极左下标+1
            else l[i]=1; 
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        rrep(i,n,1){//a[i]<=a[j],i<j 
            while(!stk.empty()&&a[i]<=a[stk.top()]) stk.pop();
            if(!stk.empty()) r[i]=max(i,stk.top()-1);
            else r[i]=n;
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        ll ans=0;
        rep(i,1,n) ans-=(ll)a[i]*(i-l[i]+1)*(r[i]-i+1);
        rep(i,1,n){
            while(!stk.empty()&&a[stk.top()]<a[i]) stk.pop();
            if(!stk.empty()) l[i]=stk.top()+1;
            else l[i]=1; 
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        rrep(i,n,1){
            while(!stk.empty()&&a[i]>=a[stk.top()]) stk.pop();
            if(!stk.empty()) r[i]=max(i,stk.top()-1);
            else r[i]=n;
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        rep(i,1,n) ans+=(ll)a[i]*(i-l[i]+1)*(r[i]-i+1);
        cout<<ans<<endl;
    }
    return 0;
}