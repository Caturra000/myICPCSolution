#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 40;
int dz[] = {0,0,0,0,1,-1};
int dy[] = {1,0,-1,0,0,0};
int dx[] = {0,1,0,-1,0,0};
int G[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
struct point{
	int x,y,z;
	int cnt;
};
int main(){
	ios::sync_with_stdio(false);
	int z,y,x;
	int sx,sy,sz;
	int ex,ey,ez;
	char t;
	while(cin>>z>>y>>x){
		if(z==0) break;
		memset(G,0,sizeof G);
		memset(vis,0,sizeof vis);
		for(int i = 0; i < z; i++){
			for(int j = 0; j < y; j++){
				for(int k = 0; k < x; k++){
					cin >> t;
					if(t=='#') G[i][j][k] = 1;
					if(t=='S') sz = i, sy = j, sx = k;
					if(t=='E') ez = i, ey = j, ex = k;
				}
			}
		}
		queue<point> q;
		q.push((point){sx,sy,sz,0});
		int ans = -1;
		while(!q.empty()){
			point u = q.front(); q.pop();
			if(vis[u.z][u.y][u.x]) continue;
			if(u.z==ez&&u.y==ey&&u.x==ex){ans = u.cnt; break;}
			vis[u.z][u.y][u.x] = 1;
			for(int i = 0; i < 6; i++){
				int zz = u.z+dz[i], yy = u.y+dy[i], xx = u.x+dx[i];
				if(zz<0||zz>=z||yy<0||yy>=y||xx<0||xx>=x||G[zz][yy][xx]==1) continue;
				q.push((point){xx,yy,zz,u.cnt+1});
			}
		}
		if(ans!=-1) cout << "Escaped in " << ans << " minute(s).\n";
		else cout << "Trapped!" << endl;
	}
	return 0;
} 