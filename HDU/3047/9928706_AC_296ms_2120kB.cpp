#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 50002;
int p[maxn],r[maxn];//rank设为子节点到父节点的相对距离 一般认为ra为rb父节点 
int n,m;
void init(){
	for(int i = 0; i < n+5; i++)
		p[i]=i;
	memset(r,0,sizeof r); 
}
int find(int x){
	//return p[x]==x?x:find(p[x]); //需要更新rank 
	if(x==p[x]) return x;
	int pa = p[x];
	p[x] = find(p[x]);
	r[x]+=r[pa];//NOTE: 
//	cout << "findpa-rank[" << p[x] << "] = " << rank[p[x]] << endl;
//	cout << "findx-rank[" << x << "] = " << rank[x] << endl;
	return p[x];
}
bool same(int a,int b){
	return find(a)==find(b);
}
void link(int a,int b,int ra,int rb,int dis){
	r[rb] = r[a]+dis-r[b]; //向量偏移 
	p[rb] = ra; //建立关系 //当且仅当不同集合时 
//	cout << "link-rank[" << rb << "] = " << rank[rb] << endl;
	
}
int main(){
	ios::sync_with_stdio(false); 
	while(cin>>n>>m){
		init();
		int ans = 0,a,b,dis,ra,rb;
		for(int i = 1; i <= m; i++){
			cin>>a>>b>>dis;
			ra = find(a);
			rb = find(b);
			if(ra==rb){//同一集合中 
				if(r[b]-r[a]!=dis)
					ans++;
			}
			else//更新 
				link(a,b,ra,rb,dis);
		}
		cout << ans << endl;
	}
	return 0;
}