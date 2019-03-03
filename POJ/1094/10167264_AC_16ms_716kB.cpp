#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<stack>
using namespace std;
const int maxn = 30;
int G[maxn][maxn],id[maxn],td[maxn],ans[maxn];
int n,m,done,full,flag,cnt;
bool in[maxn];
char str[5];
int topo(){
	memcpy(td,id,sizeof id);
	stack<int> ss; cnt = 0;
	int f=0;
	for(int i = 0; i < n; i++) if(td[i]==0){ss.push(i);ans[cnt++]=i;}
	while(!ss.empty()){
		if(ss.size()>1) f=1;//multi-way 不能在内部循环判断,multi-way必须要在cnt==n的前提,而且不是立即判断,因为后期顶点的度数可能改变 但不能这样写if(cnt==n) return 2 
		int t = ss.top(); ss.pop();
		for(int i = 0; i < n; i++){
			if(G[t][i]&&--td[i]==0){ss.push(i);ans[cnt++]=i;}
		}
	}
	if(cnt!=n) return 1;//unknown // circle 
	if(f) return 2;//multi-way
	return 0;//ok
}
void init(){
	memset(G,0,sizeof G);
	memset(id,0,sizeof id);
	memset(ans,0,sizeof ans);
	memset(in,0,sizeof in);
	done=0;full=0;flag=0;
}
int main(){
	while(scanf("%d%d",&n,&m),n){
		init();
		for(int i = 0; i < m; i++){
			scanf("%s",str);
			int from = str[0]-'A', to = str[2]-'A';
			in[from]=1;in[to]=1;
			if(G[from][to]==0){
				G[from][to]=1;
				id[to]++;
			}
			if(G[to][from]==1&&!done){//有环 
				done = 1;
				printf("Inconsistency found after %d relations.\n",i+1);
			}
			if(!done){
				flag = topo();
				if(flag==1){ //multi-way
					done = 1;
					printf("Inconsistency found after %d relations.\n",i+1);
				}
				else if(flag==0){ //ok
					done = 1;
					printf("Sorted sequence determined after %d relations: ",i+1);
					for(int j = 0; j < n; j++) printf("%c",ans[j]+'A');
					printf(".\n");
				}
			}
		}
		if(!done){
			printf("Sorted sequence cannot be determined.\n");
		} 
	}
	return 0;
} 