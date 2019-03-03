#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
#define rep(i,j,k) for(int i=j;i<=k;i++)
struct qwe{
	ll a,b;
	bool kill;
}d[maxn];
bool cmp(qwe a,qwe b){
	return a.b>b.b;
}
int s,n;
int main(){
	ios::sync_with_stdio(0);
	while(cin>>s>>n){
		rep(i,1,n)d[i].kill=0;
		rep(i,1,n)cin>>d[i].a>>d[i].b;
		sort(d+1,d+1+n,cmp);
		rep(i,1,n){
			bool f=0;
			rep(j,1,n){
				if(d[j].kill==0){
//					cout<<"Test"<<s<<" "<<d[j].a<<endl;
					if(s>d[j].a){
						s+=d[j].b;
						d[j].kill=1;
						f=1;
						break;
					}
				}
			}
			if(f==0) break;
		}
		bool flag=0;
		rep(i,1,n) if(d[i].kill==0) flag=1;
		if(flag)cout<<"NO\n";
		else cout<<"YES\n";
	}
}