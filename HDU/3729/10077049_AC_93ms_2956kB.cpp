#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 5+1e5;
//int G[65][maxn];
bool check[maxn];
int match[maxn];
int se[maxn][2];//0Start1End 
int T,n,l,r,cnt;
vector<int> ok;
int Scan(){ 
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}

void init(){
	cnt = 0;
	//memset(G,0,sizeof G);
	memset(match,0,sizeof match);
	memset(se,0,sizeof se);
	ok.clear();
}
bool dfs(int u){
	for(int i = 0; i < se[u][1]-se[u][0]+1; i++){
		int v = se[u][0]+i;
		if(check[v]) continue;
		check[v] = 1;
		if(!match[v]||dfs(match[v])){
			match[v] = u;
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		n = Scan();
		for(int i = 1; i <= n; i++){
			l = Scan();
			r = Scan();
			//memset(G[i]+l,-1,sizeof(int)*(r-l+1));
			se[i][0] = l; se[i][1] = r;
		}
		for(int i = n; i >= 1; i--){
			memset(check,0,sizeof check);
			if(dfs(i)) {
				cnt++;
				ok.push_back(i);
			}
		}
		printf("%d\n",cnt);
		for(int i = cnt-1; i >= 0; i--){
			if(i>0) printf("%d ",ok[i]);
			else printf("%d\n",ok[i]);
		}
	}
	return 0;
} 