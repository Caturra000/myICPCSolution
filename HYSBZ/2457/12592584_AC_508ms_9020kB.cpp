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
const int maxn = 2e5+11;
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
    int id,val;
}a[maxn];
bool cmp(A a,A b){
    if(a.val!=b.val)return a.val<b.val;
    return a.id<b.id;
}
int main(){
    int n;
    while(~iin(n)){
        rep(i,1,n){
            a[i].val=read();
            a[i].id=i;
        }
        sort(a+1,a+1+n,cmp);
        vector<A> block[maxn];
        int now=0;
        rep(i,1,n){
            if(i==1||a[i].val!=block[now][0].val){
                now++;
                block[now].push_back(a[i]);
            }else{
                block[now].push_back(a[i]);
            }
        }
        int ans=0;
        rep(i,1,now) sort(block[i].begin(),block[i].end(),cmp);//tend=+1
        // rep(i,1,now){
        //     cout<<block[i][0].val<<": ";
        //     for(int j=0; j < block[i].size(); j++){
        //         cout<<block[i][j].id<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> que;
        int trend;
        rep(i,1,now){
            if(i==1){
                for(int j = block[i].size()-1; j >= 0; j--){
                        que.push_back(block[i][j].id);
                }
                trend=-1;
                // cout<<"init"<<endl;
            }else if(trend==-1){
                if(block[i].back().id<que.back()){
                    for(int j = block[i].size()-1; j >= 0; j--){
                        que.push_back(block[i][j].id);
                    }
                    trend=-1;
                }else{
                    for(int j = 0; j < block[i].size(); j++){
                        que.push_back(block[i][j].id);
                    }
                    trend=1;
                }
            }else{
                if(block[i][0].id>que.back()){
                    for(int j = 0; j < block[i].size(); j++){
                        que.push_back(block[i][j].id);
                    }
                    trend=1;
                }
                else{
                     for(int j = block[i].size()-1; j >= 0; j--){
                        que.push_back(block[i][j].id);
                    }
                    trend=-1;
                    ans++;
                }
            }
            // cout<<i<<" "<<ans<<endl;
        }
        println((ans+1));
        // for(auto t:que) cout<<t<<" ";
    }
    return 0;
}