#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 2333;
double E[maxn][maxn];
int n,s;
int main(){
	while(scanf("%d%d",&n,&s)!=EOF){
		memset(E,0,sizeof E);
		for(int i = n; i >= 0; i--){
			for(int j = s; j >= 0; j--){
				if(i==n&&j==s) continue;
				E[i][j] = (n*s+(n-i)*j*E[i+1][j]+i*(s-j)*E[i][j+1]+(n-i)*(s-j)*E[i+1][j+1])/(double)(n*s-i*j);
//				E[i][j]+=(double)(n-i)*j/(n*s)*E[i+1][j];
//				E[i][j]+=(double)i*(s-j)/(n*s)*E[i][j+1];
//				E[i][j]+=(double)(n-i)*(s-j)/(n*s)*E[i+1][j+1];
//				E[i][j]=(E[i][j]+1.0)/(1.0-(double)(i*j)/(n*s));
			}
		}
		printf("%.4lf\n",E[0][0]); 
	}
	return 0;
}