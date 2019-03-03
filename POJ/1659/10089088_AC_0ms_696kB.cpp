#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

const int maxn = 20;
struct vertex{
	int degree;
	int index;
}v[maxn];
int G[maxn][maxn];
bool cmp(vertex a,vertex b){
	return a.degree>b.degree;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,x,flag=0; scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d",&v[i].degree);
			v[i].index = i;
		}
		memset(G,0,sizeof G);
		for(int i = 0; i < n-1 && !flag; i++){
			std::sort(v,v+n,cmp);
			if(i+v[i].degree>=n){flag = 1; break;}
			for(int j = i+1; j <= i+v[i].degree; j++){
				v[j].degree--;
				if(v[j].degree<0){flag = 1; break;}
				int vi = v[i].index, vj = v[j].index;
				G[vi][vj] = 1; G[vj][vi] = 1;
			}
		}
		if(v[n-1].degree!=0) flag = 1; 
		if(flag) printf("NO\n\n");
		else{
			printf("YES\n");
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(j!=n-1) printf("%d ",G[i][j]);
					else if(i!=n-1) printf("%d\n",G[i][j]);
					else printf("%d\n\n",G[i][j]);
				}
			}
		}
		
	}
	return 0;
}