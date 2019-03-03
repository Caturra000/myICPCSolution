#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const long long INF = 1ll<<55;
const int maxn = 1010;
long long a[maxn],l[maxn],r[maxn];
long long T,n,m,tl,tr,ans;
char ch[5];
using namespace std;
int main(){
	int T; scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		memset(a,0,sizeof a);memset(l,0,sizeof l); memset(r,0,sizeof r);
		ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scanf("%s",ch);
				if(ch[0] == 'R') a[j] = 0;
				else if(a[j]!=0) a[j]=a[j]+1;
				else a[j] = 1;
			}
			l[1] = 1; r[m] = m;
			for(int j = 2; j <= m; j++){
				tl = j;
				while(tl>1&&a[j]!=0&&a[j]<=a[tl-1]) tl = l[tl-1];
				l[j] = tl;
			}
			for(int j = m-1; j >= 1; j--){
				tr = j;
				while(tr<n&&a[j]!=0&&a[j]<=a[tr+1]) tr = r[tr+1];
				r[j] = tr;
			}
			for(int j = 1; j <= m; j++){
				ans = max(ans,a[j]*(r[j]-l[j]+1)*3);
			}
		}	
		printf("%lld\n",ans);
	} 
	return 0;
}