#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
const int maxn = 3e5+100, INF = 0x3f3f3f3f;
using namespace std;
int bit[maxn],m,w;
int main(){
	while(scanf("%d%d",&w,&m)!=EOF){
		memset(bit,0,sizeof bit);
		int now = 0;
		if(w==1){
			printf("YES\n");
			continue;
		}
		while(m){
			bit[now++]=m%w;
			m/=w;
		}
		for(int i = 0; i < now; i++){
			if(bit[i]==w-1){
				bit[i+1]++;
				bit[i]=-1;
			}
			else if(bit[i]==w){//w2 3
				bit[i+1]++;
				bit[i]=0;
			}
		}
		int flag = 0;
		for(int i = 0; i < now+1; i++){
//			cout<<i<<" "<<bit[i]<<endl;
			if(bit[i]!=0&&bit[i]!=-1&&bit[i]!=1){
				flag=1;
				break;
			}
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}