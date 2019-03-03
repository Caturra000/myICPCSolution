#include<bits\stdc++.h>
using namespace std;
const int maxn = 2005;
char mp[maxn][maxn];
int h[maxn];
int hh[maxn];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
     int n,m;
	 while(scanf("%d%d",&n,&m)!=EOF)
	 {
		 int ans = 0;
	//	 getchar();
		 for(int i = 1;i<=n;i++)
		 {
		//	 memset(h,0,sizeof(h));
			 for(int j = 1;j<=m;j++)
			 {
				 scanf(" %c",&mp[i][j]);
				 if(mp[i][j]=='1')
					 h[j]++;
				 else
					 h[j]=0; //关键，一旦断了就不做计算 
				 //printf("h[%d]=%d\n",j,h[j]);
				 hh[j]=h[j];
			 }
			 
			 sort(hh+1,hh+1+m,cmp);
			 for (int j = 1;j<=m;j++){
			 	// printf("hh[%d]=%d\nj*hh[j]=%d\n",j,hh[j],j*hh[j]);
				 ans = max(ans,hh[j]*j); //底乘高，前面一定都是1（否则存在0）， 
			 }
				 
		//	 getchar();
		 }
		 printf("%d\n",ans);
	 }
}
