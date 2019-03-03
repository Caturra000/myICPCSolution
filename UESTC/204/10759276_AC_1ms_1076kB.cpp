#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
const int INF = 0x3f3f3f3f;
int a[maxn],b[maxn];
int n,m,p,q,x,y,ans;
int find(){
	int minx=INF,mini=0;
	if(p<n&&a[p]<minx){minx=a[p];mini=1;}
	if(q<=m&&b[q]<minx){minx=b[q];mini=2;}
	if(mini==1) p++;
	else q++;
	return minx;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		a[1]=0;
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		ans=a[0]+a[1];
		b[0]=a[0]+a[1];
		p=2;q=0;m=0;
		for(int i = 1; i < n-1; i++){
			x=find();
			y=find();
			b[++m]=x+y;
			ans+=(x+y); 
		}
		printf("%d\n",ans);
	}
	return 0;
}