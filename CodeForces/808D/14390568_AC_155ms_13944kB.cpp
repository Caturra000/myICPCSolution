#include<bits/stdc++.h>
#include<unordered_map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll pre[MAXN],suf[MAXN],a[MAXN];
int main(){
    unordered_map<ll,ll> l,r;
    int n;
    while(cin>>n){
        l.clear(),r.clear();
        rep(i,1,n) a[i]=read();
        rep(i,1,n) pre[i]=pre[i-1]+a[i];
        suf[n+1]=0;rrep(i,n,1) suf[i]=suf[i+1]+a[i];
        l[a[1]]++;
        rep(i,2,n){
            r[a[i]]++;
        }
        bool flag=0;
        rep(i,2,n){
            if(pre[i-1]==suf[i]){
                flag=1;
                cout<<"YES"<<endl;
                break;
            }else{
                ll t=pre[i-1]-suf[i]; //cout<<t<<endl;
                //for(map<ll,ll>::iterator it=l.begin();it!=l.end();it++) cout<<(*it).first<<"--"<<(*it).second<<" ";cout<<endl;
                //for(map<ll,ll>::iterator it=r.begin();it!=r.end();it++) cout<<(*it).first<<"--"<<(*it).second<<" ";cout<<endl;
                if((t%2==0)&&t>0&&l[t/2]>0){
                    flag=1;
                    cout<<"YES"<<endl;
                    break;
                }
                t=-t;
                if((t%2==0)&&t>0&&r[t/2]>0){
                    flag=1;
                    cout<<"YES"<<endl;
                    break;
                }
                l[a[i]]++;
                r[a[i]]--;
            }
        }
        if(flag==0){
            ll t=pre[n];
            if(t%2==0&&t>0&&l[t/2]>0){
                flag=1;
                cout<<"YES"<<endl;
            }
        } 
        if(flag==0) cout<<"NO"<<endl;
    }
    return 0;
}