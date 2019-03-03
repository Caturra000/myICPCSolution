#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1100;
long long a[maxn],b[maxn],c[maxn],l[maxn],r[maxn];
long long T,n,m,tl,tr,ans;
char ch;
char str[maxn];
using namespace std;
void query(long long qwert[]){
	for(int j = 1; j <= m; j++){
		l[j] = j;
		while(qwert[j]<=qwert[l[j]-1]&&l[j]-1>=1) l[j]=l[l[j]-1];
	}
	for(int j = m; j >= 0; j--){
		r[j] = j;
		while(qwert[j]<=qwert[r[j]+1]&&r[j]+1<=m) r[j]=r[r[j]+1];
	}
	for(int j = 1; j <= m; j++){
		ans = max(ans,qwert[j]*(r[j]-l[j]+1));
	}
//	l[1] = 1; r[m] = m;
//	for(int j = 2; j <= m; j++){
//		tl = j;
//		while(tl>1&&qwert[j]!=0&&qwert[j]<=qwert[tl-1]) tl = l[tl-1];
//		l[j] = tl;
//	}
//	for(int j = m-1; j >= 1; j--){
//		tr = j;
//		while(tr<n&&qwert[j]!=0&&qwert[j]<=qwert[tr+1]) tr = r[tr+1];
//		r[j] = tr;
//	}
}
int main(){
	while(scanf("%lld%lld",&n,&m)!=EOF){
		ans = 0;
		memset(a,0,sizeof a); memset(b,0,sizeof b); memset(c,0,sizeof c);
		for(int i = 1; i <= n; i++){
			scanf("%s",str+1);
			for(int j = 1; j <= m; j++){
				if( (str[j]=='a'||str[j]=='w'||str[j]=='y'||str[j]=='z')) a[j]++;
				else a[j] = 0;
				if( (str[j]=='b'||str[j]=='w'||str[j]=='x'||str[j]=='z')) b[j]++;
				else b[j] = 0;
				if( (str[j]=='c'||str[j]=='x'||str[j]=='y'||str[j]=='z')) c[j]++;
				else c[j] = 0;
			}
			query(a);query(b);query(c);
		}	
		printf("%lld\n",ans);
	} 
	return 0;
}