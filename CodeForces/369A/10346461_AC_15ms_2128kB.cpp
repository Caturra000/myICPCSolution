#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 20000;
int T,n,m,k;
int a[maxn];
int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(a[i]==1){
				if(m>0){
					m--;
				}
				else{
					ans++;
				}
			}
			else if(a[i]==2){
				if(k>0){
					k--;
				}
				else if(m>0){
					m--;
				}
				else{
					ans++;
				}
			}
		}
//		if(m>0) m=0;
//		if(k>0) k=0;
		printf("%d\n",ans);
	}
	return 0;
}