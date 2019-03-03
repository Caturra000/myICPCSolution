#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int a[MAXN];
int main(){
    int n;
    while(cin>>n){
        rep(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        int mn=INF,mx=-INF;
        rep(i,1,n){
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
        }
        if(mx-mn<=1){
            println(n);
            rep(i,1,n){
                if(i==n) println(a[i]);
                else printf("%d ",a[i]); 
            }
        }else{
            int mxcnt=0,mncnt=0,midcnt=0;
            rep(i,1,n){
                if(mx==a[i]) mxcnt++;
                else if(mn==a[i]) mncnt++;
                else midcnt++;
            }
            int mid=mx+mn>>1;
            int ans1=0,ans2=0;
            int t1=mxcnt,t2=midcnt,t3=mncnt;
            t1+=t2/2, t3+=t2/2; t2-=(t2/2)*2;
            rep(i,1,n){
                if(a[i]==mx&&t1) t1--,ans1++;
                else if(a[i]==mn&&t3) t3--,ans1++;
                else if(a[i]!=mx&&a[i]!=mn&&t2) t2--,ans1++;
            }
            t1=mxcnt,t2=midcnt,t3=mncnt;
            int t=min(t1,t3);
            t1-=t,t2+=t*2,t3-=t;
            rep(i,1,n){
                if(a[i]==mx&&t1) t1--,ans2++;
                else if(a[i]==mn&&t3) t3--,ans2++;
                else if(a[i]!=mx&&a[i]!=mn&&t2) t2--,ans2++;
            }
            println(min(ans1,ans2));
            t1=mxcnt,t2=midcnt,t3=mncnt;
            vector<int> vec;
            if(ans1<ans2){
                t1+=t2/2, t3+=t2/2; t2-=(t2/2)*2;
            }else{
                t1-=t,t2+=t*2,t3-=t;
            }
            rep(i,1,n){
                if(t1) vec.push_back(mx),t1--;
                else if(t2) vec.push_back(mid),t2--;
                else if(t3) vec.push_back(mn),t3--;
            }
            for(int i=0;i<vec.size();i++){
                if(i==(int)vec.size()-1) println(vec[i]);
                else printf("%d ",vec[i]);
            }
        }
    }
    return 0;
}