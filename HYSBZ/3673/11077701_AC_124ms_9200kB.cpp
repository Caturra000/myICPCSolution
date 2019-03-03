#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
const int maxn = 4e5+11; 
typedef rope<int> RP;
rope<int> *rp[maxn];//p[maxn][maxn] 
int op,n,m,a,b;
void change(RP &rp,int x,int v){
	rp.erase(x,1);
	rp.insert(x,v); 
}
int find(RP &rp,int x){//无路径压缩 
	while(rp[x]!=x) x=rp[x];
	return x;
}
void link(RP &rp,int a,int b){//
	change(rp,find(rp,a),find(rp,b));
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		
		rp[0] = new rope<int>;
		for(int i = 0; i < n; i++) rp[0]->push_back(i);
		for(int i = 1; i <= m; i++){
			scanf("%d",&op);
			if(op==1){
				scanf("%d%d",&a,&b);a--;b--; 
				rp[i]=new rope<int>(*rp[i-1]);
				if(find(*rp[i],a)!=find(*rp[i],b)) link(*rp[i],a,b);
			}
			else if(op==2){
				scanf("%d",&a);
				rp[i]=new rope<int>(*rp[a]);
			}
			else{
				rp[i]=rp[i-1];
				scanf("%d%d",&a,&b);a--;b--;
				printf("%d\n",find(*rp[i],a)==find(*rp[i],b));
			}
		}
	}
	return 0; 
}