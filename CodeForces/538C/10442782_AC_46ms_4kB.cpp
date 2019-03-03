#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 ll;
ll n,m,prex,pret,x,t,flag,mmax;
int main(){
	while(scanf("%I64d%I64d",&n,&m)!=EOF){
		mmax=0;flag=0;
		scanf("%I64d%I64d",&prex,&pret);mmax=max(mmax,pret+prex-1);
		for(int i = 2; i <= m; i++){
			scanf("%I64d%I64d",&x,&t); mmax=max(mmax,max(pret,t));
			double px = (t-pret+prex+x)/2.0;
			if(px<prex||px>x) flag=1; 
			ll ph = (pret+t+x-prex)/2;
			mmax=max(mmax,ph);
			prex=x;pret=t;
		}
		mmax=max(mmax,pret+n-prex);//WA1
		if(!flag) printf("%I64d\n",mmax);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
} 