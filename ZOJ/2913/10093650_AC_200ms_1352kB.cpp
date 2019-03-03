#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
const int maxn = 1e4;
set<int> zone;
int link[maxn][12];
int dis[maxn],tdis[maxn];//dis[i]表示编号为i的点到所有公交站点距离的最大值 
void bfs(int st){
	queue<int> q;
	memset(tdis,0,sizeof tdis);
	tdis[st] = 1;
	q.push(st);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(tdis[cur] > dis[cur]) dis[cur] = tdis[cur];
		for(int i = 1; i <= link[cur][0]; i++){
			int temp = link[cur][i];//邻接边全部遍历  和中心有啥关系？ 
			if(tdis[temp]==0){q.push(temp); tdis[temp] = tdis[cur]+1;}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		int nz,nr,mz,mr,num,id;
		zone.clear();
		cin >> nz >> nr;
		for(int i = 0; i < nz; i++){
			cin >> id >> mz;
			link[id][0] = mz;
			for(int j = 1; j <= mz; j++){
				cin >> link[id][j];
				zone.insert(link[id][j]);//NOTE:用于求解ans下标，防止重复并且从小到大排序 
			}
		}
		int pos; memset(dis,0,sizeof dis);
		for(int i = 0; i < nr; i++){
			cin >> mr;
			for(int j = 0; j < mr; j++){
				cin >> pos;
				bfs(pos); //NOTE:从公交站开始bfs 
			}
		}
		set<int>::iterator ite = zone.begin();
		int ans = *ite; //first
		for(++ite; ite!=zone.end(); ite++){
			if(dis[*ite]<dis[ans]) ans = *ite;
		}
		cout << dis[ans] << " " << ans << endl;
	}
	return 0;
} 