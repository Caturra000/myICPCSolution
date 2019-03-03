#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#define lowbit(b) (b)&(-b)
using namespace std;
const int maxn = 1100;
typedef long long ll;
int G[maxn][maxn];
int sum[maxn][maxn];
//int fts[maxn][maxn];
int n,m,q,r,c,mmax;
//int rsq(int ft[],int b){
//	int sum = 0;
//	while(b){
//		sum+=ft[b];
//		b-=lowbit(b);
//	}
//	return sum;
//}
//void update(int ft[],int k,int v){
//	while(k<maxn){
//		ft[k]+=v;
//		k+=lowbit(k);
//	}
//}
int da;
map<int,int> pos;
int main(){
	while(scanf("%d%d%d",&n,&m,&q)!=EOF){
		memset(G,0,sizeof G);da=0;pos.clear();
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scanf("%d",&G[i][j]);
				if(G[i][j]==0) sum[i][j]=0;
				else sum[i][j]=sum[i][j-1]+1;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = m; j >= 1; j--){
				if(sum[i][j]>da){
					pos.clear();
					pos[i]=1;
					da = sum[i][j];
				}
				if(sum[i][j]==da){
					if(pos[i]!=0) continue;
					else pos[i]=1;
				}
			}
		}
//		cout<<da<<"sdasfeeds"<<endl;
//cout<<"ysz"<<pos.size()<<endl<<"yda"<<da<<endl;
		for(int i = 1; i <= q; i++){
			scanf("%d%d",&r,&c);
			if(pos[r]!=0){
				pos[r]=0;
			}
			if(G[r][c]==0){
				G[r][c]=1;
			}
			else{
				G[r][c]=0;
			}
			int curmax=0;
			memset(sum[r],0,sizeof sum[r]);
			for(int j = 1; j <= m; j++){
				if(G[r][j]==0) sum[r][j]=0;
				else sum[r][j] = sum[r][j-1]+1;
				curmax = max(sum[r][j],curmax);
			}
			
			if(curmax==da) pos[r]=1;
			if(curmax>da){
				pos.clear();
				pos[r]=1;
				da = curmax;
			}
			if(curmax<da){
//				cout<<curmax<<"cur"<<endl;
//				cout<<"mysz"<<pos.size();
				int cnt=0;
				for(map<int,int>::iterator ii = pos.begin(); ii != pos.end(); ii++) (*ii).second==0?cnt++:0; 
				if(cnt!=pos.size()){
					printf("%d\n",da);
					continue;//1..2....
				}
				da = 0;
				for(int k = 1; k <= n; k++){
					for(int l = m; l >= 1; l--){
						if(sum[k][l]>da){
							pos.clear();
							pos[k]=1;
							da=sum[k][l];
						}
						if(sum[k][l]==da){
							if(pos[k]!=0) continue;
							else pos[k]=1;
						}
					}
				}
			}
//			cout<<endl<<"sz"<<pos.size()<<endl<<"da"<<da<<endl;	
//			for(map<int,int>::iterator ii = pos.begin; ii != pos.end(); ii++) cout<<ii<<endl; 
			printf("%d\n",da);
		}
	}
	return 0;
}