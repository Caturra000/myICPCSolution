#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
int n,m;
int main(){
	while(cin>>n>>m){
		if(n>=2*m) cout<<m<<endl;
		else if(m>=2*n) cout<<n<<endl;
		else{
			double x;
			int ans=0;
			x=(2.0*min(n,m)-max(n,m))/3.0;
			int xx=x;
			if(n>m)m=m-2*xx,n=n-xx;
			else m=m-xx,n=n-2*xx;
			ans=xx;
			int nn=n,mm=m,tmp=0;
			bool flag=0;
			while(1){
				if(flag)break;
				if(n-2>=0&&m-1>=0){
					ans++;
					n-=2;m-=1;
				}
				else flag=1;
			}
			tmp=ans;n=nn;m=mm;ans=xx;
			flag=0;
			while(1){
				if(flag)break;
				if(n-1>=0&&m-2>=0){
					ans++;
					n-=1;m-=2;
				}
				else flag=1;
			}
			cout<<max(tmp,ans)<<endl;
		}
	}
	return 0;
}