#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1100;
int a[maxn],b[maxn],c[maxn],l[maxn],r[maxn];
int T,n,m,tl,tr,ans;
char str[maxn];
using namespace std;
void query(int qwert[]){
	for(int j = 1; j <= m; j++){
		l[j] = j;
		while(l[j]-1>=1&&qwert[j]<=qwert[l[j]-1]) l[j]=l[l[j]-1];
	}
	for(int j = m; j >= 0; j--){
		r[j] = j;
		while(r[j]+1<=m&&qwert[j]<=qwert[r[j]+1]) r[j]=r[r[j]+1];
	}
	for(int j = 1; j <= m; j++){
		ans = max(ans,qwert[j]*(r[j]-l[j]+1));
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		ans = 0;
		memset(a,0,sizeof a);memset(b,0,sizeof b);memset(c,0,sizeof c);
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
		printf("%d\n",ans);
	} 
	return 0;
}