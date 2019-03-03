#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+31;
int p[maxn];
int find(int x){
	return p[x]==x?x:p[x]=find(p[x]);
} 
bool link(int a,int b){
	a=find(a);b=find(b);
	if(a==b)return 0;
	p[b]=a;
	return 1;
}
bool same(int a,int b){
	return find(a)==find(b);
}
void init(int n){
	for(int i = 0; i < n+22; i++) p[i]=i;
}
int save[maxn][2]; 
int main(){
	int n,m,a,b,q,x,good,bad;
	while(scanf("%d%d%d%d",&n,&m,&good,&bad)!=EOF){
		bool flag=0;int cnt=0;init(n);
		for(int i = 0; i < m; i++){
			scanf("%d%d",&save[i][0],&save[i][1]);
		}
		for(int i = 0; i < good; i++){
			scanf("%d",&x);
			if(same(n+2,x))flag=1;
			else link(n+1,x),cnt++;
		}
		for(int i = 0 ; i < bad; i++){
			scanf("%d",&x);
			if(same(n+1,x))flag=1;
			else link(n+2,x),cnt++;
		}
		for(int i = 0; i < m; i++){
			a=save[i][0];b=save[i][1];
			int ta=find(a),tb=find(b);
			if(ta==tb)flag=1;
			else if(ta==n+1&&tb!=n+2)link(n+2,b),cnt++;
			else if(ta==n+1&&tb==n+2)continue;
			else if(ta==n+2&&tb!=n+1)link(n+1,b),cnt++;
			else if(ta==n+2&&tb==n+1)continue;
			else if(tb==n+1&&ta!=n+2)link(n+2,a),cnt++;
			else if(tb==n+2&&ta!=n+1)link(n+1,a),cnt++;
			else if(ta!=tb)link(n+1,a),link(n+2,b),cnt+=2;
		}
		if(cnt==n&&!flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}