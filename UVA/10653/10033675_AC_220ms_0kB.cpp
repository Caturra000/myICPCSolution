#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1234;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn];
struct point{
    int x,y;
    int z;
};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool vis[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    int r,c;
    while(cin>>r>>c){
        if(r==0&&c==0) break;
        memset(G,0,sizeof G);
        memset(vis,0,sizeof vis);
        int rr; cin >> rr;
        for(int i = 0; i < rr; i++){
            int rrr,num;
            cin >> rrr >> num;
            for(int j = 0; j < num; j++){
                int pos;
                cin >> pos;
                G[rrr][pos] = 1;
            }
        }
        int sx,sy,ex,ey;
        cin >> sy >> sx >> ey >> ex;
        queue<point> q;
        q.push((point){sx,sy,0});
        int ans;
        while(!q.empty()){
            point p = q.front(); q.pop();
            if(vis[p.y][p.x]) continue;
            vis[p.y][p.x] = 1;
            if(p.y==ey&&p.x==ex){
                ans = p.z;
                break;
            }
            for(int i = 0; i < 4; i++){
                int yy = p.y+dy[i],xx = p.x+dx[i];
                if(yy<0||yy>=r||xx<0||xx>=c||G[yy][xx]==1||vis[yy][xx]==1) continue;
                q.push((point){xx,yy,p.z+1});
            }
        }
        cout << ans << endl;
    }
}