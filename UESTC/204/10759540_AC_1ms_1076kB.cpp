#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
const int INF = 0x3f3f3f3f;
int n,m,now1,now2,ans,x,y;
int a[maxn],b[maxn];
int find(){
	int mmin=INF,flag=0;
	if(now1<n&&a[now1]<mmin){
		mmin=a[now1];
		flag=1;
	}
	if(now2<m&&b[now2]<mmin){
		mmin=b[now2];
		flag=2;
	}
	if(flag==1) now1++;
	if(flag==2) now2++;
	return mmin;
}
int main(){
	while(scanf("%d\n",&n)!=EOF){
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		if(n==1){printf("%d\n",a[0]);continue;}
		sort(a,a+n);
		now1=0;now2=0;m=0;ans=0;
		for(int i = 0; i < n-1; i++){
			x=find();
			y=find();
			ans+=x+y;
			b[m++]=x+y;
		}
		printf("%d\n",ans);
	}
	return 0;
}