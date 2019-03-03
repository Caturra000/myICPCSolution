#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1100;
int a[maxn],ta[maxn],l[maxn],r[maxn];
int T,n,m,tl,tr,ans,t;
char str[maxn];
using namespace std;
void query(int qwert[]){
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
		ans = max(ans,a[j]*(r[j]-l[j]+1));
	}
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		ans = 0;
		memset(a,0,sizeof a);
		memset(ta,0,sizeof ta);
		for(int i = 1; i <= n; i++){
			cin>>str+1;
			for(int j = 1; j <= m; j++){
				if(str[j]=='0') ta[j] = 0;
				else ta[j]++;
			}
			memcpy(a,ta,sizeof ta);
			sort(a,a+m);
			query(a);
		}
		cout<<ans<<endl;
	} 
	return 0;
}