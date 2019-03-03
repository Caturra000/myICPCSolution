#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
typedef pair<int,int> PR;
int n,K,Q;
int D,m,root,lc[maxn],rc[maxn];
priority_queue<PR> que;
vector<int> ans;
inline int sqr(int x){return x*x;}
struct point{
	int x[5];
	void read(){
		for(int i = 0; i < K; i++) scanf("%d",&x[i]);
	}
	void print(){
		for(int i = 0; i < K-1; i++) printf("%d ",x[i]);
		printf("%d\n",x[K-1]); 
	}
	bool operator < (const point &a)const{
		return x[D]<a.x[D];//NOTE
	}
}dot[maxn],P;
int build(int l,int r,int now){
	if(l>r) return 0;
	D = now;
	int mid = (l+r)>>1;
	nth_element(dot+l,dot+mid,dot+r+1);
	lc[mid]=build(l,mid-1,(now+1)%K);
	rc[mid]=build(mid+1,r,(now+1)%K);
	return mid;
}
int dis(point p1,point p2){
	int ret=0;
	for(int i = 0; i < K; i++) ret+=sqr(p1.x[i]-p2.x[i]);
	return ret;
}
void query(int cur,int now){
	if(cur==0) return;
	PR nd(dis(dot[cur],P),cur);
	int x = lc[cur],y=rc[cur];
	if(dot[cur].x[now]<P.x[now]) swap(x,y);
	query(x,(now+1)%K);
	if(que.size()<m) que.push(nd);
	else{
		if(nd.first<que.top().first){
			que.pop();que.push(nd);
		}
	}
	if(sqr(dot[cur].x[now]-P.x[now])<=que.top().first) query(y,(now+1)%K);
}

int main(){
	while(scanf("%d%d",&n,&K)!=EOF){
		memset(lc,0,sizeof lc);memset(rc,0,sizeof rc);
		for(int i = 1; i <= n; i++) dot[i].read();
		root=build(1,n,0);
		scanf("%d",&Q);
		while(Q--){
			P.read();scanf("%d",&m);
			printf("the closest %d points are:\n",m);
			query(root,0);
			while(!que.empty()){
				ans.push_back(que.top().second);
				que.pop();
			}
			while(!ans.empty()){
				dot[ans.back()].print();
				ans.pop_back();
			}
		}
	}
	return 0;
}